/*
 *  mesh.cpp
 *  asrTracer
 *
 *  Created by Petrik Clarberg on 2006-02-14.
 *  Copyright 2006 Lund University. All rights reserved.
 *
 */

#include <fstream>
#include <vector>
#include "defines.h"
#include "triangle.h"
#include "mesh.h"

using namespace std;

/**
 * Creates a mesh primitive.
 */
Mesh::Mesh() : Primitive()
{
}

/**
 * Loads a mesh from the specified file.
 * @param filename Name of the file from which to load the mesh object
 */
Mesh::Mesh(const std::string& filename, Material* m) : Primitive(m)
{
	load(filename);
}

/**
 * Loads a mesh from the specified file.
 */
void Mesh::load(const std::string& filename)
{
	cout << "loading mesh (" << filename << ")" << endl;

	// Clear out old data.
	clear();
	
	// Just call load_obj() since no other file formats are supported.
	loadOBJ(filename);
}

/**
 * Clears all data associated with the mesh.
 */
void Mesh::clear()
{
	// clear vertex attributes
	mOrigVtxP.clear();
	mOrigVtxN.clear();
	mVtxP.clear();
	mVtxN.clear();
	mVtxUV.clear();
	
	// clear faces
	mFaces.clear();
}

/**
 * Loads a mesh file in the OBJ format. 
 * Note that the various arrays (mVtxP,...) are assumed to be cleared beforehand.
 */
void Mesh::loadOBJ(const std::string& filename)
{
	// Open file
	ifstream is;
	is.open(filename.c_str(), ios_base::in);	// open in text mode
	if(!is.is_open()) throw std::runtime_error("could not open file "+filename);
	
	// Reserve size in arrays to hold the loaded data.
	// Note the std::vector arrays grows in multiples of the initial capacity,
	// hence it is important to set these to a reasonable number.
	mOrigVtxP.reserve(1000);
	mOrigVtxN.reserve(1000);
	mVtxUV.reserve(1000);
	mFaces.reserve(1000);
	
	char line[256];
	int line_num = 0;
	float a,b,c;
	bool has_normals=true, has_uv=true;

	
	//----------- reading starts here -------------
	
	// All vertex positions, normals, texture coordinates,
	// and faces are read and appended to the respective arrays.
	// Polygons with n>3 sides are triangulated on-the-fly.

	while(is.good())
	{
		is.getline(line,256);
		string s(line);
		istringstream iss(s);
		line_num++;
		
		string what;
		iss >> what;
		
		if(what=="v")			// Vertex
		{
			iss >> a >> b >> c;
			mOrigVtxP.push_back(Point3D(a,b,c));
		}
		else if(what=="vn")		// Normal
		{
			iss >> a >> b >> c;
			mOrigVtxN.push_back(Vector3D(a,b,c));
		}
		else if(what=="vt")		// Texture coordinate
		{
			iss >> a >> b;
			mVtxUV.push_back(UV(a,b));
		}
		else if(what=="f")		// Face
		{
			Triangle::vertex vtx[3];
			int n=0, k=0;
						
			while(iss.good())
			{
				// Read indices
				int pidx=0, nidx=0, tidx=0;
				
				iss >> pidx;
				if(pidx==0) break;
				
				if(iss.peek()=='/')
				{
					char ch = 0;
					iss >> ch;
					if(iss.peek()=='/')
					{
						// format: vertex//normal
						iss >> ch >> nidx;
						has_uv = false;
					}
					else
					{
						iss >> tidx;
						if(iss.peek()=='/')
						{
							// format: vertex/texture/normal
							iss >> ch >> nidx;
						}
						else
						{
							// format: vertex/texture
							has_normals = false;
						}
					}
				}
				
				// Setup vertex (the OBJ indices starts at 1, hence we subtract)
				vtx[k].p = pidx-1;
				vtx[k].n = nidx-1;
				vtx[k].t = tidx-1;
				
				if(k<2)		// first two just read and pass on
				{
					k++;
				}
				else
				{
					// one complete triangle read
					n++;
					
					// add triangle to list of triangles
					mFaces.push_back(Triangle(this,vtx[0],vtx[1],vtx[2]));
					
					// move last index to middle position to prepare for next set of indices (if any)
					vtx[1] = vtx[2];
				}
			}

			// if a face with less than 3 valid set of indices is found, we cast an exception
			if(n==0) throw std::runtime_error("error on line "+int2str(line_num));
		}
	}
	
	// ----------- reading done --------------
	
	is.close();		// close input file
		
	// debug
	int nverts = (int)mOrigVtxP.size();
//	int nnorms = (int)mVtxN.size();
//	int ntexs = (int)mVtxUV.size();
	int ntris = (int)mFaces.size();
	if(nverts==0 || ntris==0) throw std::runtime_error("invalid mesh");

//	cout << nverts << " vtx, " << nnorms << " normals, " << ntexs << " uvs, " << ntris << " tris" << endl;
	cout << ntris << " triangles" << endl;
	
	
	// All vertex attributes and triangles have been loaded.
	// Now, we need to take care of missing normals and/or texture coordinates.

	// If the normals are missing, we compute smooth normals over the
	// mesh by area-weighting the face normals (which can be found from 
	// the vertex positions). One normal per vertex position is created.

	if(!has_normals)
	{
		mOrigVtxN.clear();
		mOrigVtxN.resize(nverts);
		for(int i=0; i<ntris; i++)
		{
			Triangle& t = mFaces[i];
			Vector3D wn = t.getArea() * t.getFaceNormal();
			for(int j=0; j<3; j++)
			{
				t.mVtx[j].n = t.mVtx[j].p;
				mOrigVtxN[ t.mVtx[j].n ] += wn;
			}
		}
		for(int i=0; i<nverts; i++) mOrigVtxN[i].normalize();
	}
	
	
	// If texture coordinates are missing, we simply set each triangle's
	// vertices to have the uv-coordinates (0,0), (1,0), (0,1) respectively.

	if(!has_uv)
	{
		mVtxUV.resize(3);
		mVtxUV[0] = UV(0,0);
		mVtxUV[1] = UV(1,0);
		mVtxUV[2] = UV(0,1);
		for(int i=0; i<ntris; i++)
			for(int j=0; j<3; j++)
				mFaces[i].mVtx[j].t = j;
	}
	
	// All done!
}

/**
 * Prepares the mesh for rendering by transforming all vertex positions/normals
 * to world space.
 */
void Mesh::prepare()
{
	// Transform vertex positions.
	int npos = (int)mOrigVtxP.size();

	mVtxP.resize(npos);

	for(int i=0; i<npos; i++)
		mVtxP[i] = mWorldTransform * mOrigVtxP[i];
	
	Matrix worldInvT = mWorldTransform;
	worldInvT = worldInvT.inverse();
	worldInvT = worldInvT.transpose();

	// Transform and normalize vertex normals.
	int nnorm = (int)mOrigVtxN.size();

	mVtxN.resize(nnorm);

	for(int i=0; i<nnorm; i++)
	{
		mVtxN[i] = worldInvT * mOrigVtxN[i];
		mVtxN[i].normalize();
	}
	
	for (int i = 0; i < (int)mFaces.size(); i++)
		mFaces[i].prepare();
}

/**
 * Extract all intersectable geometry from the mesh, i.e., 
 * append a ptr to each Triangle is  to the given geometry array.
 */
void Mesh::getGeometry(std::vector<Intersectable*>& geometry)
{
	std::vector<Triangle>::iterator itr = mFaces.begin();
	for ( ; itr!=mFaces.end(); ++itr)
		geometry.push_back( &(*itr) );
	
	// Note, this is a little dangerous because we are storing pointers into 
	// a std::vector - if the vector is reallocated all pointers become invalid.
	// Hence, it's vital to re-run this function if the geometry is changed.
}

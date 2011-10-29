/*
 *  mesh.h
 *  asrTracer
 *
 *  Created by Petrik Clarberg on 2006-02-14.
 *  Copyright 2006 Lund University. All rights reserved.
 *
 */

#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
#include "triangle.h"
#include "primitive.h"

/** 
 * Class representing a triangle mesh.
 * The mesh can be loaded from an WaveFront (.obj) mesh file.
 * Internally, the mesh's vertex positions, normals, and texture
 * coordinates are stored in separate vectors. Each triangle has
 * three sets of indices into these vectors. If the normals are
 * not specified in the obj-file, these are computed by area-weighting
 * the face normals.
 */
class Mesh : public Primitive
{
public:
	Mesh();
	Mesh(const std::string& filename, Material* m=0);
	void load(const std::string& filename);

	// TEMP TEMP - Should be protected
	void getGeometry(std::vector<Intersectable*>& geometry);

protected:
	void prepare();
	void clear();
	void loadOBJ(const std::string& filename);

protected:
	std::vector<Point3D> mOrigVtxP;		///< Array of original vertex positions.
	std::vector<Vector3D> mOrigVtxN;	///< Array of original vertex normals.

	std::vector<Point3D> mVtxP;			///< Array of vertex positions.
	std::vector<Vector3D> mVtxN;		///< Array of vertex normals.
	std::vector<UV> mVtxUV;				///< Array of vertex UV coordinates.
	std::vector<Triangle> mFaces;		///< Array of triangles.
	
	friend class Triangle;				// Triangle is a friend class so it can access protected data.
};

#endif

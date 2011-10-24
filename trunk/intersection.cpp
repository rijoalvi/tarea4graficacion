#include "intersection.h"
#include "intersectable.h"


Ray Intersection::getReflectedRay() const
{
	const Vector3D& D = mRay.dir;
	Vector3D N = mNormal;





	// TODO: Implement reflection.
	// --------

	Vector3D R = D; // Resulting reflection vector
	
	// --------




    return Ray(mPosition + N*0.001f, R );
}

Ray Intersection::getRefractedRay() const
{
	const Vector3D& D = mRay.dir;
	Vector3D N = mNormal;

	float iEta = 1.0f;
	float tEta = mMaterial->getIndexOfRefraction();

	if (!mFrontFacing)
		swap(iEta, tEta); // Inside.

	float eta = iEta / tEta;

	// TODO: Implement refraction.
	// --------

	Vector3D T = D; // Resulting refraction vector

	// --------




	float mu = eta*N.dot(D) - N.dot(T);

        return Ray(mPosition - N*0.001f, T );
}

Ray Intersection::getShadowRay(PointLight *light) const
{
	// Un-normalized light vector
	Vector3D lightVec = light->getWorldPosition() - mPosition;
	
	// Length of light vector - we don't want to go beyond this in our shadow ray tests
	float len = lightVec.length();

	// Ray from hit point towards the light. Note that lightVec will be normalized by the Ray constructor
	return Ray(mPosition + mNormal * 0.001f, lightVec, 0.0f, len);
}



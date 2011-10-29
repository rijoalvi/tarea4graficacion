#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "matrix.h"
#include "ray.h"
#include "pointlight.h"

class Intersectable;
class Material;

/**
 * Class representing a ray/object intersection point. 
 * All the necessary information about the intersection is computed
 * by the intersected object and stored in this class.
 */
class Intersection
{
public:
        Ray mRay;			///< A copy of the ray causing the intersection.
	const Intersectable* mObject;	///< Pointer to the object hit by the ray.
        Material* mMaterial;		///< Pointer to the material at the hit point.
        Point3D mPosition;		///< Position of hit point in world coordinates.
        Vector3D mNormal;		///< Normal at hit point.
        bool mFrontFacing;		///< True if the hit point is the "outside" of the object
        Vector3D mView;			///< View direction at the hit point.
        float mHitTime;			///< Hit time along ray.

public:
	Intersection() : mObject(0), mMaterial(0) { }
	
	Ray getReflectedRay() const;
	Ray getRefractedRay() const;
	Ray getShadowRay(PointLight *light) const;
};

#endif

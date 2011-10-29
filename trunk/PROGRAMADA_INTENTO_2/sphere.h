#ifndef SPHERE_H
#define SPHERE_H

#include "primitive.h"
#include "intersectable.h"

/**
 * Class representing a sphere.
 * The sphere has a radius and is centered around origin by default.
 * By setting its transform, the translation/scale/orientation can
 * be changed. The ray/sphere intersection is done by transforming the
 * ray to object space, and solving the quadratic equation for the
 * sphere: x^2 + y^2 + z^2 = r^2.
 */
class Sphere : public Primitive, public Intersectable
{
public:
	Sphere();
	Sphere(float radius, Material* m=0);
	virtual ~Sphere();

	void setRadius(float r);
	
	// Implementation of the Intersectable interface.
	bool intersect(const Ray& ray) const;
	bool intersect(const Ray& ray, Intersection& isect) const;
	void getAABB(AABB& bb) const;

protected:
	void prepare();
	bool solveQuadratic(float A, float B, float C, float& t0, float& t1) const;
	
protected:
	float mRadius;					///< Radius of sphere.
	Matrix mInvWorldTransform;		///< World->Object transform.	
};

#endif

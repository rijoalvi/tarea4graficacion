#ifndef AABB_H
#define AABB_H

#include "matrix.h"

class Ray;

/**
 * Class representing an axis-aligned bounding box (AABB).
 */
class AABB
{
public:
	Point3D mMin;			///< Minimum.
	Point3D mMax;			///< Maximum.
	
public:
	AABB();
	AABB(const Point3D& p);
	AABB(const Point3D& p1, const Point3D& p2);
	AABB(const Point3D& p1, const Point3D& p2, const Point3D& p3);
	virtual ~AABB() {}

	void init(const Point3D& p);
	void include(const Point3D& p);
	void include(const AABB& b);
	void grow(float d);
	float getVolume() const;
	float getArea() const;
	int getLargestAxis() const;
	bool intersect(const Ray& r, float& tmin, float& tmax) const;
};

#endif

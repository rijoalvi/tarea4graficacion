#ifndef LISTACCELERATOR_H
#define LISTACCELERATOR_H

#include "rayaccelerator.h"

class ListAccelerator : public RayAccelerator
{
private:
	std::vector<Intersectable*> objects;

public:
	virtual void build(const std::vector<Intersectable*>& objects);
	virtual bool intersect(const Ray& ray);
	virtual bool intersect(const Ray& ray, Intersection& is);
};

#endif

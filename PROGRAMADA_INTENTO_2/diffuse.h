#ifndef DIFFUSE_H
#define DIFFUSE_H

#include "material.h"

/**
 * Simple diffuse (Lambertian) material.
 * Only the normal and light vector are used in the evaluation
 * of the BRDF, hence the viewing direction does not matter.
 */
class Diffuse : public Material
{
public:
	Diffuse(const Color& c, float r=0.0f, float t=0.0f, float n=1.0f);
	Color evalBRDF(const Intersection& is, const Vector3D& L);

protected:
	Color mDiffColor;		///< The diffuse color.
};

#endif

#include "defines.h"
#include "scene.h"
#include "camera.h"
#include "ray.h"
#include "intersection.h"
#include "material.h"
#include "whittedtracer.h"
#include "timer.h"
#include "image.h"

/**
 * Creates a Whitted raytracer. The parameters are passed on to the base class constructor.
 */
WhittedTracer::WhittedTracer(Scene* scene, Image* img) : Raytracer(scene,img)
{
}


WhittedTracer::~WhittedTracer()
{
}

/**
 * Raytraces the scene by calling tracePixel() for each pixel in the output image.
 * The function tracePixel() is responsible for computing the output color of the
 * pixel. This should be done in a sub class derived from the Raytracer base class.
 */
void WhittedTracer::computeImage()
{
	std::cout << "Raytracing..." << std::endl;
	Timer timer;
	
	Color c;
	int width = mImage->getWidth();
	int height = mImage->getHeight();
	
	// Loop over all pixels in the image
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			// Raytrace the pixel at (x,y).
			c = tracePixel(x,y);
			
			// Store the result in the image.
			mImage->setPixel(x,y,c);
		}
		
		// Print progress approximately every 5%.
		if ((y+1) % (height/20) == 0 || (y+1) == height)
			std::cout << (100*(y+1)/height) << "% done" << std::endl;
	}
	
	std::cout << "Done in " << timer.stop() << " seconds" << std::endl;
}

/**
 * Compute the color of the pixel at (x,y) by raytracing. 
 * The default implementation here just traces through the center of
 * the pixel.
 */
Color WhittedTracer::tracePixel(int x, int y)
{
	Color pixelColor = Color(0.0f, 0.0f, 0.0f);

	float cx = (float)x + 0.5f;
	float cy = (float)y + 0.5f;
	
	// Let the camera setup the ray.
	Ray ray = mCamera->getRay(cx,cy);
	
	return trace(ray, 0);
}

/**
 * Computes the radiance returned by tracing the ray r.
 */
Color WhittedTracer::trace(const Ray& ray, int depth)
{
	if (mScene->intersect(ray))
		return Color(1,1,1);
	else 
		return Color(0,0,0);
}


#include "defines.h"
#include "image.h"

/// This string is stored as a comment in exr files written by this class.
static const char EXR_OUTPUT_COMMENT[] = "PR Raytracer";

/**
 * Default constructor. Creates an uninitialized image.
 */
Image::Image() : mPixels(0), mWidth(0), mHeight(0)
{
}

/**
 * Creates an image buffer of the specified size.
 * \param width Width in pixels
 * \param height Height in pixels
 */
Image::Image(int width, int height) : mWidth(width), mHeight(height), mPixels(new Color[width*height])
{
	std::cout << "creating image (" << mWidth << "x" << height << ")" << std::endl;
	
	if (width <= 0 || height <= 0)
		throw std::runtime_error("(Image::Image) image dimensions must be larger than 0");
}

/**
 * Destroys the object.
 */
Image::~Image()
{
	if (mPixels)
		delete [] mPixels;
}

/**
 * Loads an image from a file.
 * Currently, OpenEXR (.exr) is the only supported format.
 */
void Image::load(const std::string& filename)
{
}

//inline float correct(float x){ return (powf(x,1.66f)) * 255.0f * powf(10.0f, 1.66f); }

/**
 * Writes the image to a file.
 * The file format is chosen based on the file ending, but currently
 * only OpenEXR (.exr) high-dynamic range images are supported.
 * \param filename Filename to store the image in
 */
void Image::save(const std::string& filename) const
{
}

/**
 * Sets the pixel at (x,y) to color c.
 */
void Image::setPixel(int x, int y, const Color& c)
{
	if (x < 0 || x >= mWidth || y < 0 || y >= mHeight) 
		throw std::runtime_error("(Image::setPixel) pixel coordinate outside image");
	
	mPixels[y*mWidth + x] = c;
}

/**
 * Returns the pixel value at (x,y) in the reference c.
 * Note that the range of the parameters is not checked.
 */
void Image::getPixel(int x, int y, Color& c) const
{
	c = mPixels[y*mWidth + x];
}

/**
 * Returns the pixel at (x,y).
 * Note that the range of the parameters is not checked.
 */
Color Image::getPixel(int x, int y) const
{
	return mPixels[y*mWidth + x];
}

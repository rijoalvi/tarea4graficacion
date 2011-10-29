#include "defines.h"
#include "ray.h"
#include "image.h"
#include "camera.h"

using namespace std;

/** Default constructor. The image buffer must be given as an argument, 
*	so the camera can extract the image dimensions automatically.
*/
Camera::Camera(Image* img) : Node(), mImage(img)
{
	if (!mImage)
		throw std::runtime_error("(Camera::Camera) image null pointer");

	std::cout << "creating camera" << std::endl;
}

/**
 * Destructor. Does nothing.
 */
Camera::~Camera()
{
}

/**
 * Setup the camera frame by specifying the camera's position, target, and up vector.
 */
void Camera::setLookAt(const Point3D& pos, const Point3D& target, const Vector3D& up, float fov, float near, float far)
{
	// Set camera origin, near/far plane.
	mOrigin = pos;
	mNearPlane = near;
	mFarPlane = far;
	
	// Setup orthogonal camera frame defined by right,forward,up vectors.
	mForward = target - pos;
	mForward.normalize();
	mRight = mForward % up;
	mRight.normalize();
	mUp = mRight % mForward;
	
//Calculo de St y Sk
	St = std::tan((float)((fov/2) * M_PI/180));
	Sk = std::tan((float)((fov/2)/(mImage->getWidth()/(mImage->getHeight()) * M_PI/180));
}

/**
 * Returns a ray that goes through image plane location (x,y),
 * where the coordinate is given in terms of image pixel dimensions.
 */
Ray Camera::getRay(float x, float y) const
{

//FALTA ESTO

}

/**
 * Prepare the camera for use in raytracing by transforming its frame to world coordinates.
 */
void Camera::prepare()
{
	// Transform coordinate origin and frame to world space.
	mOrigin = mWorldTransform * mOrigin;
	mForward = mWorldTransform * mForward;
	mRight = mWorldTransform * mRight;
	mUp = mWorldTransform * mUp;
}

#ifndef CAMERA_H
#define CAMERA_H

#include "node.h"

class Image;	
class Ray;

/**
 * Class representing a simple perspective camera. 
 * The camera needs to know which Image object is used for the 
 * output image in order to extract the image dimensions.
 * The camera can be conveniently setup using the setLookAt()
 * function, which takes a position, target and up vector.
 * The field of view parameter measures the FOV in degrees
 * horizontally.
 */
class Camera : public Node
{
public:
	Camera(Image* img);
	virtual ~Camera();
	
	void setLookAt(const Point3D& pos, const Point3D& target, const Vector3D& up, float fov, float near=1.0f, float far=1000.0f);
	virtual Ray getRay(float x, float y) const;
	
protected:
	void prepare();
	
protected:
	Image* mImage;				///< Ptr to the output image.
	Point3D mOrigin;				///< Position of camera origin.
	Vector3D mForward;			///< Camera frame forward vector.
	Vector3D mRight;				///< Camera frame right vector.
	Vector3D mUp;					///< Camera frame up vector.
	float mNearPlane;			///< Distance to near viewing plane.
	float mFarPlane;			///< Distance to far viewing plane.
};

#endif

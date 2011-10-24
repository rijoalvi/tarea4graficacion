#include "defines.h"
#include "intersectable.h"
#include "camera.h"
#include "scene.h"

/**
 * Initializes an empty scene.
 */
Scene::Scene(RayAccelerator* accelerator) : mRoot(new Node()), mBackgroundProbe(0)
{
	mAccelerator = accelerator;
	std::cout << "creating scene" << std::endl;
	mBackgroundColor = Color(0.0f, 0.0f, 0.0f);
}

/**
 * Destroys the scene and all its nodes.
 */
Scene::~Scene()
{
	if (mRoot)
		delete mRoot; // Recursively deletes all children nodes.
}

/**
 * Adds a node to the scene hierarchy. 
 * @param node Ptr to the node to add
 * @param parent Ptr to the parent node, or 0 at top level.
 */
void Scene::add(Node* node, Node* parent)
{
	if (node == 0)
		throw std::runtime_error("(Scene::add) node is null pointer");
	else if (mRoot->hasChild(node))
		throw std::runtime_error("(Scene::add) node is already in the scene hierarchy");

	if (parent == 0)
		parent = mRoot; // Root is parent.
	else if (!mRoot->hasChild(parent))
		throw std::runtime_error("(Scene::add) parent node is not in the scene hierarchy");

	parent->addChild(node);
}

/**
 * Prepare scene for raytracing. This function must be called
 * before any raytracing operations can be performed.
 *
 * The nodes' transforms are propagated down the hierarchy,
 * an acceleration structure is setup, etc.
 */
void Scene::prepare()
{
	std::cout << "preparing scene..." << std::endl;

	// Recursively setup transform matrices.
	setupTransform(mRoot, Matrix());

	// Recursively call prepare() function on all nodes.
	prepareNode(mRoot);

	// Extract scene data that will be needed during renderng.
	mCameras.clear();

	std::vector<Intersectable*> geometry;
	geometry.reserve(1000);
	extractData(mRoot, geometry);
	
	// Build accelerator.
	mAccelerator->build(geometry);
}

/**
 * Sets the background color to c. The background is only used
 * if no light probe is setup.
 */
void Scene::setBackground(const Color& c)
{
	mBackgroundColor = c;
}

/**
 * Sets the current light probe to use for the background to lp.
 * If lp is 0, then a uniform background color is used instead.
 */
void Scene::setBackground(LightProbe* lp)
{
	mBackgroundProbe = lp;
}

/**
 * Returns the background color in direction d.
 * If a light probe is setup, the color is taken from the probe,
 * otherwise a uniform background color is used.
 */
Color Scene::getBackground(const Vector3D& d) const
{
    /* TODO : REturn Backgrund color */
    return(Color(0,0,0));
}

/**
 * Recursively set the transform matrix of the node and its children.
 * At each step the matrix is multiplied by the node's local matrix.
 */
void Scene::setupTransform(Node* node, const Matrix& parent)
{
	node->setupTransform(parent);	
	Node::t_itr itr = node->mChildren.begin();
	for( ; itr!=node->mChildren.end(); ++itr)
		setupTransform(*itr, node->mWorldTransform);
}

/**
 * Call the prepare() functioin on the node and all of its children.
 */
void Scene::prepareNode(Node* node)
{
	// Call prepare on the node and on all its children.
	node->prepare();
	Node::t_itr itr = node->mChildren.begin();
	for( ; itr!=node->mChildren.end(); ++itr)
		prepareNode(*itr);
}

/**
 * Recursively traverse node hierarchy and store pointers to relevant
 * objects we will need during rendering. This includes building lists
 * of all cameras and lights in the scene, as well as extracting all
 * intersectable geometry from the scene.
 */
void Scene::extractData(Node* node, std::vector<Intersectable*>& geometry)
{
	// Extract intersectable geometry.
	node->getGeometry(geometry);

	// Check if the node is a camera or a point light, and if so,
	// store a pointer to it in the corresponding list.
	Camera* cam = dynamic_cast<Camera*>(node);
	if (cam)
		mCameras.push_back(cam);
	
	PointLight* pl = dynamic_cast<PointLight*>(node);
	if (pl)
		mPLights.push_back(pl);

	// Recurse into children nodes.
	Node::t_itr itr = node->mChildren.begin();
	for( ; itr!=node->mChildren.end(); ++itr)
		extractData(*itr, geometry);
}

/**
 * Returns true if the given ray intersects the scene.
 * However, no info about the hit point is returned.
 */
bool Scene::intersect(const Ray& ray)
{
	return mAccelerator->intersect(ray);
}

/**
 * Returns true if the given ray intersects the scene.
 * Info about the closest hit is returned in the Intersection object.
 */
bool Scene::intersect(const Ray& ray, Intersection& is)
{
	return mAccelerator->intersect(ray, is);
}

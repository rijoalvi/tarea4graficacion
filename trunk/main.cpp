#include "matrix.h"
#include "color.h"
#include "aabb.h"
#include "camera.h"
#include "defines.h"
#include "diffuse.h"
#include "image.h"
#include "intersectable.h"
#include "intersection.h"
#include "listaccelerator.h"
#include "material.h"
#include "mesh.h"
#include "node.h"
#include "pointlight.h"
#include "primitive.h"
#include "ray.h"
#include "rayaccelerator.h"
#include "raytracer.h"
#include "scene.h"
#include "sphere.h"
#include "timer.h"
#include "triangle.h"
#include "whittedtracer.h"

#include <QApplication>
#include "ventana.h"
int main(int argc, char *argv[]) {
    initializeGL();
    QApplication app(argc, argv);
    Ventana ventana;
    ventana.show();
    return app.exec();
}

void VisorOpenGL::initializeGL() {
    glClearColor(1.0,1.0,1.0,1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}


#include "paneldibujo.h"
#include <cmath>

PanelDibujo::PanelDibujo(QWidget *parent) :QGLWidget(parent)
{
    sides = 3;
    radius = 1.0;
}

void PanelDibujo::initializeGL(){
    glShadeModel(GL_SMOOTH);
    glClearColor(0, 0, 0, 0);
    //glClearDepth(1.0f);
    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void PanelDibujo::resizeGL(int width, int height){
    double xMin = 0, xMax = 10, yMin = 0, yMax = 10;
    glViewport(0,0,(GLint)width, (GLint)height);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    //***Now we move on to 3D space we need to change our viewing
    //***space to be one that uses perspective to view the
    //***scene/object. You can use either glFrustum() or
    //***gluPerpective. USe whichever one makes sens to you. We will
    //***go over this in lab for more details.
    glFrustum( -1.0, 1.0, -1.0, 1.0, 5.0, 15.0 );
    //glOrtho( -1.0, 1.0, -1.0, 1.0, 5.0, 15.0 );
    //gluPerspective( 90.0, 1.0, 0.1, 20.0 );
    glMatrixMode( GL_MODELVIEW );
}

void PanelDibujo::paintGL(){
    //***You want to start with a clean sheet, so we make sure that
    //***there are no other (unwanted) objects that will be drawn. This
    //***is achieved by clearing the the colour buffer.


    //***Here is a new buffer you have to clear. The depth buffer is
    //***required for doing 3D models. This enables drawing in the
    //***correct order so that polygons/objects/etc closer to the
    //***eye/screen are drawn on top of the things in the distance.
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //***Once you have cleared the depth buffer you have to enable the
    //***depth test for working in a 3D environment.
    glEnable(GL_DEPTH_TEST);
    //*** This clears the matrix on the stack.
    //*** The top matrix will be the identity matrix.
    glLoadIdentity();
//---------------------------------------------------------------------CAMARA!!!!!-------------------------
    //***gluLookAt() positions the camera where it should be and points
    //***it in the direction you wish it to point. More in labs (or in
    //***the documentation.
    gluLookAt(5.0, 9.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

//---------------------------------------------------------------------CAMARA!!!!!-------------------------

    //*** you can scale the object - see lab exercises
    glScalef( 1, 1, 1 );

    //***These translation controls let you move the view of the object
    //*** left and right (x-direction) and up and down (y-diresction).
    //*** The xTrans is negated for a reason, can you tell what that is?
    glTranslatef( /*-xTrans*/0.0, 0.0, 0.0 );
    glTranslatef( 0.0, /*yTrans*/0.0, 0.0 );
    glTranslatef( 0.0, 0.0, /*zTrans*/0.0 );

    //***These are the controls that are used by the sliders and mouse
    //*** for rotation use your own values for xRot/yRot/zRot to see
    //*** the effects.
    glRotatef( /*xRot*/0.0, 1.0, 0.0, 0.0 );
    glRotatef( /*yRot*/0.0, 0.0, 1.0, 0.0 );
    glRotatef( /*zRot*/0.0, 0.0, 0.0, 1.0 );

    //This is where the object is defined and drawn.

    //***First you need to specify which colour you wish to use.
    //*** The colours are specified by their RGB triplets.
    glColor3f( 1.0, 1.0, 1.0 );
    //***Try changing the values of the colour triple (red, green, blue)
    //***Try copying the colour line and puting different colours beside
    //*** each vertex

    glBegin( GL_QUAD_STRIP);

    glColor3f( 0.0, 1.0, 1.0 );
    glVertex3f( 0.0, 0.0, 0.0 ); //V0
    glVertex3f( 0.0, 1.0, 0.0 ); //V1
    glVertex3f( 1.0, 0.0, 0.0 ); //V2
    glVertex3f( 1.0, 1.0, 0.0 ); //V3

    glColor3f( 1.0, 0.0, 1.0 );
    glVertex3f( 1.0, 0.0, 0.0 ); //V2
    glVertex3f( 1.0, 1.0, 0.0 ); //V3
    glVertex3f( 1.0, 0.0, 1.0 ); //V4
    glVertex3f( 1.0, 1.0, 1.0 ); //V5

    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f( 1.0, 0.0, 1.0 ); //V4
    glVertex3f( 1.0, 1.0, 1.0 ); //V5
    glVertex3f( 0.0, 0.0, 1.0 ); //V6
    glVertex3f( 0.0, 1.0, 1.0 ); //V7

    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( 0.0, 0.0, 1.0 ); //V6
    glVertex3f( 0.0, 1.0, 1.0 ); //V7
    glVertex3f( 0.0, 0.0, 0.0 ); //V0
    glVertex3f( 0.0, 1.0, 0.0 ); //V1
    glEnd();

    glBegin(GL_QUADS);
    glColor3f( 0.0, 1.0, 0.0 );
    glVertex3f( 0.0, 1.0, 0.0 ); //V1
    glVertex3f( 0.0, 1.0, 1.0 ); //V7
    glVertex3f( 1.0, 1.0, 1.0 ); //V5
    glVertex3f( 1.0, 1.0, 0.0 ); //V3
    glEnd();

    glBegin(GL_QUADS);
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( 0.0, 0.0, 0.0 ); //V0
    glVertex3f( 1.0, 0.0, 0.0 ); //V2
    glVertex3f( 1.0, 0.0, 1.0 ); //V4
    glVertex3f( 0.0, 0.0, 1.0 ); //V6
    glEnd();
}
void PanelDibujo::changeSides(int s){}
void PanelDibujo::changeRadius(double r){}

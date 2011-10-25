#include "escena.h"

escena::escena()
{
}

void Escena::draw(){

    ejes.draw();
    glColor3f(0.0,0.0,0.0);
    glPointSize(4);

    switch (Draw_type){
        case GL_POINTS:
            glBegin(GL_POINTS);
            break;
        case GL_LINES:
            glBegin(GL_LINES);
            break;
        case GL_LINE_STRIP: glBegin(GL_LINE_STRIP);
            break;
        case GL_LINE_LOOP: glBegin(GL_LINE_LOOP);
            break;
        case GL_POLYGON:
            glBegin(GL_POLYGON);
            break;
        case GL_QUADS:
            glBegin(GL_QUADS);
            break;
        case GL_QUAD_STRIP: glBegin(GL_QUAD_STRIP);
            break;
        case GL_TRIANGLES: glBegin(GL_TRIANGLES);
            break;
        case GL_TRIANGLE_STRIP: glBegin(GL_TRIANGLE_STRIP);
            break;
        case GL_TRIANGLE_FAN:
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0,0,0);
            break;
    }

    for (int i=0;i<8;i++){
        glVertex3fv((GLfloat *) &vertices[i]);
    }

    glEnd();
}

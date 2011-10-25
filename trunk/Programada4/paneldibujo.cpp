#include "paneldibujo.h"
#include <cmath>

PanelDibujo::PanelDibujo(QWidget *parent) :
    QGLWidget(parent)
{
    sides = 3;
    radius = 1.0;
}

void PanelDibujo::initializeGL(){}
void PanelDibujo::resizeGL(int x, int h){}
void PanelDibujo::paintGL(){}
void PanelDibujo::changeSides(int s){}
void PanelDibujo::changeRadius(double r){}

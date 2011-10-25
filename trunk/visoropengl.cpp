#include "visoropengl.h"
VisorOpenGL::VisorOpenGL(QWidget *parent): QGLWidget(parent) {
    // Inicializamos los ángulos de rotación
    observer_angle_x = 0;
    observer_angle_y = 0;
    observer_angle_z = 0;
    // Definimos el tamaño del volumen de visualización
    Window_width=5;
    Window_height=5;
    Front_plane=10;
    Back_plane=1000;
    // se inicia la posicion del observador, en el eje z
    Observer_distance=2*Front_plane;
    // permitimos al componente tener el foco y aceptar eventos
    setFocusPolicy(Qt::StrongFocus);
}

VisorOpenGL::~VisorOpenGL() {
    makeCurrent();
}

QSize VisorOpenGL::minimumSizeHint() const {
    return QSize(50, 50);
}
QSize VisorOpenGL::sizeHint() const {
    return QSize(400, 400);
}
//El visor proporciona tres slots que permiten a otros componentes cambiar la orientación de la escena:
void VisorOpenGL::setXRotation(int angle) {
    normalizeAngle(&angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}


#include <QtGui>
#include "visoropengl.h"
#include "ventana.h"
Ventana::Ventana() {
    visorOpenGL = new VisorOpenGL;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(visorOpenGL);
    setLayout(mainLayout);
    setVentanaTitle(tr("Tarea Programada 4"));

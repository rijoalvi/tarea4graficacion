#ifndef VENTANA_H
#define VENTANA_H
#include <QWidget>
#include "visoropengl.h"
class Ventana : public QWidget {
    Q_OBJECT
public:
    Ventana();
private:
    VisorOpenGL *visorOpenGL;
};
#endif

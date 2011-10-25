#ifndef PANELDIBUJO_H
#define PANELDIBUJO_H

#include <QGLWidget>

class PanelDibujo : public QGLWidget
{
    Q_OBJECT
public:
    explicit PanelDibujo(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    int sides;
    double radius;

signals:

public slots:
    void changeSides(int s);
    void changeRadius(double r);

};

#endif // PANELDIBUJO_H

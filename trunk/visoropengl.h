#ifndef VISOROPENGL
#define VISOROPENGL
#include <QGLWidget>
#include <QEvent>
#include <QMouseEvent>
#include "escena.h"


class VisorOpenGL: public QGLWidget {
	Q_OBJECT

	public:
		VisorOpenGL(QWidget *parent = 0);
		~VisorOpenGL();
		QSize minimumSizeHint() const;
		QSize sizeHint() const;

	public slots:
		void setXRotation(float angle);
		void setYRotation(float angle);
		void setZRotation(int angle);

	signals:
		void xRotationChanged(float angle);
		void yRotationChanged(float angle);
		void zRotationChanged(int angle);

	protected:
		void initializeGL();
		void paintGL();
		void resizeGL(int width, int height);

		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void keyPressEvent(QKeyEvent *event);

		void setObserver();
		void setProjection();
		void dibujarEscena();

	private:
		QPoint lastPos;

		Escena escena;
		GLint Draw_type;

		int Window_width;
		int Window_height;
		int Front_plane;
		int Back_plane;

		float Observer_distance;
		float observer_angle_x;
		float observer_angle_y;
		float observer_angle_z;

		void normalizeAngle(float angle);
};
#endif


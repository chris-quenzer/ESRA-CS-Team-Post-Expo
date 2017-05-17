#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLWidget>
#include "gl/GLU.h"
#include <QTimer>
#include <QTime>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent) : QOpenGLWidget(parent)
    {
        connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
        timer.start(16);

        time.start();
    }

    double nav_rot_x = 0.0;
    double nav_rot_y = 0.0;
    double nav_rot_z = 0.0;

    bool demo = false;

    float Rand_f(float low, float high);
    int Rand_i(int ilow, int ihigh);

private:
    QTimer timer;
    QTime time;

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
};

#endif // GLWIDGET_H

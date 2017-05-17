#include "glwidget.h"
#include "loadobjfile.cpp"
#include "BmpToTexture.cpp"
#include <QFile>
#include <QDir>

#define _USE_MATH_DEFINES
#include <math.h>

GLuint tex;
GLuint navball, crosshairs;

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1,1,1,1); //white
    //glClearColor(.2,.2,.2,1); //grey
    //glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_COLOR_MATERIAL);

    QString navball_path = QDir::temp().absoluteFilePath("navball.obj");
    QFile::copy(":Resources/models/navball.obj", navball_path);

    QString crosshairs_path = QDir::temp().absoluteFilePath("crosshairs.obj");
    QFile::copy(":Resources/models/crosshairs.obj", crosshairs_path);

    QString navTex_path = QDir::temp().absoluteFilePath("navball.bmp");
    QFile::copy(":Resources/textures/navball.bmp", navTex_path);

    // Put navball in list ---------------------------
    navball = glGenLists(1);
        glNewList(navball, GL_COMPILE);
        LoadObjFile((char *)navball_path.toStdString().c_str());
        glEndList();
    //------------------------------------------------
    // Put crosshairs in list ------------------------
    crosshairs = glGenLists(1);
        glNewList(crosshairs, GL_COMPILE);
        LoadObjFile((char *)crosshairs_path.toStdString().c_str());
        glEndList();
    //------------------------------------------------

    //use BmpToTexture()
    int width = 1024, height = 512;

    unsigned char *Texture = BmpToTexture((char *)navTex_path.toStdString().c_str(), &width, &height);
    int level = 0, ncomps = 3, border = 0;

    //set texture object
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &tex); // assign binding “handles”
    glBindTexture(GL_TEXTURE_2D, tex); // make tex0 texture current
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexImage2D(GL_TEXTURE_2D, level, ncomps, width, height, border, GL_RGB, GL_UNSIGNED_BYTE, Texture);


}

void GLWidget::paintGL()
{
    glDrawBuffer( GL_BACK );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // CROSSHAIRS -------------------------------------
    glPushMatrix();
    glColor3f(1,0.7,0);
    glTranslatef(0,-1,0);
    glRotatef(-90, 1,0,0); // initial rotation
    glCallList(crosshairs);
    glPopMatrix();

    // NAVBALL
    glPushMatrix();
    glTranslatef(0,-1,0);
    if(demo)
    {
        glRotatef(10 * sin(2 * M_PI * time.elapsed()/1000), 1,1,0); // oscillating
    }
    glRotatef(nav_rot_x, 1,0,0); // X Rotation
    glRotatef(nav_rot_y, 0,1,0); // Y Rotation
    glRotatef(nav_rot_z, 0,0,1); // Z Rotation
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    glCallList(navball);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glFlush( );
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glOrtho( -3., 3.,     -3., 3.,     0.01, 1000. );
    gluPerspective( 30., (float)w/h, 0.01, 1000. );
    gluLookAt(0.,3.,0.,     0.,0.,0.,      0.,0.,-1.);

    //update();
}

float
GLWidget::Rand_f(float low, float high)
{
    long random();		// returns integer 0 - TOP
    float r;		// random number

    r = (float)rand();

    return(low + r * (high - low) / (float)RAND_MAX);
}


int
GLWidget::Rand_i(int ilow, int ihigh)
{
    float low = (float)ilow;
    float high = ceil((float)ihigh);

    return (int)Rand_f(low, high);
}

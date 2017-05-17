#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Graphs g;
    w.show();
    //g.show();

    return a.exec();
}

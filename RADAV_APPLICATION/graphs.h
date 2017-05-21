#ifndef GRAPHS_H
#define GRAPHS_H

#include <QDialog>
#include "dataprocessing.h"
#include "mainwindow.h"
#include <QTimer>
#include <QTime>

namespace Ui {
class Graphs;
}

class Graphs : public QDialog
{
    Q_OBJECT

public:    
    void timerSetup();

    //Add graph setup functions here:
    void makeLongPlot(QCustomPlot *&gyroLong);
    void makeCurrentPlot(QCustomPlot *&gyroCurrent);
    void makeAltitudePlot(QCustomPlot *&altitude);
    void makeVelocityPlot(QCustomPlot *&velocity, bool historic);
    void addHistoricVelocity(QCustomPlot*&velocity);
    double plotNextVelocity(int key, QCustomPlot *&velocity, DataProcessing &, double, bool, double velocityValue);
    double plotNextAltitude(int key, QCustomPlot *&altitude, DataProcessing &, struct baseAltitudeInfo altInfo, double alt);


    void makeTable();
    void cellSelected(int nRow, int nCol);

    static double gyro_x;
    static double gyro_y;
    static double gyro_z;
    //bool first_time = true;           //Removed on 3/13/17 and moved to graphs.cpp

    static int m_dataSource;

    //DataProcessing plottingGW;

    explicit Graphs(QWidget *parent = 0);
    ~Graphs();

private slots:

private:

};

#endif // GRAPHS_H

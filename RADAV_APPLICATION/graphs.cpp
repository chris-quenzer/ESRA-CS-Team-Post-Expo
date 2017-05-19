#include "graphs.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "dataprocessing.h"

#include <QtSerialPort/QSerialPort>

DataProcessing MainWindow::plotting;

bool first_time = true;
bool first_historic = true;


Graphs::Graphs(QWidget *parent) :
    QDialog(parent)
{

}

Graphs::~Graphs()
{

}

/***********************************************************************
 * Gets data from the main window from the sensor data struct
 * sends it to the data processing object
 *
 *
 * *********************************************************************/

void Graphs::makeLongPlot(QCustomPlot *&gyroLong)
{
    gyroLong->addGraph(); // blue line
    gyroLong->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    gyroLong->addGraph(); // red line
    gyroLong->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    gyroLong->addGraph(); // green line
    gyroLong->graph(2)->setPen(QPen(QColor(0, 145, 10)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    gyroLong->xAxis->setTicker(timeTicker);
    gyroLong->axisRect()->setupFullAxesBox();
    gyroLong->yAxis->setRange(-200, 300);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(gyroLong->xAxis, SIGNAL(rangeChanged(QCPRange)), gyroLong->xAxis2, SLOT(setRange(QCPRange)));
    connect(gyroLong->yAxis, SIGNAL(rangeChanged(QCPRange)), gyroLong->yAxis2, SLOT(setRange(QCPRange)));

    gyroLong->xAxis->setLabel("Time (s)");
    gyroLong->yAxis->setLabel("Gyro position (Degrees)");

}


void Graphs::makeCurrentPlot(QCustomPlot *&gyroCurrent)
{
    //Graph 2
    gyroCurrent->addGraph(); // blue line
    gyroCurrent->graph(0)->setPen(QPen((QColor(40, 110, 255)), 1.0, Qt::DotLine));

    gyroCurrent->addGraph(); // red line
    gyroCurrent->graph(1)->setPen(QPen((QColor(255, 110, 40)), 2.0, Qt::SolidLine));

    gyroCurrent->addGraph(); // gray line
    gyroCurrent->graph(2)->setPen(QPen((QColor(110, 110, 110)), 2.0, Qt::SolidLine));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    gyroCurrent->xAxis->setTicker(timeTicker);
    gyroCurrent->axisRect()->setupFullAxesBox();
    gyroCurrent->yAxis->setRange(-200, 300);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(gyroCurrent->xAxis, SIGNAL(rangeChanged(QCPRange)), gyroCurrent->xAxis2, SLOT(setRange(QCPRange)));
    connect(gyroCurrent->yAxis, SIGNAL(rangeChanged(QCPRange)), gyroCurrent->yAxis2, SLOT(setRange(QCPRange)));

}


/******************************************************
 * Function: MakeAltitudePlot
 * Description: Plots altitude from both the GPS and altimiter
 *
 * ****************************************************/
void Graphs::makeAltitudePlot(QCustomPlot *&altitude)
{
    altitude->addGraph(); // blue line altimiter
    altitude->graph(0)->setName("Altimiter");
    altitude->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    altitude->addGraph(); // red line gps altitude data
    altitude->graph(1)->setName("GPS Altimiter");
    altitude->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    altitude->addGraph(); // grey line difference between each source of altimiter info
    altitude->graph(2)->setName("Difference");
    altitude->graph(2)->setPen(QPen((QColor(128, 128, 128)), 1.0, Qt::DotLine));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    altitude->xAxis->setTicker(timeTicker);
    altitude->axisRect()->setupFullAxesBox();
    altitude->yAxis->setRange(0, 300);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(altitude->xAxis, SIGNAL(rangeChanged(QCPRange)), altitude->xAxis2, SLOT(setRange(QCPRange)));
    connect(altitude->yAxis, SIGNAL(rangeChanged(QCPRange)), altitude->yAxis2, SLOT(setRange(QCPRange)));

    altitude->xAxis->setLabel("Time (s)");
    altitude->yAxis->setLabel("Altitude (Ft)");

    altitude->graph(0)->addToLegend();
    altitude->graph(1)->addToLegend();
    altitude->graph(2)->addToLegend();
    //altitude->legend->setVisible(true);

}

/******************************************************
 * Function: MakeVelocityPlot
 * Description: Plots velocity using position data
 *
 * ****************************************************/
void Graphs::makeVelocityPlot(QCustomPlot *&velocity, bool historic)
{
    if(first_time)
    {
        velocity->addGraph(); // blue line velocity
        velocity->graph(0)->setPen(QPen(QColor(40, 110, 255)));
        velocity->graph(0)->addToLegend();
        first_time = false;
    }

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    velocity->xAxis->setTicker(timeTicker);
    velocity->axisRect()->setupFullAxesBox();
    velocity->yAxis->setRange(-100, 100);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(velocity->xAxis, SIGNAL(rangeChanged(QCPRange)), velocity->xAxis2, SLOT(setRange(QCPRange)));
    connect(velocity->yAxis, SIGNAL(rangeChanged(QCPRange)), velocity->yAxis2, SLOT(setRange(QCPRange)));

    velocity->xAxis->setLabel("Time (s)");
    velocity->yAxis->setLabel("Velocity (Ft/s)");

    if(historic && first_historic)
    {
        velocity->addGraph(); // grey dotted line for historic velocity
        velocity->graph(1)->setPen(QPen((QColor(128, 128, 128)), 1.0, Qt::DotLine));

        velocity->graph(0)->setName("Current Velocity");
        velocity->graph(1)->setName("Velocity From Previous Flight");


        velocity->graph(1)->addToLegend();
        velocity->legend->setVisible(true);
        first_historic = false;
    }
}

/***********************************************************************************
 * Function: plotNextAltitude
 * Description: gets attribute from specified source plots it onto graph using a key
 * Input: key, pointer reference to the Qcustomplot its plotting to and a
 * dataprocessing object to determine the source to get data from
 * Output: Qcustomplot with a new data point on the graph
 *
 * ********************************************************************************/
double Graphs::plotNextAltitude(int key, QCustomPlot *&altitude, DataProcessing &plotting, struct baseAltitudeInfo altInfo, double alt)
{
    // add data to lines:
   //double alt = plotting.getNextAltitude(plotting.source, ALTITUDE, altInfo);//plotting.getAttributeFromSource(plotting.source, ALTITUDE, 1);
   //double altGps = plotting.getNextAltitude(plotting.source, ALTITUDE_GPS, altInfo);//plotting.getAttributeFromSource(plotting.source, ALTITUDE_GPS, 1);
   qDebug() << "ALT GPS " << alt << endl;
   //double altDiff = fabs(alt) - fabs(altGps);

  altitude->graph(0)->addData(key, alt);
  //altitude->graph(1)->addData(key, altGps);
  //altitude->graph(2)->addData(key, altDiff);

  //rescale value (vertical) axis to fit the current data:
  altitude->graph(0)->rescaleValueAxis(true);
  //altitude->graph(1)->rescaleValueAxis(true);

  return alt;
}


/*********************************************************************************
 * Function: plotNextVelocity
 * Description: gets attribute from specified source plots it onto graph using a key
 * Input: key, pointer reference to the Qcustomplot its plotting to and a
 * dataprocessing object to determine the source to get data from, also a bool value to determine
 * whether or not to add another line for historic data
 * Output: Qcustomplot with a new data point on the graph
 *
 * *******************************************************************************/
double Graphs::plotNextVelocity(int key, QCustomPlot *&velocity, DataProcessing &plotting, double time, bool historic, double velocityValue)
{
    //double velocityValue = plotting.getNextVelocity(plotting.source, time);

    qDebug() << "VELOCITY VALUE " << velocityValue << endl;
    if(velocityValue != nan(""))
    {
        velocity->graph(0)->addData(key, velocityValue); //Position Data

        //rescale value (vertical) axis to fit the current data:
        velocity->graph(0)->rescaleValueAxis(true);

        if(historic)
        {
            //double velocityValue = plotting.getNextVelocity(FFILE, time);
            velocity->graph(1)->addData(key, velocityValue); //Position Data

            //rescale value (vertical) axis to fit the current data:
            velocity->graph(1)->rescaleValueAxis(true);
        }
    }
    return velocityValue;
}

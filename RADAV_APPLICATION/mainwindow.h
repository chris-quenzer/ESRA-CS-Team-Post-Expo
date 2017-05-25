/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QRegExp>  //Added for parsing 2/14/17 Alex Wood
#include <QTime>    //Added for delay function 2/18/17 Alex Wood
#include <QCoreApplication> //Added for delay function 2/18/17 Alex Wood
#include <QtEndian>

#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlContext>


//#include "um6_data_interface.h"
#include "dataprocessing.h"
#include "createprofile.h"
class Graphs;
#include "mpu9250.h"
#include "mavproxyint.h"
#include <qcustomplot.h>

#define ACC_TO_DEG_DIVISOR  182.0416667

QT_BEGIN_NAMESPACE
class QLabel;

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

class settingsDialog;


/*This is the start of the MainWindow class*/
class MainWindow : public QMainWindow
{
    Q_OBJECT


//MainWindow Public Declerations
public:

    //MainWindow Constructor
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    struct launchData{
        QString time;
        QString flightEvent;
        double altitude;
        double velocity;
        double acceleration;
        double accelerationG;
        QString latitude;
        QString longitude;
        QString humLat;
        QString humLon;
        double gyroX;
        double gyroY;
        double gyroZ;
        double pitchRate;
        double rollRate;
        double yawRate;
        double magX;
        double magY;
        double magZ;

        double maxAlt;
        double maxVel;
        double maxAccelGs;
    };

    QVector<launchData> final_data;
    launchData current_data;

    void writeToFinalCSV();

    void putData(const QByteArray &data);

    /*Start Changes 2-14-17 Alex Wood*/

    bool getNewData;
    bool collectData;

    QVector<inputData> inputDataVector;

    QString curDataString;

    QByteArray dataBytes;

    QDataStream *inDataStream;   //Added to support data stream object in nose cone rx function
    Ui::MainWindow *ui;

    bool receivingData = false;

    void readNoseConeAvi();     //Added for Byte array read 3/31/17 Alex Wood

    void setCollectDataOn();

    void setCollectDataOff();

    void delay(int milliToWait);

    void setGpsLat(quint8 lb, quint8 mlb, quint8 mhb, quint8 hb, inputData *curData);
    void setGpsLon(quint8 lb, quint8 mlb, quint8 mhb, quint8 hb, inputData *curData);
    void setGpsTime(quint8 lb, quint8 mlb, quint8 mhb, quint8 hb, inputData *curData);
    void setGpsAlt(quint8 lb, quint8 mlb, quint8 mhb, quint8 hb, inputData *curData);

    /*End Changes 2-14-17 Alex Wood*/

    //Adding functions to scale input data from sensors
    void setScaled9250Acc(inputData *curData, quint16 accX, quint16 accY, quint16 accZ);
    void setScaled9250Gyro(inputData *curData, quint16 gyroX, quint16 gyroY, quint16 gyroZ);
    void setScaled9250Mag(inputData *curData, quint16 magX, quint16 magY, quint16 magZ);

    static DataProcessing plotting;

    void set_graph1(bool);
    void set_graph2(bool);
    void timerSetup();
    void updateTitle();
    void updateFlightLog();
    void printErrorLog(quint8, int);


    void alt_vel_update(int, double);
    void nav_update(double);
    void initializeMap();

    // MAPPING
    struct GPSCoordinate{
        double latitude;
        double longitude;
    };

    QQuickView *view = new QQuickView();

    int mapType;
    int zoom;
    double map_latitude;
    double map_longitude;
    bool circleOn;
    bool focusRocketOn;

    QList<GPSCoordinate> rocketPath;

    Q_INVOKABLE double get_mapType();
    Q_INVOKABLE double get_zoom();
    Q_INVOKABLE double get_lat();
    Q_INVOKABLE double get_long();
    Q_INVOKABLE bool get_circleState();
    Q_INVOKABLE bool get_focusRocketState();
    Q_INVOKABLE QList<MainWindow::GPSCoordinate> get_rocketPath();

    float Rand_f(float low, float high); //testing
    int Rand_i(int ilow, int ihigh); //testing
    // END MAPPING

    QList<double> altList;
    int altDiffCount = 0;

    bool altIsChanging();

    QString mission_time;
    int flightTime = 0;
    int launchTime = 0;
    QString landingTime;

    bool time_reset = false;
    bool apo_time_set = false;
    bool ascent_ind_set = false;
    bool launch_time_set = false;
    bool descent_ind_set = false;
    bool landing_time_set = false;

private slots:

    void NoseAviByte();

    //Invokes the about QT window method
    void aboutQt();

    //Shows the about window for this applicaion
    void about();

    //Opens the comm settings window
    void on_actionComm_Settings_triggered();

    //Close the application
    void on_actionQuit_triggered();

    //Call the aboutQT function
    void on_actionAbout_QT_triggered();

    //Open the Serial port
    void openSerialPort();

    //Close the serial port
    void closeSerialPort();

    //Read data from the serial port USED in on_sndButtonClicked
    void readData();


    //Error handler
    void handleError(QSerialPort::SerialPortError error);

    //This function is a triggared action for clicking on the 'about' in the help menu
    void on_action_About_triggered();

    //Action slot for the toolbar connect icon
    void on_actionConnect_triggered();

    //Action slot fot the toolbar disconnect icon
    void on_actionDisconnect_triggered();

    //This function is a triggered action for clicking on 'Open' in the File menu
    void on_action_Open_triggered();



    //Handles the call to get data from the MPU9250
    void on_mpuStartButton_clicked();

    //begins process of sending data from the input data structure to the graphed output
    void on_sndtoGrph_clicked();

    void on_action_New_triggered();

    void on_start_stop_clicked();

    void realtimeDataSlot();

    void on_actionRestart_triggered();

    void on_includeHistoric_toggled(bool checked);

    void on_mavProxyShowButton_clicked();

    void on_expoDemoCheckBox_clicked(bool checked);

    void on_mapSelect_valueChanged(int arg1);

public slots:
    // MAPPING
    void on_zoomSlider_valueChanged(int value);
    void on_circleCheckBox_clicked(bool checked);
    void on_focusRocketCheckBox_clicked(bool checked);
    void map_focus_update();

    double convertGPSCoord(double degrees, double minutes);

    void updateRocketPath();
    void randomPath(); //testing
    //END MAPPING

signals:
    // MAPPING
    void mapTypeChanged();
    void latitudeChanged();
    void longitudeChanged();
    void zoomChanged();
    void circleChanged();
    void focusOptionChanged();
    void focusRocketChanged();
    void rocketPathChanged();
    // END MAPPING

private:
    //Initiate connection with UART device
    void initActionConnections();

private:
    int m_inc = 5;
    bool m_toggle = false;

    QLabel *status;
    settingsDialog *settings;
    Graphs *graphWin;
    CreateProfile* profile;

    QSerialPort *serial;
    Graphs *graph_data;

    bool connected;             //will be true if connected to serial port, else false

    QTimer *rxTimer;

    QCustomPlot *altitude;
    QCustomPlot *velocity;
    bool includeHistoric = false;
    bool writePDF = false;
    bool writeCSV = false;
    QString profilePath = "../SensorData";

    double maxAlt = 0;
    double maxVel = 0;
    double maxAccelGs = 0;
    double prevGyrox = 0;
    double prevGyroy = 0;
    double prevGyroz = 0;

    MavProxyInt *mavProxLink;           //Added 05/10/17

    void showStatusMessage(const QString &message);
    void closeApplication();
};

#endif // MAINWINDOW_H

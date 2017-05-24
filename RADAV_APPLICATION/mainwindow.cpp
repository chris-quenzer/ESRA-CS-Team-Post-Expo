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

#include "mainwindow.h"
#include "dataprocessing.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include "graphs.h"

/* START This is for testing input data 2-13-17 Alex Wood*/
//#include "mpu9250.h"
/* END This is for testing input data 2-13-17 Alex Wood*/

#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include <QColor>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>
#include <QTimer>           //Added 2/26/17 Alex Wood for timing data read interval

//Added 2/26/17 Alex Wood for timing data read interval
#include <QTimer>

//Added 4/19/17 by Chris Quenzer for GPS Mapping/QML
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlContext>

QTime master_time(QTime::currentTime());
QTimer dataTimer;
bool sim_running = false;

QTimer *mapPathTimer = new QTimer;
QTimer *mapFocusTimer = new QTimer;

//data vars stored in "graphs.h"
int Graphs::m_dataSource = 0;

double Graphs::gyro_x;
double Graphs::gyro_y;
double Graphs::gyro_z;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowState(Qt::WindowMaximized);

    /*Added 1-17-2017 for connections*/
    serial = new QSerialPort(this);     //Create teh serial port object

    settings = new settingsDialog;      //Create the settings object
    graphWin = new Graphs;
    profile = new CreateProfile;

    status = new QLabel;                //Create the label object

    ui->statusBar->addWidget(status);   //Pass the status object to the tool bar

    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error), this, &MainWindow::handleError);

    connected = false;
    collectData = false;

    mavProxLink = new MavProxyInt();

    /*Finished additions for 1-17-2017*/

    // Launch LED indicator
    ui->launch_LED->setColor("green");
    ui->launch_LED->setDiameter(10);
    ui->launch_LED->setState(false);

    // Apogee LED indicator
    ui->apo_LED->setColor("green");
    ui->apo_LED->setDiameter(10);
    ui->apo_LED->setState(false);

    // Descent LED indicator
    ui->descent_LED->setColor("green");
    ui->descent_LED->setDiameter(10);
    ui->descent_LED->setState(false);
    ui->descent_LED->setFlashRate(500);

    // Landing LED indicator
    ui->landing_LED->setColor("green");
    ui->landing_LED->setDiameter(10);
    ui->landing_LED->setState(false);

    // GPS LED indicator
    ui->gps_LED->setState(true);

    // graph setup #######################################################################
    timerSetup();
    set_graph1(false);
    set_graph2(false);
    //connect(ui->start_stop, SIGNAL(on_start_stop_clicked()), Graphs, SLOT(&Graphs::on_start_stop_clicked()));

    // End graph setup ###################################################################

    // Mission time init
    mission_time = "00:00:00:000";
    ui->mission_time->display(mission_time);

    //set LAUNCH button background to green
    QPalette pal = ui->start_stop->palette();
    pal.setColor(QPalette::Button, QColor(Qt::green));
    ui->start_stop->setAutoFillBackground(true);
    ui->start_stop->setPalette(pal);
    ui->start_stop->update();

    //This timer will call the MPU-9250 function at the specified interval
    // Still need a way to start this after the serial port is setup
    rxTimer = new QTimer(this);

    // MAPPING
    initializeMap();
    // END MAPPING
}

//Default destructor
MainWindow::~MainWindow()
{
    ui->customPlot->savePdf("PlotPdf.pdf", 0, 0, QCP::epAllowCosmetic, "Adobe", "Rocket Data snapshot");

    delete mavProxLink;
    delete settings;
    delete ui;
    delete view; //needed so map doesn't try to read non-existent data and crash app
    delete mapPathTimer;
    delete mapFocusTimer;

}

/*Start Changes 2-14-17 Alex Wood*/


/******************************************************************************
* Function: NoseAviByte()
* Purpose: This is a rework, and the current version of the communications
*           interface. This interface uses byte shifiting to reconstruct
*           serialized data. This function alos displays the data to the UI
*           as well as stores the data in the data structure, thus extending
*           values read to the storage module.
* Parameters: None
* Output: This will store the values in teh data structure, will need to add
*           helper functions to output the values to the UI
*******************************************************************************/
void MainWindow::NoseAviByte()
{
    //Get data from nose cone avi bay
    readNoseConeAvi();

    //Look for SNP packet header
    int curCount = 0;
    int maxCount = dataBytes.size();

    //Loop through array of bytes
    while(curCount < maxCount)
    {

        //If packet header is found, parse data vals
        if(((dataBytes.at(curCount) == 'S') && (dataBytes.at(curCount + 1) == 'N') && (dataBytes.at(curCount + 2) == 'P')) && (curCount + 40) < maxCount)
        {
            //Build and fill data structure with received data
            inputData *curData = new inputData;

            //All incoming values should be in little endian order
            curCount += 3;
            /***Start Low-g MEMS MPU-9250***/
            quint16 accX = 0;
            quint16 accY = 0;
            quint16 accZ = 0;
            quint16 gyroX = 0;
            quint16 gyroY = 0;
            quint16 gyroZ = 0;
            quint16 magX = 0;
            quint16 magY = 0;
            quint16 magZ = 0;
            /***End Low-g MEMS MPU-9250***/

            /***Start High-g ACC***/
            quint8 accHX = 0;
            quint8 accHY = 0;
            quint8 accHZ = 0;
            /***End High-g ACC***/

            /***Start Hgh precision Alt***/
            quint32 highPresAlt = 0;
            /***End Hgh precision Alt***/

            /*** Start MPU 9250 Sensor Data***/
            accX = quint8(dataBytes.at(curCount)) << 8 | quint8(dataBytes.at(curCount + 1));
            curCount += 2;
            accY = quint8(dataBytes.at(curCount)) << 8 | quint8(dataBytes.at(curCount + 1));
            curCount += 2;
            accZ = quint8(dataBytes.at(curCount)) << 8 | quint8(dataBytes.at(curCount + 1));
            curCount += 2;
            gyroX = quint8(dataBytes.at(curCount)) << 8 | quint8(dataBytes.at(curCount + 1));
            curCount += 2;
            gyroY = quint8(dataBytes.at(curCount)) << 8 | quint8(dataBytes.at(curCount + 1));
            curCount += 2;
            gyroZ = quint8(dataBytes.at(curCount)) << 8 | quint8(dataBytes.at(curCount + 1));
            curCount += 2;
            magX = quint8(dataBytes.at(curCount)) << 8  | quint8(dataBytes.at(curCount + 1));
            curCount += 2;
            magY = quint8(dataBytes.at(curCount)) << 8  | quint8(dataBytes.at(curCount + 1));
            curCount += 2;
            magZ = quint8(dataBytes.at(curCount)) << 8  | quint8(dataBytes.at(curCount + 1));
            curCount += 2;

            setScaled9250Acc(curData, accX, accY, accZ);
            setScaled9250Gyro(curData, gyroX, gyroY, gyroZ);
            setScaled9250Mag(curData, magX, magY, magZ);

            /*** End MPU 9250 Sensor Data***/

            accHX = quint8(dataBytes.at(curCount));
            curCount += 1;
            accHY = quint8(dataBytes.at(curCount));
            curCount += 1;
            accHZ = quint8(dataBytes.at(curCount));
            curCount += 1;

            //highPresAlt = quint8(dataBytes.at(curCount)) | quint8(dataBytes.at(curCount + 1)) << 8 | quint8(dataBytes.at(curCount + 2)) << 16  | quint8(dataBytes.at(curCount + 3)) << 24;
            highPresAlt = quint8(dataBytes.at(curCount)) <<24 | quint8(dataBytes.at(curCount + 1)) << 16 | quint8(dataBytes.at(curCount + 2)) << 8  | quint8(dataBytes.at(curCount + 3));
            curCount += 4;

            /***Start GPS***/

            setGpsLat( quint8(dataBytes.at(curCount)), quint8(dataBytes.at(curCount + 1)), quint8(dataBytes.at(curCount + 2)), quint8(dataBytes.at(curCount + 3)), curData);
            curCount += 4;
            setGpsLon( quint8(dataBytes.at(curCount)), quint8(dataBytes.at(curCount + 1)), quint8(dataBytes.at(curCount + 2)), quint8(dataBytes.at(curCount + 3)), curData);
            curCount += 4;
            setGpsAlt(quint8(dataBytes.at(curCount)), quint8(dataBytes.at(curCount + 1)), quint8(dataBytes.at(curCount + 2)), quint8(dataBytes.at(curCount + 3)), curData);
            curCount += 4;
            setGpsTime(quint8(dataBytes.at(curCount)), quint8(dataBytes.at(curCount + 1)), quint8(dataBytes.at(curCount + 2)), quint8(dataBytes.at(curCount + 3)), curData);
            curCount += 4;



            curData->intAccX = accX;
            curData->accX = QString::number(accX);
            curData->intAccY = accY;
            curData->accY = QString::number(accY);
            curData->intAccZ = accZ;
            curData->accZ = QString::number(accZ);
            curData->intGyroX = gyroX;
            curData->gyroX = QString::number(gyroX);
            curData->intGyroY = gyroY;
            curData->gyroY = QString::number(gyroY);
            curData->intGyroZ = gyroZ;
            curData->gyroZ = QString::number(gyroZ);
            curData->intMagX = magX;
            curData->magX = QString::number(magX);
            curData->intMagY = magY;
            curData->magY = QString::number(magY);
            curData->intMagZ = magZ;
            curData->magZ = QString::number(magZ);

            curData->intAccXH = accHX;
            curData->accXH = QString::number(accHX);
            curData->intAccYH = accHY;
            curData->accYH = QString::number(accHY);
            curData->intAccZH = accHZ;
            curData->accZH = QString::number(accHZ);

            curData->intAltitude = highPresAlt;
            curData->altitude = QString::number(highPresAlt);


            //Output data to validate rx
            ui->timeOutputLabel->setText(curData->curTimeString);
            ui->accXDisplay->setText(curData->accX);
            ui->accYDisplay->setText(curData->accY);
            ui->accZDisplay->setText(curData->accZ);
            ui->gyroXDisplay->setText(curData->gyroX);
            ui->gyroYDisplay->setText(curData->gyroY);
            ui->gyroZDisplay->setText(curData->gyroZ);
            ui->magXDisplay->setText(curData->magX);
            ui->magYDisplay->setText(curData->magY);
            ui->magZDisplay->setText(curData->magZ);

            ui->highGXDisplay->setText(curData->accXH);
            ui->highGYDisplay->setText(curData->accYH);
            ui->highGZDisplay->setText(curData->accZH);

            ui->altimeterDisplay->setText(curData->altitude);

            ui->longDisplay->setText(curData->humanLon);
            ui->latDisplay->setText(curData->humanLat);
            ui->gpsAltDisplay->setText(curData->altGPSFeet + tr(" ft"));

            inputDataVector.push_back(*curData);

            profilePath = profile->getProfilePath();
            writeCSV = profile->writeCSVCheck();
            plotting.receiveDataVector(&inputDataVector, writeCSV, profilePath);

            //Adding scaled output field 05/10/17
            ui->scaledAccXDisp->setText(QString::number((curData->scaledAccX)));
            ui->scaledAccYDisp->setText(QString::number((curData->scaledAccY)));
            ui->scaledAccZDisp->setText(QString::number((curData->scaledAccZ)));

            ui->scaledGyroXDisp->setText(QString::number((curData->scaledGyroX)));
            ui->scaledGyroYDisp->setText(QString::number((curData->scaledGyroZ)));
            ui->scaledGyroZDisp->setText(QString::number((curData->scaledGyroZ)));

            ui->scaledMagXDisp->setText(QString::number((curData->scaledMagX)));
            ui->scaledMagYDisp->setText(QString::number((curData->scaledMagY)));
            ui->scaledMagZDisp->setText(QString::number((curData->scaledMagZ)));

            if(!plotting.isValidCoord(curData->latDegrees, curData->latMins, curData->lonDegrees, curData->lonMins))
            {
                ui->gps_status->setText("GPS Status: NO GPS LOCK");
                ui->gps_LED->setColor("red");
            }
            else
            {
                ui->gps_status->setText("GPS Status: GPS LOCK");
                ui->gps_LED->setColor("green");
            }

            //End edits on 05/10/17

            qDebug() << "Time: " + curData->curTime;
            qDebug() << "AccX: " + curData->accX;
            qDebug() << "AccY: " + curData->accY;
            qDebug() << "AccZ: " + curData->accZ;
            qDebug() << "GyroX: " + curData->gyroX;
            qDebug() << "GyroY: " + curData->gyroY;
            qDebug() << "GyroZ: " + curData->gyroZ;
            qDebug() << "MagX: " + curData->magX;
            qDebug() << "MagY: " + curData->magY;
            qDebug() << "MagZ: " + curData->magZ;

            qDebug() << "Heading: " << (atan2(curData->magY.toDouble(), curData->magX.toDouble()) * 180) / M_PI; // Heading in X-Y plane in degrees from North

        }
        else
        {
            printErrorLog(dataBytes.at(curCount), curCount);
            curCount++;
        }

    }
    printErrorLog(-1, -1);
    delay(1010);

}

void MainWindow::setGpsLat(quint8 lb, quint8 mlb, quint8 mhb, quint8 hb, inputData *curData)
{

    if(lb >= 127)
    {
        //We are in Southern Hemisphere
        curData->southHemi = true;
        lb -= 127;      //Remove the 8th bit position value to get rid of hem mod
    }
    else
    {
        curData->southHemi = false;
    }

    //curData->intGpsLat = lb | mlb << 8 | mhb << 16  | hb << 24;
    //Strange order and naming due to hardware sending in bigEndian
    curData->intGpsLat = lb << 24 | mlb << 16 | mhb << 8  | hb;

    double tmpDouble(double((curData->intGpsLat))/10000.0000);

    QString tmpString = QString::number(tmpDouble, 'f', 5);

    int sizeCheck = tmpString.size();

    //If the value is less than 9-digits including the decimal, prepend leading 0's
    if(9 - sizeCheck > 0)
    {
        //Add the needed ammount of leading zeros to the string
        for(int i = 0; i < sizeCheck; i++)
        {
            tmpString.push_front('0');
        }
    }

    //curData->latitude = tmpString;

    //QString subString = tmpString.mid((tmpString.size() - 8), 7);

    //QString subString2 = tmpString.mid(0, (tmpString.size() - 8));

    //Substring made up of the minutes and fraction of minutes portion. pos 2 and 3
    //contain seconds pos4 has decimal and pos 5-8 contain fractions of minutes
    QString subString = tmpString.mid(2,7);

    //This substring will contain only the degrees portion of lat, between 0 and 90 in two digits
    QString subString2 = tmpString.mid(0,2);

    curData->latDegrees = subString2.toUInt();
    curData->latMins = subString.toDouble();

    if(curData->southHemi == true)
    {
        //Build human readable output string
        tmpString = tr("S ") + subString2 + tr("°") + tr(" ") + subString + tr("'");
        curData->humanLat = tmpString;
        tmpString.clear();

        //Build string for use in GPS plotting
        tmpString = tr("-") + subString2 + subString;
        curData->latitude = tmpString;
        tmpString.clear();
    }
    else
    {
        //Build human readable output string
        tmpString = tr("N ") + subString2 + tr("°") + tr(" ") + subString + tr("'");
        curData->humanLat = tmpString;
        tmpString.clear();

        //Build string for use in GPS plotting
        tmpString = subString2 + subString;
        curData->latitude = tmpString;
        tmpString.clear();
    }

}

void MainWindow::setGpsLon(quint8 lb, quint8 mlb, quint8 mhb, quint8 hb, inputData *curData)
{
    if(lb >= 127)
    {
        //We are in Southern Hemisphere
        curData->eastHemi = true;
        lb -= 127;      //Remove the 8th bit position value to get rid of hem mod
    }
    else
    {
        curData->eastHemi = false;
    }

    //curData->intGpsLon = lb | mlb << 8 | mhb << 16  | hb << 24;
    curData->intGpsLon = lb << 24 | mlb << 16 | mhb << 8  | hb;

    double tmpDouble(double((curData->intGpsLon))/10000.0000);

    QString tmpString = QString::number(tmpDouble, 'f', 5);

    int sizeCheck = tmpString.size();

    //If the value is less than 10-digits including the decimal, prepend leading 0's ( 0 <= long <= 180) thus 1 morde digit
    if(10 - sizeCheck > 0)
    {
        //Add the needed ammount of leading zeros to the string
        for(int i = 0; i < sizeCheck; i++)
        {
            tmpString.push_front('0');
        }
    }

    //Substring made up of the minutes and fraction of minutes portion. pos 2 and 3
    //contain seconds pos4 has decimal and pos 5-8 contain fractions of minutes
    QString subString = tmpString.mid(3,7);

    //This substring will contain only the degrees portion of lon, between 0 and 90 in two digits
    QString subString2 = tmpString.mid(0,3);

    curData->lonDegrees = subString2.toUInt();
    curData->lonMins = subString.toDouble();

    if(curData->eastHemi == true)
    {
        //Build human readable output string
        tmpString = tr("E ") + subString2 + tr("°") + tr(" ") + subString + tr("'");
        curData->humanLon = tmpString;
        tmpString.clear();

        //Build string for use in GPS plotting
        tmpString = tr("-") + subString2 + subString;
        curData->longitude = tmpString;
        tmpString.clear();
    }
    else
    {
        //Build human readable output string
        tmpString = tr("W ") + subString2 + tr("°") + tr(" ") + subString + tr("'");
        curData->humanLon = tmpString;
        tmpString.clear();

        //Build string for use in GPS plotting
        tmpString = subString2 + subString;
        curData->longitude = tmpString;
        tmpString.clear();
    }
}

void MainWindow::setGpsTime(quint8 lb, quint8 mlb, quint8 mhb, quint8 hb, inputData *curData)
{
    quint32 gpsTime = 0;

    //gpsTime = lb | mlb << 8 | mhb << 16  | hb << 24;
    gpsTime = lb << 24 | mlb << 16 | mhb << 8  | hb;
    curData->intGpsTime = gpsTime;

    QString tmpString = QString::number(double((gpsTime) / 1000.000), 'f', 3);

    //Find out if there are 10 characters in the string, if not add leading zeros
    int sizeCheck = 10 - tmpString.size();

    //Zero fill leading characters for time string display
    if(sizeCheck > 0)
    {
        for(int i = 0; i < sizeCheck; i++)
        {
            tmpString.push_front('0');
        }
    }

    QString tmpString1 = tmpString.mid(0, 2);
    QString tmpString2 = tmpString.mid(2,2);
    QString tmpString3 = tmpString.mid(4,6);

    //QString returnString = tmpString1 + tr(":") + tmpString2 + tr(":") + tmpString3;
    curData->curTimeString = tmpString1 + tr(":") + tmpString2 + tr(":") + tmpString3;

}

void MainWindow::setGpsAlt(quint8 lb, quint8 mlb, quint8 mhb, quint8 hb, inputData *curData)
{
    quint32 altMeter = 0;
    double altFeet = 0;
    double toFeet = 3.8084;         //From google converter

    //altMeter = lb | mlb << 8 | mhb << 16  | hb << 24;
    altMeter = lb << 24 | mlb << 16 | mhb << 8  | hb;
    altFeet = altMeter * toFeet;

    curData->intGpsAlt = altMeter;
    curData->gpsAltFeet = altFeet;

    curData->altGPSMeter = QString::number(altMeter);
    curData->altGPSFeet = QString::number(altFeet);
}

/******************************************************************************
* Function: setScaled9250Acc()
* Purpose: This function is desgine to scale the sensor data to output in valid
*          human format. For acc -16 g's <= acc <= 16 g/sec. This gives
*          a range of 33 values possible. so the scale factor is 65535/33.
*          To normalize unsigned int to signed int, if value is grater than 32767
*          it is deemed to be a negative number, thus subtracting 65535 from it
*          will result in the proper negative value.
* Parameters: Componenets of accelerometer data and the curData structure to store values.
* Output: This will output the properly scaled value in g's  from the
*         sensor in each directions
*******************************************************************************/
void MainWindow::setScaled9250Acc(inputData *curData, quint16 accX, quint16 accY, quint16 accZ)
{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    if(accX > 32767)
    {
        //It is a negative value, Normalize and scale
        x = (((double)(accX - 65535)) / (65535/33));
        curData->scaledAccX = x;
    }
    else
    {
        //Positive value, just scale
        x = (((double)(accX)) / (65535/33));
        curData->scaledAccX = x;
    }

    qDebug() << tr("Scaled AccX: ") + curData->scaledAccX;

    if(accY > 32767)
    {
        //It is a negative value, Normalize and scale
        y = (((double)(accY - 65535)) / (65535/33));
        curData->scaledAccY = y;
    }
    else
    {
        //Positive value, just scale
        y = (((double)(accY)) / (65535/33));
        curData->scaledAccY = y;
    }

    qDebug() << tr("Scaled AccY: ") + curData->scaledAccY;

    if(accZ > 32767)
    {
        //It is a negative value, Normalize and scale
        z = (((double)(accZ - 65535)) / (65535/33));
        curData->scaledAccZ = z;
    }
    else
    {
        //Positive value, just scale
        z = (((double)(accZ)) / (65535/33));
        curData->scaledAccZ = z;
    }
    qDebug() << tr("Scaled AccZ: ") + curData->scaledAccZ;

}

/******************************************************************************
* Function: setScaled9250Gyro()
* Purpose: This function is desgine to scale the sensor data to output in valid
*          human format. For gyro -2000 deg/sec <= gyro <= 2000 deg/sec. This gives
*          a range of 4001 values possible. so the scale factor is 65535/4001.
*          To normalize unsigned int to signed int, if value is grater than 32767
*          it is deemed to be a negative number, thus subtracting 65535 from it
*          will result in the proper negative value.
* Parameters: Componenets of mag data and the curData dtructure to store values.
* Output: This will output the properly scaled value in degrees per second from the
*         sensor in each directions
*******************************************************************************/
void MainWindow::setScaled9250Gyro(inputData *curData, quint16 gyroX, quint16 gyroY, quint16 gyroZ)
{
    double tmpDouble = 0.0;

    if(gyroX > 32767)
    {
        //Negative value, Normalize and scale
        tmpDouble = (((double)(gyroX - 65535)) / (65535/4001));
    }
    else
    {
        //positive value, scale
        tmpDouble = (((double)(gyroX)) / (65535/4001));
    }

    curData->scaledGyroX = tmpDouble;
    qDebug() << tr("Scaled GyroX: ") +  curData->scaledGyroX;

    if(gyroY > 32767)
    {
        //Negative value, Normalize and scale
        tmpDouble = (((double)(gyroY - 65535)) / (65535/4001));
    }
    else
    {
        //positive value, scale
        tmpDouble = (((double)(gyroY)) / (65535/4001));
    }

    curData->scaledGyroY = tmpDouble;
    qDebug() << tr("Scaled GyroY: ") +   curData->scaledGyroY;

    if(gyroZ > 32767)
    {
        //Negative value, Normalize and scale
        tmpDouble = (((double)(gyroZ - 65535)) / (65535/4001));
    }
    else
    {
        //positive value, scale
        tmpDouble = (((double)(gyroZ)) / (65535/4001));
    }

    curData->scaledGyroZ = tmpDouble;
    qDebug() << tr("Scaled GyroZ: ") +  curData->scaledGyroZ;
}

/******************************************************************************
* Function: setScaled9250Mag
* Purpose: This function is desgine to scale the sensor data to output in valid
*          human format. For magnetometer -4800 uT <= mag <= 4800 uT. This gives
*          a range of 9601 values possible. so the scale factor is 65535/9601.
*          To normalize unsigned int to signed int, if value is grater than 32767
*          it is deemed to be a negative number, thus subtracting 65535 from it
*          will result in the proper negative value.
* Parameters: Componenets of mag data and the curData dtructure to store values.
* Output: This will output the properly scaled value in micro tesla from the
*         sensor in each directions
*******************************************************************************/

void MainWindow::setScaled9250Mag(inputData *curData, quint16 magX, quint16 magY, quint16 magZ)
{
    double tmpDouble = 0.0;

    if(magX > 32767)
    {
        //Negative value, Normalize and scale
        tmpDouble = (magX - 65535);
        tmpDouble = tmpDouble / (65535/9601);
    }
    else
    {
        //positive value, scale
        tmpDouble = (((double)(magX)) / (65535/9601));
    }

    curData->scaledMagX = tmpDouble;
    qDebug() << tr("Scaled MagX: ") + curData->scaledMagX;

    if(magY > 32767)
    {
        //Negative value, Normalize and scale
        tmpDouble = (((double)(magY - 65535)) / (65535/9601));
    }
    else
    {
        //positive value, scale
        tmpDouble = (((double)(magY)) / (65535/9601));
    }

    curData->scaledMagY = tmpDouble;
    qDebug() << tr("Scaled MagY: ") + curData->scaledMagY;

    if(magZ > 32767)
    {
        //Negative value, Normalize and scale
        tmpDouble = (((double)(magZ - 65535)) / (65535/9601));
    }
    else
    {
        //positive value, scale
        tmpDouble = (((double)(magZ)) / (65535/9601));
    }

    curData->scaledMagZ = tmpDouble;
    qDebug() << tr("Scaled MagZ: ") + curData->scaledMagZ;
}

void MainWindow::readNoseConeAvi()
{
    QByteArray noseData = serial->readAll();

    dataBytes = noseData;

    qDebug() << "Reading data bytes from telemetry source: ";
}


void MainWindow::setCollectDataOn()
{
    //Modified to start and stop data cllection
    collectData = !collectData;
}

void MainWindow::setCollectDataOff()
{
    collectData = false;
}

//
/******************************************************************************
* Function: delay(int milliToWait)
* Purpose: This function sets the delay time in between data retrival instances.
* Parameters: Integer value of milli seconds to wait before polling before reading
*               serial buffer for new data.
* Output: This function will interupt at the interval specified to read more data.
* Citation: http://stackoverflow.com/questions/3752742/how-do-i-create-a-pause-wait-function-using-qt
*******************************************************************************/
void MainWindow::delay(int milliToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs(milliToWait);
    while(QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

/*End Changes 2-14-17 Alex Wood*/



void MainWindow::on_action_Open_triggered()
{
    plotting.importFile_csv();
    qDebug() << plotting.path;
}

void MainWindow::aboutQt()
{
    aboutQt();
}

/******************************************************************************
* Function: openSerialPort()
* Purpose: This function estableshes the serial connection with the selected
*          device
* Parameters: None
* Output: This function will open the serial connection or display an error
*         message
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void MainWindow::openSerialPort()
{

    // This sets the settings for the program. Create a settings object and fill
    // parameters
    settingsDialog::Settings curSettings = settings->settings();

    if(curSettings.name != "Custom" && connected == false)
    {
        //Set the connections name
        serial->setPortName(curSettings.name);
        ui->pNameLabel->setText(tr("Port Name: ") + curSettings.name);

        //Set the connection baud rate
        serial->setBaudRate(curSettings.baudRate);
        ui->bRateLabel->setText(tr("Baud Rate: ") + curSettings.stringBaudRate);

        //Set the Data Bits settings
        serial->setDataBits(curSettings.dataBits);
        ui->dBitsLabel->setText(tr("Data Bits: ") + curSettings.stringDataBits);

        //Set the parity bits
        serial->setParity(curSettings.parity);
        ui->pBitsLabel->setText(tr("Parity: ") + curSettings.stringParity);

        //Set the Stop bits
        serial->setStopBits(curSettings.stopBits);
        ui->sBitsLabel->setText(tr("Stop Bits: ") + curSettings.stringStopBits);

        //Set the flow control
        serial->setFlowControl(curSettings.flowControl);
        ui->fContLabel->setText(tr("Flow Control: ") + curSettings.stringFlowControl);

        if (serial->open(QIODevice::ReadWrite))
        {
            showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(curSettings.name).arg(curSettings.stringBaudRate).arg(curSettings.stringDataBits)
                          .arg(curSettings.stringParity).arg(curSettings.stringStopBits).arg(curSettings.stringFlowControl));
            connected = true;
            //sensor->setSerialPort(serial);
        }
        else
        {
            //Display error message for connection failure.
            QMessageBox::critical(this, tr("Error"), serial->errorString());
            showStatusMessage(tr("Open Error"));
        }

    }
    else if(connected)
    {
        QMessageBox::critical(this, tr("Error"), "You already have a connection");
        //showStatusMessage(tr("Open Error")
    }
    else
    {
        //No device was selected, display error
        QMessageBox::critical(this, tr("Error"), "No device selected, please select a dvice before connecting.");
        //showStatusMessage(tr("Open Error"));
        showStatusMessage(tr("No device selected, not connected"));
    }

}

/******************************************************************************
* Function: closeSerialPort()
* Purpose: This function will close the open serial port connection when called
* Parameters: none
* Output: The serial port will be closed
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void MainWindow::closeSerialPort()
{
    if(serial->isOpen())
    {
        serial->close();
    }

    //Re enable the connecttion button
    ui->pNameLabel->setText(tr("Port Name:"));
    ui->bRateLabel->setText(tr("Baud Rate: "));
    ui->dBitsLabel->setText(tr("Data Bits: "));
    ui->pBitsLabel->setText(tr("Parity Bits: "));
    ui->sBitsLabel->setText(tr("Stop Bits: "));
    ui->fContLabel->setText(tr("Flow Control: "));

    showStatusMessage(tr("Disconnected"));

    connected = false;
}

/******************************************************************************
* Function: about()
* Purpose: This function will show the about window for this application
* Parameters: None
* Output: This will display teh about window for the application
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void MainWindow::about()
{
    QMessageBox about;

    about.setWindowTitle("About RADAV");
    about.setText("Alpha version of RADAV for 2017 OSU ESRA Team");
    about.setInformativeText("The <b>RADAV Appliaction</b> is designed to receive"
                             " telemetry data from the ESRA rocket via a serial connection "
                             "to the radio tranciever.");
    about.setIconPixmap(QPixmap(":/Resources/images/OSU_AIAA_2016-17.png").scaled(512,360, Qt::KeepAspectRatio));
    about.show();
    about.exec();
}


/******************************************************************************
* Function: readData()
* Purpose: This function will read data from the serial connection
* Parameters: None
* Output: This function will save the recieved data in the data structure
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void MainWindow::readData()
{
    QByteArray data = serial->readAll();

    QString rxDataString(data);

    ui->rxTextLabel->setText(rxDataString);
}


/******************************************************************************
* Function: handleError(QSerialPort::SerialPortError error)
* Purpose: THis function handels errors with the serial connection
* Parameters: Serial Port Error String
* Output: Will output an error message if error occurs
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if(error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this, tr("Critical Error 2"), serial->errorString());
        closeSerialPort();
    }
}

/******************************************************************************
* Function: initActionConnections()
* Purpose:  This function associates the connect and disconnect icons on the tool
*            bar with the desired functionality.
* Parameters: None
* Output: Calls desired function based on the icon used
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void MainWindow::initActionConnections()
{
    //This connects the connect action with the appropriate function call
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);

    //This connects the disconnect action with the appropriate function call
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
}

/******************************************************************************
* Function: showStatusMessage(const QString &message)
* Purpose:  This function is designed to output the connection status of the serial
*           port in the status bar at the bottom of a window.
* Parameters: A string that contains the error message for the particular status mesage
* Output:   The curent status of the cerial connection.
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void MainWindow::showStatusMessage(const QString &message)
{

    // This sets the status message in the status bar. This will display connection
    // information.
    status->setText(message);
}

/******************************************************************************
* Function: on_actionComm_Settings_triggered()
* Purpose: This function creates the settings dialog window where the user will
*          select the comm device to use to recieve data.
* Parameters: None
* Output: Application will close by calling the closeApplication helper function
*         Which relies on the QApplication::quit() function
*******************************************************************************/
void MainWindow::on_actionComm_Settings_triggered()
{
    //settingsDialog *setDialog = new settingsDialog();
    settings->show();
}


/******************************************************************************
* Function: on_actionQuit_triggered()
* Purpose: This function closes the application by calling the closeApplication
*          helper function.
* Parameters: None
* Output: Application will close by calling the closeApplication helper function
*         Which relies on the QApplication::quit() function
*******************************************************************************/
void MainWindow::on_actionQuit_triggered()
{
    QCoreApplication::quit();
}


/******************************************************************************
* Function: AboutQT()
* Purpose: Display information about the version of QT used to create the
*          application
* Parameters: None
* Output: New dialog with all current QT application information
*******************************************************************************/
void MainWindow::on_actionAbout_QT_triggered()
{
    QApplication::aboutQt();
}

/******************************************************************************
* Function: closeApplication()
* Purpose: Private helper function to close the application
* Parameters: None
* Output: The application window will be closed.
*******************************************************************************/
void MainWindow::closeApplication()
{
    on_actionQuit_triggered();
}

/******************************************************************************
* Function:
* Purpose:
* Parameters:
* Output:
*******************************************************************************/

void MainWindow::on_action_About_triggered()
{
    MainWindow::about();
}

void MainWindow::on_actionConnect_triggered()
{
    openSerialPort();
}

void MainWindow::on_actionDisconnect_triggered()
{
    closeSerialPort();
}

void MainWindow::nav_update(double time)
{

        double gyro_x = plotting.getAttributeFromSource(plotting.source, X_GYRO, 1);
        double gyro_y = plotting.getAttributeFromSource(plotting.source, Y_GYRO, 1);
        double gyro_z = plotting.getAttributeFromSource(plotting.source, Z_GYRO, 1);
        if(gyro_x != nan(""))
        {
            ui->GLwidget->nav_rot_x = gyro_x;
            ui->GLwidget->nav_rot_y = gyro_y;
            ui->GLwidget->nav_rot_z = gyro_z;
        }

        double ratePitch = (gyro_x - prevGyrox) / time;
        double rateRoll = (gyro_y - prevGyroy) / time;
        double rateYaw = (gyro_z - prevGyroz) / time;
        prevGyrox = gyro_x;
        prevGyroy = gyro_y;
        prevGyroz = gyro_z;

        qDebug() << "GYRO DATA: " << ui->GLwidget->nav_rot_x;//plotting.NextXGyro(1);

        ui->pitch_LCD->display(gyro_x);
        ui->roll_LCD->display(gyro_y);
        ui->yaw_LCD->display(gyro_z);
        ui->pitchRate_LCD->display(ratePitch);
        ui->rollRate_LCD->display(rateRoll);
        ui->yawRate_LCD->display(rateYaw);

        //double accel = plotting.getAttributeFromSource(plotting.source, X_ACCEL, 1);
        //ui->accel_LCD->display(accel);


}

void MainWindow::alt_vel_update(int key, double time)
{
    struct baseAltitudeInfo altInfo = profile->getAltitudeInfo();

    current_data.time = mission_time; // TIME

    //altitude
    double alt = plotting.getNextAltitude(plotting.source, ALTITUDE, altInfo);
    double inputAlt, lastKnownAlt, lastKnownMaxAlt;
    plotting.altInit = altInfo.baseHeight;

    //velocity
    double vel, inputVel;
    if(altList.empty())
    {
        vel = 0;
    }

    if(alt != nan(""))
    {
        graph_data->plotNextAltitude(key, altitude, plotting, altInfo, alt);
        inputAlt = alt;
        altList.push_front(inputAlt);
        ui->alt_cur_LCD->display(inputAlt);
        current_data.altitude = inputAlt; // ALTITUDE
        lastKnownAlt = inputAlt;

        if(alt > maxAlt)
        {
             maxAlt = alt;
             ui->alt_max_LCD->display(maxAlt);
             ui->apo_LED->setState(false);
             apo_time_set = false;
        }
        else
        {
            lastKnownMaxAlt = maxAlt;
            ui->alt_max_LCD->display(lastKnownMaxAlt);
            if(inputAlt > 0 && !apo_time_set)
            {
                ui->apo_LED->setState(true);
                ui->apo_time_label->setText(mission_time);
                current_data.flightEvent = "Apogee"; // APOGEE
                apo_time_set = true;
            }
        }

        ui->alt_cur_LCD->display(lastKnownAlt);
    }
    else
    {
        ui->alt_cur_LCD->display(lastKnownAlt);
    }

    if(vel != nan(""))
    {
        if(altList.size() > 1)
        {
            vel = plotting.getNextVelocity(plotting.source, 0, altList[1], altList[0]);
        }

        if(vel > 50 && !launch_time_set)
        {
            ui->launch_LED->setState(true);
            ui->launch_time_label->setText(mission_time);
            current_data.flightEvent = "Launch"; // LAUNCH
            launch_time_set = true;
        }

        graph_data->plotNextVelocity(key, velocity, plotting, time, includeHistoric, vel);

        ui->vel_cur_LCD->display(vel);

        current_data.velocity = vel; // VELOCITY

        if(vel > maxVel)
        {
             maxVel = vel;
             ui->vel_max_LCD->display(vel);
        }

        if(vel < -2)
        {
            ui->descent_LED->setFlashing(true);
        }
        else
        {
            ui->descent_LED->setState(false);
        }
    }

    double accelMag = plotting.getAccelerationMagnitude(1);
    ui->accel_LCD->display(accelMag);
    current_data.acceleration = accelMag; // ACCELLERATION

    double gForce = plotting.getGForce();
    ui->g_force->display(gForce);

    current_data.gyroX = 0;
    current_data.gyroY = 0;
    current_data.gyroZ = 0;

    current_data.pitchRate = 0;
    current_data.rollRate = 0;
    current_data.yawRate = 0;

    current_data.magX = 0;
    current_data.magX = 0;
    current_data.magX = 0;
}

/******************************************************************************
* Function: on_pushButton_2_clicked()
* Purpose: This curently initiates the parsing of incoming sensor data - NEED UPDATE -
* Parameters: None
* Output: The output fieleds will be populated with sensor data
*******************************************************************************/
void MainWindow::on_mpuStartButton_clicked()
{

    //NoseAviByte()
    setCollectDataOn();
    if(collectData)
    {
        qDebug() << "Data collection started!";
        //rxTimer = new QTimer(this);
        //connect(rxTimer, SIGNAL(timeout()),this, SLOT(startMpu9250()));
        //connect(rxTimer, SIGNAL(timeout()),this, SLOT(noseConeData()));
        connect(rxTimer, SIGNAL(timeout()),this, SLOT(NoseAviByte()));
        rxTimer->start(500);        //get data from sensor 2x secnd
    }
    else
    {
        //disconnect(rxTimer, SIGNAL(timeout()),this, SLOT(startMpu9250()));
        //disconnect(rxTimer, SIGNAL(timeout()),this, SLOT(noseConeData()));
        disconnect(rxTimer, SIGNAL(timeout()),this, SLOT(NoseAviByte()));
        qDebug() << "Data collection stopped!";
    }

}

void MainWindow::on_sndtoGrph_clicked()
{
    QFileDialog dialog(this);

    inputData tmpData;
    m_inc ++;
    tmpData.accX = QString::number(m_inc);
    tmpData.accY = QString::number(m_inc);
    tmpData.accZ = QString::number(m_inc);
    tmpData.gyroX = QString::number(m_inc);
    tmpData.gyroY = QString::number(m_inc);
    tmpData.gyroZ = QString::number(m_inc);
    tmpData.magX = QString::number(m_inc);
    tmpData.magY = QString::number(m_inc);
    tmpData.magZ = QString::number(m_inc);

    tmpData.altitude = QString::number(m_inc);
    tmpData.curTime = QString::number(m_inc);
    tmpData.latitude = QString::number(m_inc+40);
    tmpData.longitude = QString::number(m_inc+40);


    tmpData.altGPSMeter = QString::number(m_inc+5);
    inputDataVector.push_back(tmpData);

    tmpData.accX = QString::number(4);
    tmpData.accY = QString::number(3);
    tmpData.accZ = QString::number(3);
    tmpData.gyroX = QString::number(2);
    tmpData.gyroY = QString::number(2);
    tmpData.gyroZ = QString::number(2);
    tmpData.magX = QString::number(3);
    tmpData.magY = QString::number(3);
    tmpData.magZ = QString::number(3);

    tmpData.altitude = QString::number(m_inc);
    tmpData.curTime = QString::number(m_inc);
    tmpData.latitude = QString::number(m_inc+41);
    tmpData.longitude = QString::number(m_inc+41);
    tmpData.altGPSMeter = QString::number(m_inc);
    inputDataVector.push_back(tmpData);

    tmpData.accX = QString::number(-1);
    tmpData.accY = QString::number(-1);
    tmpData.accZ = QString::number(-1);
    tmpData.gyroX = QString::number(-1);
    tmpData.gyroY = QString::number(-1);
    tmpData.gyroZ = QString::number(-1);
    tmpData.magX = QString::number(-1);
    tmpData.magY = QString::number(-1);
    tmpData.magZ = QString::number(-1);

    tmpData.altitude = QString::number(m_inc);
    tmpData.curTime = QString::number(m_inc);

    tmpData.latitude = QString::number(m_inc+41);
    tmpData.longitude = QString::number(m_inc+41);
    tmpData.altGPSMeter = QString::number(m_inc);   //Changed by alex wood 4/15/17 for data struct changes

    inputDataVector.push_back(tmpData);

    plotting.source = SENSOR;
    profilePath = profile->getProfilePath();
    writeCSV = profile->writeCSVCheck();
    MainWindow::plotting.receiveDataVector(&inputDataVector, writeCSV, profilePath);
    printErrorLog(24, 0);
    printErrorLog(25, 1);
    printErrorLog(24, -1);




}

//FUNCTIONS FOR "graphs.cpp" INTERACTION ###################################################

void MainWindow::set_graph1(bool historic)
{
    altitude = ui->customPlot;
    graph_data->makeAltitudePlot(altitude);
}

void MainWindow::set_graph2(bool historic)
{
    velocity = ui->customPlot_2;
    graph_data->makeVelocityPlot(velocity, historic);
}

void MainWindow::timerSetup()
{
    dataTimer.setSingleShot(false);
    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
   //  connect(ui->applyButton, &QPushButton::clicked, this, &settingsDialog::apply);
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(nav_update()));       //Connects Nav ball to graph output vals

}


void MainWindow::realtimeDataSlot()
{
    // calculate two new data points:
    double key = master_time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;

    //Mission time display ---------------------------------
    int secs = master_time.elapsed() / 1000;
    int mins = (secs / 60) % 60;
    int hours = (secs / 3600);
    int ms = (master_time.elapsed() % 1000);
    secs = secs % 60;
    mission_time = QString("%1:%2:%3:%4")
            .arg(hours, 2, 10, QLatin1Char('0'))
            .arg(mins, 2, 10, QLatin1Char('0'))
            .arg(secs, 2, 10, QLatin1Char('0'))
            .arg(ms, 3, 10, QLatin1Char('0'));
    ui->mission_time->display(mission_time);
    //------------------------------------------------------

    if (key-lastPointKey > 1.0) // at most add point every 2 ms
    {
        // add data to graphs
       double timeMsec = plotting.getAttributeFromSource(plotting.source, GPS_TIME, 1);
       double timeMsec2 = plotting.getAttributeFromSource(plotting.source, GPS_TIME, 1);

       double time = 1.0; //TODO: Add time count to parse function, instead of 1

       nav_update(time);
       updateRocketPath();
       alt_vel_update(key, time);
       final_data.append(current_data);
       current_data.flightEvent = "";

       lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->customPlot->xAxis->setRange(0, key, Qt::AlignLeft);
    ui->customPlot->replot();

   // ui->customPlot_2->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->customPlot_2->xAxis->setRange(0, key, Qt::AlignLeft);
    ui->customPlot_2->replot();

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 1.0) // average fps over 2 seconds
    {
      lastFpsKey = key;
      frameCount = 0;
    }
}

void MainWindow::writeToFinalCSV()
{
    QDateTime fileDate;
    QString writeFile = profile->getProfilePath() + "/finalData" + fileDate.currentDateTime().toString("dd.MM.yyyy") + ".csv";

    QFile::remove(writeFile);

    QFile csv(writeFile);

    //if(csv.isOpen())
    //{
    //    csv.copy(writeFile);
    //}

    if(!csv.open(QFile::Append | QFile::Text))
    {
        qDebug() << csv.errorString();
        return;
    }
    QTextStream csvStream( &csv );

    csvStream << "Time----------,Event----------,Altitude----------,Velocity----------,Acceleration----------,Latitude----------,"
                 "Longitude----------,GyroX----------,GyroY----------,GyroZ----------,Pitch Rate----------,Roll Rate----------,"
                 "Yaw Rate----------,MagX----------,MagY----------,MagZ----------\n";
    for(int i = 0; i < final_data.size(); i++)
    {
        launchData tempData = final_data.at(i);
        csvStream << tempData.time << "," << tempData.flightEvent << "," << tempData.altitude << "," <<
                     tempData.velocity << "," << tempData.acceleration << "," << tempData.latitude << "," <<
                     tempData.longitude << "," << tempData.gyroX << "," << tempData.gyroY << "," <<
                     tempData.gyroZ << "," << tempData.pitchRate << "," << tempData.rollRate << "," <<
                     tempData.yawRate << "," << tempData.magX << "," << tempData.magY << "," << tempData.magZ << "\n";
    }

    csv.close();
}

void MainWindow::on_start_stop_clicked()
{
    QString flightName = "";
    flightName = profile->getFlightName();
    setWindowTitle("RADAV - Alpha " + flightName);
    Graphs::m_dataSource = FFILE;

    sim_running = !sim_running;

    if(sim_running)
    {

        if(MainWindow::plotting.path == "")
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(NULL, "Continue?", "Are you sure you want to start recording data?",
                                        QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::No)
            {
                sim_running = false;
                return;
            }
            else
            {
                plotting.source = SENSOR;
            }

        }
        if(flightName == "")
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(NULL, "Continue?", "You have not created a profile, if you continue your data cannot be saved",
                                        QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::No)
            {
                sim_running = false;
                return;
            }
        }

        dataTimer.start(0); // Interval 0 means to refresh as fast as possible

        master_time.start();
        printf("Timer started.\n");
        ui->start_stop->setText("STOP");

        //set STOP button outline to red
        QPalette pal = ui->start_stop->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->start_stop->setAutoFillBackground(true);
        ui->start_stop->setPalette(pal);
        ui->start_stop->update();
    }
    else
    {
        dataTimer.stop();
        master_time.restart();
        printf("Timer stopped.\n");
        ui->start_stop->setText("LAUNCH");

        //set LAUNCH button background to green
        QPalette pal = ui->start_stop->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->start_stop->setAutoFillBackground(true);
        ui->start_stop->setPalette(pal);
        ui->start_stop->update();

        if(profile->writeCSVCheck())
        {
            writeToFinalCSV();
        }

        updateFlightLog();
    }

    writePDF = profile->writePDFCheck();
    if(writePDF)
    {
        ui->customPlot->savePdf(profilePath + "/Altitude.pdf", 0, 0, QCP::epAllowCosmetic, "Adobe", "Altitude snapshot for flight");
        ui->customPlot_2->savePdf(profilePath + "/Velocity.pdf", 0, 0, QCP::epAllowCosmetic, "Adobe", "Velocity snapshot for flight");
    }
}

/*******************************************************
 * Function: update flight log
 * Description: Opens FLight log created with profile and adds max altitude and max velocity reached
 *
 *
 * ****************************************************/
void MainWindow::updateFlightLog()
{
    QString writeFile = profilePath + "/FlightLog.txt";
    QFile flight(writeFile);

    if(!flight.open(QFile::Append | QFile::Text))
    {
        qDebug() << flight.errorString();
        //return 0;
    }
    QTextStream flightStream( &flight );
    flightStream << "Max Altitude Attained During Flight: " << maxAlt << " ft." << endl;
    flightStream << "Max Velocity Attained During Flight: " << maxVel << " ft./s" << endl;
    flight.close();
}

/*******************************************************
 * Function: When you click New from the main window
 * Description: Allows user to create a new profile using the main windows profile object
 *
 *
 * ******************************************************/
void MainWindow::on_action_New_triggered()
{
    profile->show();
}

/*********************************************************
 * Function: includeHistoric
 * Description: Allows data from a csv file selected by the user to be displayed in the background
 * of current data being plotted
 *
 * ******************************************************/
void MainWindow::on_includeHistoric_toggled(bool checked)
{
    includeHistoric = checked;
    set_graph2(checked);
}


void MainWindow::printErrorLog(quint8 byteArray, int location)
{
          QDateTime fileDate;
          QString writeFile = profilePath + "/ErrorLog.txt";
          QFile flight(writeFile);

          if(!flight.open(QFile::Append | QFile::Text))
          {
              qDebug() << flight.errorString();
              //return 0;
          }
          QTextStream flightStream( &flight );
        if(location > -1)
        {
          flightStream << "Byte " << byteArray << " lost at " << location << ", ";
        }
        else
        {
            flightStream << "\n" << fileDate.currentDateTime().toString("hh:mm:ss") << fileDate.currentDateTime().toString("MM.dd.yyyy") << endl;
        }
          flight.close();
}
// GPS MAPPING FUNCTIONS ##############################################################################
// MAPPING

void MainWindow::initializeMap()
{
    zoom = 15;
    map_latitude = 43.7958; //testing
    map_longitude = -120.6516; //testing
    circleOn = false;
    focusRocketOn = true;

    //connect(mapPathTimer, SIGNAL(timeout()), this, SLOT(updateRocketPath()));
    //mapPathTimer->setSingleShot(false);
    //mapPathTimer->start(1000); //calls updateRocketPath() every 1 sec

    connect(mapFocusTimer, SIGNAL(timeout()), this, SLOT(map_focus_update()));
    mapFocusTimer->setSingleShot(false);
    mapFocusTimer->start(0);

    ui->zoomSlider->setValue(zoom);
    ui->zoomLCD->display(zoom);

    ui->latitudeSpinBox->setValue(map_latitude);
    ui->longitudeSpinBox->setValue(map_longitude);

    ui->circleCheckBox->setChecked(circleOn);
    ui->focusRocketCheckBox->setChecked(focusRocketOn);


    view->rootContext()->setContextProperty("mapData", this);
    ui->map = QWidget::createWindowContainer(view, ui->mapFrame);
    ui->map->setMinimumSize(ui->mapFrame->width(), ui->mapFrame->height());
    ui->map->setMinimumSize(ui->mapFrame->width(), ui->mapFrame->height());
    ui->map->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl("qrc:Resources/qml/mapping.qml"));
    // END MAPPING
}

double MainWindow::convertGPSCoord(double degrees, double minutes)
{
    double decDeg;
    decDeg = degrees + minutes / 60;
    return decDeg;
}

void MainWindow::on_latitudeSpinBox_valueChanged(double arg1)
{
    map_latitude = arg1;
    //qDebug() << latitude;
    emit latitudeChanged();
}

void MainWindow::on_longitudeSpinBox_valueChanged(double arg1)
{
    map_longitude = arg1;
    //qDebug() << latitude;
    emit longitudeChanged();
}

void MainWindow::on_zoomSlider_valueChanged(int value)
{
    zoom = value;
    ui->zoomLCD->display(zoom);
    emit zoomChanged();
}

void MainWindow::on_circleCheckBox_clicked(bool checked)
{
    circleOn = checked;
    emit circleChanged();
}

void MainWindow::on_focusRocketCheckBox_clicked(bool checked)
{
    focusRocketOn = checked;
    emit focusOptionChanged();
}

void MainWindow::map_focus_update()
{
    ui->map->setMinimumSize(ui->mapFrame->width(), ui->mapFrame->height());
    ui->map->setMinimumSize(ui->mapFrame->width(), ui->mapFrame->height());
    emit focusRocketChanged();
}

void MainWindow::updateRocketPath()
{
    //qDebug() << "Looking for GPS Coord....";

    GPSCoordinate coord;
    double latDegrees = plotting.getAttributeFromSource(plotting.source, LAT_DEG, 1);
    double lonDegrees = plotting.getAttributeFromSource(plotting.source, LON_DEG, 1);

    double latMins = plotting.getAttributeFromSource(plotting.source, LAT_MIN, 1);
    double lonMins = plotting.getAttributeFromSource(plotting.source, LON_MIN, 1);

    if(!plotting.isValidCoord(latDegrees, latMins, lonDegrees, lonMins))
    {
        ui->gps_status->setText("GPS Status: NO GPS LOCK");
        ui->gps_LED->setColor("red");
        current_data.latitude = "GPS ERROR";
        current_data.longitude = "GPS ERROR";
        return;
    }
    else
    {
        map_latitude = convertGPSCoord(latDegrees, latMins);
        map_longitude = -(convertGPSCoord(lonDegrees, lonMins));

        ui->gps_status->setText("GPS Status: GPS LOCK");
        ui->gps_LED->setColor("green");
        current_data.latitude = QString::number(map_latitude); // LATITUDE
        current_data.longitude = QString::number(map_longitude); // LONGITUDE
    }


    ui->GPS_lat_LCD->display(map_latitude);
    ui->GPS_long_LCD->display(map_longitude);

    ui->latitudeSpinBox->setValue(map_latitude); //debug
    ui->longitudeSpinBox->setValue(map_longitude); //debug

    //qDebug() << "Current GPS Coord: (" << map_latitude << "," << map_longitude << ")";

    coord.latitude = map_latitude;
    coord.longitude = map_longitude;

    if(rocketPath.empty())
    {
        rocketPath.append(coord);
      
        //qDebug() << "New coord added: (" << rocketPath.last().latitude << "," << rocketPath.last().longitude << ")";

        emit latitudeChanged();
        emit longitudeChanged();
        emit rocketPathChanged();
    }
    else
    {
        if((rocketPath.last().latitude != coord.latitude) ||
           (rocketPath.last().longitude != coord.longitude)) // Only add to path if different coordinate
        {
            rocketPath.append(coord);

            //qDebug() << "New coord added: (" << rocketPath.last().latitude << "," << rocketPath.last().longitude << ")";

            emit latitudeChanged();
            emit longitudeChanged();
            emit rocketPathChanged();
        }
    }
}

double MainWindow::get_zoom()
{
    return zoom;
}

double MainWindow::get_lat()
{
    return map_latitude;
}

double MainWindow::get_long()
{
    return map_longitude;
}

bool MainWindow::get_circleState()
{
    return circleOn;
}

bool MainWindow::get_focusRocketState()
{
    return focusRocketOn;
}

QList<MainWindow::GPSCoordinate> MainWindow::get_rocketPath()
{
    return rocketPath;
}

void MainWindow::randomPath()
{
    map_latitude += Rand_f(-0.001, 0.001);
    map_longitude += Rand_f(-0.001, 0.001);

    ui->latitudeSpinBox->setValue(map_latitude);
    ui->longitudeSpinBox->setValue(map_longitude);

    emit latitudeChanged();
    emit longitudeChanged();
}

float MainWindow::Rand_f(float low, float high)
{
    long random();		// returns integer 0 - TOP
    float r;		// random number

    r = (float)rand();

    return(low + r * (high - low) / (float)RAND_MAX);
}


int MainWindow::Rand_i(int ilow, int ihigh)
{
    float low = (float)ilow;
    float high = ceil((float)ihigh);

    return (int)Rand_f(low, high);
}

// END GPS MAPPING FUNCTIONS ##############################################################################

void MainWindow::on_mavProxyShowButton_clicked()
{
    mavProxLink->show();
}

void MainWindow::on_expoDemoCheckBox_clicked(bool checked)
{
    plotting.demo = checked;
}

#ifndef MPU9250_H
#define MPU9250_H

#include <QObject>
#include <QDataStream>
#include <QWidget>

#include "mainwindow.h"
#include "settingsdialog.h"




class MPU9250
{

public:
    MPU9250();
/*
    typedef struct inputData
    {
        //Time stamp from Arduino
        quint32 curTime;

        //Accelerometr data
        quint16 accX;
        quint16 accY;
        quint16 accZ;

        //Gyroscope data
        quint16 gyroX;
        quint16 gyroY;
        quint16 gyroZ;

        //Magnetometer data
        quint16 magX;
        quint16 magY;
        quint16 magZ;

    }inputData;

    bool getNewData;

    QVector<inputData> dataVector;

    QString curDataString;

    QByteArray dataBytes;

    QSerialPort *curPort;

    void setSerialPort(QSerialPort *mainProgPort);

    void startMpu9250();

    void readData_9250();

    void setCollectDataOn();
    void setCollectDataOff();

protected:
        bool collectData;
*/
};

#endif // MPU9250_H

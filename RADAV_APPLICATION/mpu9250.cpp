#include "mpu9250.h"

MPU9250::MPU9250()
{
    //collectData = false;
    //getNewData = true;
}
/*
void MPU9250::setSerialPort(QSerialPort *mainProgPort)
{
    curPort = mainProgPort;
}

void MPU9250::startMpu9250()
{
    readData_9250();

    //Now the curString should have the data received from the sensors
    for(int i = 0; i < curDataString.size(); i++)
    {
        if(getNewData == true)
        {
            //Make sure we start parsing at the beggining of a dataset
            while(curDataString.at(i) != (char)'a')
            {
                //Find the start char of the signal denoted by an 'a'
                i++;
            }

            getNewData = false;
        }
        else
        {
            i += 2;
            inputData curData;

            curData.curTime = dataBytes.at(i);
            i+= 2;
            curData.accX = dataBytes.at(i);
            i+= 2;
            curData.accY = dataBytes.at(i);
            i+= 2;
            curData.accZ = dataBytes.at(i);

            i+= 2;
            curData.gyroX = dataBytes.at(i);
            i+= 2;
            curData.gyroY = dataBytes.at(i);
            i+= 2;
            curData.gyroZ = dataBytes.at(i);
            i+= 2;

            curData.magX = dataBytes.at(i);
            i+= 2;
            curData.magY = dataBytes.at(i);
            i+=2;
            curData.magZ = dataBytes.at(i);

            getNewData = true;

            dataVector.push_back(curData);
        }


    }

}

void MPU9250::readData_9250()
{
    if(curPort->open(QIODevice::ReadWrite))
    {
        QByteArray data9250 = curPort->readAll();

        QString curData(data9250);

        dataBytes = data9250;

        curDataString = curData;
    }
}

void MPU9250::setCollectDataOn()
{
    collectData = true;
}

void MPU9250::setCollectDataOff()
{
    collectData = false;
}
*/

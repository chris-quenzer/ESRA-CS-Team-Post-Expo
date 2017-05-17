#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#define SENSOR 1
#define FFILE 2

#include <QStringList>

typedef struct inputData
{
    /********************************
    *  Start MPU-9250 High-G Accel  *
    *********************************/
    //Time stamp from GPS 4 bytes max
    QString curTime;
    //QString curTimeString;

    //All values are 2 Bytes

    //Accelerometr data
    QString accX;
    QString accY;
    QString accZ;

    //Gyroscope data
    QString gyroX;
    QString gyroY;
    QString gyroZ;

    //Magnetometer data
    QString magX;
    QString magY;
    QString magZ;

    /********************************
    *    End MPU-9250 Low-G Accel   *
    *********************************/

    /********************************
    * Start H3LIS 200DL High-G Accel*
    *********************************/

    //All values are 1 Byte

    //Accelerometr data
    QString accXH;
    QString accYH;
    QString accZH;

    //Gyroscope data
    QString gyroXH;
    QString gyroYH;
    QString gyroZH;

    //Magnetometer data
    QString magXH;
    QString magYH;
    QString magZH;

    /********************************
    *  End H3LIS 200DL High-G Accel *
    *********************************/

    /********************************
    * Start MS5611 High Res Altimeter*
    *********************************/

    //3 Byte value representing Altitude
    QString altitude;

    /********************************
    * End MS5611 High Res Altimeter*
    *********************************/

    /********************************
    *      Start MAX - M8 GPS       *
    *********************************/

    QString latitude;       //4 Bytes
    QString longitude;      //4 Bytes
    QString altGPS;         //4 Bytes
    //QString timeGPS;        //4 Bytes

    /********************************
    *       End MAX - M8 GPS        *
    *********************************/

    //Addition of battery fuel guage
    //Maybe more fields.

}inputData;

class DataProcessing
{
public:



    DataProcessing();
    double NextTime();
    double NextXGyro();
    double NextYGyro();
    double NextZGyro();

    double NextXAccel();
    double NextYAccel();
    double NextZAccel();

    void importFile_csv();
    void clear_data();

    int ReadFromCSV();
    int WriteToCSV();
    void receiveDataVector(QVector<inputData>*);


    int count = 0;
    int count1 = 0;
    QStringList m_xGyro;
    QStringList m_yGyro;
    QStringList m_zGyro;

    QStringList m_xAccel;
    QStringList m_yAccel;
    QStringList m_zAccel;

    QStringList m_xMag;
    QStringList m_yMag;
    QStringList m_zMag;

    //Low-G accelerometer  Added 3/3/2017 Alex Wood

    QStringList m_xHGyro;
    QStringList m_yHGyro;
    QStringList m_zHGyro;

    QStringList m_xHAccel;
    QStringList m_yHAccel;
    QStringList m_zHAccel;

    QStringList m_xHMag;
    QStringList m_yHMag;
    QStringList m_zHMag;

    //Altimeter Values     Added 3/3/2017 Alex Wood

    QStringList m_Altimeter;

    //GPS Data             Added 3/3/2017 Alex Wood
    QStringList m_latGPS;
    QStringList m_longGPS;
    QStringList m_timeGPS;
    QStringList m_AltimeterGPS;

    QVector<inputData>* m_inputDataVector;
    //inputData m_inputDataVector;

    QString path = "";
    QString browse_dir = "C://";
    double NextDataPoint(QStringList list);
};

#endif // DATAPROCESSING_H
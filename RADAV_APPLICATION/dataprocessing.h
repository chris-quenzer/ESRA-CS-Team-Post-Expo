#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#define SENSOR 1
#define FFILE 0

#include <QStringList>


/*enums for the possible data we could receive,
 *matched with its position in the data stream that in arrives in
 */
enum Attribute {
GPS_TIME,
X_GYRO,
Y_GYRO,
Z_GYRO,
X_ACCEL,
Y_ACCEL,
Z_ACCEL,
X_MAG,
Y_MAG,
Z_MAG,
X_HGYRO,
Y_HGYRO,
Z_HGYRO,
X_HACCEL,
Y_HACCEL,
Z_HACCEL,
X_HMAG,
Y_HMAG,
Z_HMAG,
ALTITUDE,
GPS_LAT,
GPS_LONG,
ALTITUDE_GPS,
HUMAN_LAT,
LAT_DEG,
LAT_MIN,
HUMAN_LON,
LON_DEG,
LON_MIN,
VEL_LAT_DEG,
VEL_LAT_MIN,
VEL_LON_DEG,
VEL_LON_MIN
};

struct baseAltitudeInfo
{
    double baseHeight;              //Altitude at launch site in Feet
    double baseTemp;                //Ground temperature in Kelvin
    double basePressure;            //Avg base pressure in milli-bars
};

typedef struct inputData
{
    /********************************
    *  Start MPU-9250 High-G Accel  *
    *********************************/
    //Old Time string value, real time from GPS
    QString curTime;

    //All values are 2 Bytes

    //Accelerometr data
    QString accX;
    quint16 intAccX;
    QString accY;
    quint16 intAccY;
    QString accZ;
    quint16 intAccZ;
    double scaledAccX;          //Added for outputting scaled values 5/10/17
    double scaledAccY;          //Added for outputting scaled values 5/10/17
    double scaledAccZ;          //Added for outputting scaled values 5/10/17

    double scaledHAccX;
    double scaledHAccY;
    double scaledHAccZ;

    //Gyroscope data
    QString gyroX;
    quint16 intGyroX;
    QString gyroY;
    quint16 intGyroY;
    QString gyroZ;
    quint16 intGyroZ;
    double scaledGyroX;          //Added for outputting scaled values 5/10/17
    double scaledGyroY;          //Added for outputting scaled values 5/10/17
    double scaledGyroZ;          //Added for outputting scaled values 5/10/17

    //Magnetometer data
    QString magX;
    quint16 intMagX;
    QString magY;
    quint16 intMagY;
    QString magZ;
    quint16 intMagZ;
    double scaledMagX;          //Added for outputting scaled values 5/10/17
    double scaledMagY;          //Added for outputting scaled values 5/10/17
    double scaledMagZ;          //Added for outputting scaled values 5/10/17

    /********************************
    *    End MPU-9250 Low-G Accel   *
    *********************************/

    /********************************
    * Start H3LIS 200DL High-G Accel*
    *********************************/

    //All values are 1 Byte

    //Accelerometr data
    QString accXH;
    quint8 intAccXH;
    QString accYH;
    quint8 intAccYH;
    QString accZH;
    quint8 intAccZH;


    //Gyroscope data        *** This value not needed ***
    QString gyroXH;
    QString gyroYH;
    QString gyroZH;

    //Magnetometer data     *** This value not needed ***
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
    quint32 intAltitude;

    /********************************
    * End MS5611 High Res Altimeter*
    *********************************/

    /********************************
    *      Start MAX - M8 GPS       *
    *********************************/

    QString latitude;           //4 Bytes
    QString humanLat;           //
    quint32 intGpsLat;
    bool southHemi;
    int latDegrees;
    double latMins;

    QString longitude;          //4 Bytes
    QString humanLon;
    quint32 intGpsLon;
    bool eastHemi;              //True = east hemispher fales = west hemisphere
    int lonDegrees;             //Integer degree value
    double lonMins;             //double minutes and fraction of minutes for lat

    QString altGPSMeter;        //4 Bytes
    QString altGPSFeet;         //4 Bytes
    quint32 intGpsAlt;          //In meters
    double gpsAltFeet;          //Converted to feet in setGpsAlt()

    quint32 intGpsTime;
    QString curTimeString;

    /********************************
    *       End MAX - M8 GPS        *
    *********************************/

    //Addition of battery fuel guage
    //Maybe more fields.

}inputData;


struct sensorData{
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
QStringList m_time;
QStringList m_AltimeterGPS;

QStringList m_humanLat;
QStringList m_latDegrees;
QStringList m_latMins;
QStringList m_humanLon;
QStringList m_lonDegrees;
QStringList m_lonMins;

QStringList m_latDegreesVel;
QStringList m_latMinsVel;
QStringList m_lonDegreesVel;
QStringList m_lonMinsVel;


};


class DataProcessing
{
public:

    DataProcessing();

    void importFile_csv();
    void clear_data();

    int ReadFromCSV();
    int WriteToCSV(QString);
    void setProfilePath(QString);
    void setWriteCSV(bool);

    //General functions for getting attributes from a specific source
    double getAttributeFromSource(int source, Attribute a, int pop);
    double nextDataPoint(sensorData &sourceData, Attribute a, int pop);
    double getNextValue(QStringList &attribute, int pop);
    double getNextAltitude(int source, Attribute alt, struct baseAltitudeInfo altInfo);
    double getNextVelocity(int source, double delta_time, double alt1, double alt2);
    double getAccelerationMagnitude();
    double getGForce(int source, int isLow);

    double calculateDistance(int source);

    void receiveDataVector(QVector<inputData>*, bool, QString);

    bool isValidCoord(double latDeg, double latMin, double lonDeg, double lonMin);

    int count = 0;
    int count1 = 0;
    double g_force = 0;

    QVector<inputData>* m_inputDataVector;
    QVector<inputData>* m_convertedDataVector;

    //We have 2 possible sources of data, either from a sensor on the 'rocket', or a csv file
    sensorData csvData;
    sensorData rocketData;
    int source = SENSOR;
    //inputData m_inputDataVector;

    QString path = "";
    QString browse_dir = "C://";
    QString newFilePath;
    double NextDataPoint(QStringList list);

    double prevVel = 0;
    double accel_mag = 0;

    double altInit = 0;

    bool demo;

    bool firstPressure = false;
    double seaLvlAlt;
};

#endif // DATAPROCESSING_H

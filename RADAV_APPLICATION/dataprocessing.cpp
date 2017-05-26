#include "dataprocessing.h"
#include "mainwindow.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QCoreApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QtMath>

DataProcessing::DataProcessing()
{
    m_inputDataVector = nullptr;
    //ReadFromCSV();

}


/*************************************************************************
 * Function: ReadFromCSV
 * Description: Reads CSv file and splices input into indiviual lists of each attribute based on a
 * pre-determined ordering
 * Output: 0 if error reading the file
 *
 * **********************************************************************/
int DataProcessing::ReadFromCSV(){

    if(path != "")
    {
        QFile csv(path);

        if (!csv.exists()) {
            qDebug() << "File does not exist!";
            QMessageBox::critical(NULL, "Error!", "Error reading file");
            return 0;
        }
        if(!csv.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << csv.errorString();
            return 0;
        }

        count = 0;

        while (!csv.atEnd()) {
            QByteArray line = csv.readLine();

           csvData.m_xGyro.push_back(line.split(',').value(X_GYRO - 1));
           csvData.m_yGyro.push_back(line.split(',').value(Y_GYRO - 1));
           csvData.m_zGyro.push_back(line.split(',').value(Z_GYRO - 1));

           csvData.m_xAccel.push_back(line.split(',').value(X_ACCEL - 1));
           csvData.m_yAccel.push_back(line.split(',').value(Y_ACCEL - 1));
           csvData.m_zAccel.push_back(line.split(',').value(Z_ACCEL - 1));

           csvData.m_xMag.push_back(line.split(',').value(X_MAG - 1));
           csvData.m_yMag.push_back(line.split(',').value(Y_MAG - 1));
           csvData.m_zMag.push_back(line.split(',').value(Z_MAG - 1));

           csvData.m_xHGyro.push_back(line.split(',').value(X_HGYRO - 1));
           csvData.m_yHGyro.push_back(line.split(',').value(Y_HGYRO - 1));
           csvData.m_zHGyro.push_back(line.split(',').value(Z_HGYRO - 1));

           csvData.m_xHAccel.push_back(line.split(',').value(X_HACCEL - 1));
           csvData.m_yHAccel.push_back(line.split(',').value(Y_HACCEL - 1));
           csvData.m_zHAccel.push_back(line.split(',').value(Z_HACCEL - 1));

           csvData.m_xHMag.push_back(line.split(',').value(X_HMAG - 1));
           csvData.m_yHMag.push_back(line.split(',').value(Y_HMAG - 1));
           csvData.m_zHMag.push_back(line.split(',').value(Z_HMAG - 1));

           csvData.m_Altimeter.push_back(line.split(',').value(ALTITUDE - 1));

           QString latDeg = line.split(',').value(LAT_DEG - 1);
           QString lonDeg = line.split(',').value(LON_DEG - 1);
           QString latMin = line.split(',').value(LAT_MIN - 1);
           QString lonMin = line.split(',').value(LON_MIN - 1);

           if(isValidCoord(latDeg.toDouble(), latMin.toDouble(), lonDeg.toDouble(), lonMin.toDouble()))
           {
               csvData.m_timeGPS.push_back(line.split(',').value(GPS_TIME));
               csvData.m_AltimeterGPS.push_back(line.split(',').value(ALTITUDE_GPS - 1));

               csvData.m_latGPS.push_back(line.split(',').value(GPS_LAT - 1));
               csvData.m_longGPS.push_back(line.split(',').value(GPS_LONG - 1));

               csvData.m_humanLat.push_back(line.split(',').value(HUMAN_LAT - 1));
               csvData.m_humanLon.push_back(line.split(',').value(HUMAN_LON - 1));

               csvData.m_latDegrees.push_back(line.split(',').value(LAT_DEG - 1));
               csvData.m_latMins.push_back(line.split(',').value(LAT_MIN - 1));
               csvData.m_lonDegrees.push_back(line.split(',').value(LON_DEG - 1));
               csvData.m_lonMins.push_back(line.split(',').value(LON_MIN - 1));

               csvData.m_latDegreesVel.push_back(line.split(',').value(LAT_DEG - 1));
               csvData.m_latMinsVel.push_back(line.split(',').value(LAT_MIN - 1));
               csvData.m_lonDegreesVel.push_back(line.split(',').value(LON_DEG - 1));
               csvData.m_lonMinsVel.push_back(line.split(',').value(LON_MIN - 1));
           }
           else
           {
               csvData.m_timeGPS.push_back("GPS ERROR");
               csvData.m_AltimeterGPS.push_back("GPS ERROR");

               csvData.m_latGPS.push_back("GPS ERROR");
               csvData.m_longGPS.push_back("GPS ERROR");

               csvData.m_humanLat.push_back("GPS ERROR");
               csvData.m_humanLon.push_back("GPS ERROR");

               csvData.m_latDegrees.push_back("GPS ERROR");
               csvData.m_latMins.push_back("GPS ERROR");
               csvData.m_latDegreesVel.push_back("GPS ERROR");
               csvData.m_latMinsVel.push_back("GPS ERROR");

               csvData.m_lonDegrees.push_back("GPS ERROR");
               csvData.m_lonMins.push_back("GPS ERROR");
               csvData.m_lonDegreesVel.push_back("GPS ERROR");
               csvData.m_lonMinsVel.push_back("GPS ERROR");
           }

        }

        //qDebug() << "LENGTH AFTER IMPORT: " << csvData.m_xGyro.length();
    }

    if(demo)
    {
        rocketData = csvData;
    }

    return 1;
}

/*************************************************************************
 * Function: WriteToCSV
 * Description: Writes sensor/rocket data to csv, data values are written to csv in predefined order
 * OutPut: returns 1 if error
 *
 * **********************************************************************/

int DataProcessing::WriteToCSV(QString writePath)
{
        QDateTime fileDate;
        QString writeFile = writePath + "/inputData" + fileDate.currentDateTime().toString("dd.MM.yyyy") + ".csv";

        QFile csv(writeFile);

       /* if (!csv.exists()) {
            qDebug() << "File does not exist!";
            QMessageBox::critical(NULL, "Error!", "Error reading file");
            return 0;
        }*/
        if(!csv.open(QFile::Append | QFile::Text))
        {
            qDebug() << csv.errorString();
            return 0;
        }
        QTextStream csvStream( &csv );

        for(int i = 0; i < m_inputDataVector->size(); i++)
        {
             inputData tmpData = m_inputDataVector->at(i);
             csvStream << tmpData.curTime << "," << tmpData.gyroX << "," << tmpData.gyroY << "," << tmpData.gyroZ
                       << "," << tmpData.accX << "," << tmpData.accY << "," << tmpData.accZ
                       << "," << tmpData.magX << "," << tmpData.magY << "," << tmpData.magZ
                       << "," << tmpData.gyroXH << "," << tmpData.gyroYH << "," << tmpData.gyroZH
                       << "," << tmpData.accXH << "," << tmpData.accYH << "," << tmpData.accZH
                       << "," << tmpData.magXH << "," << tmpData.magYH << "," << tmpData.magZH
                       << "," << tmpData.altitude << "," << tmpData.latitude << "," << tmpData.longitude
                       << "," << tmpData.altGPSMeter << "," << tmpData.humanLat << "," << QString::number(tmpData.latDegrees)
                       << "," << QString::number(tmpData.latMins) << "," << tmpData.humanLon << "," << QString::number(tmpData.lonDegrees)
                       << "," << QString::number(tmpData.lonMins) <<endl;
        //Edited this function Alex Wood 3/3/2017
             //Edited again tmpData.altGPS to tmpData.altGPSMeter for data struct changes
        }
        csv.close();


    return 1;
}

/****************************************************************
 * Function: receiveDataVector
 * Description: gets dataVector and adds values to dataprocessing's
 * own set of lists that manage the data, used for getting data from a sensor
 * Input: vector of inputData
 * Output: none
 * Changes: rocketData's stringlists should be filled if tmpData has at least one element
 * *************************************************************/
void DataProcessing::receiveDataVector(QVector<inputData>* tmpData, bool writeCSV, QString writePath)
{
    m_inputDataVector = tmpData;

    if (writeCSV)
    {
        WriteToCSV(writePath);
    }

    // write processed values to new .CSV

    while(m_inputDataVector->size() > 0)
    {
        inputData tmpData = m_inputDataVector->front();

        //tmpData.altitude.toStdString() = (1 - (qPow((tmpData.altitude.toDouble() / 100) / 1013.25, 0.190284) * 145366.45)) - altInit; // (- baseAlt)

        m_inputDataVector->pop_front();
        rocketData.m_xGyro.append(tmpData.gyroX);
        rocketData.m_yGyro.append(tmpData.gyroY);
        rocketData.m_zGyro.append(tmpData.gyroZ);
        rocketData.m_xAccel.append(tmpData.accX);
        rocketData.m_yAccel.append(tmpData.accY);
        rocketData.m_zAccel.append(tmpData.accZ);
        rocketData.m_xMag.append(tmpData.magX);
        rocketData.m_yMag.append(tmpData.magY);
        rocketData.m_zMag.append(tmpData.magZ);

        rocketData.m_xHGyro.append(tmpData.gyroXH);
        rocketData.m_yHGyro.append(tmpData.gyroYH);
        rocketData.m_zHGyro.append(tmpData.gyroZH);
        rocketData.m_xHAccel.append(tmpData.accXH);
        rocketData.m_yHAccel.append(tmpData.accYH);
        rocketData.m_zHAccel.append(tmpData.accZH);
        rocketData.m_xHMag.append(tmpData.magXH);
        rocketData.m_yHMag.append(tmpData.magYH);
        rocketData.m_zHMag.append(tmpData.magZH);

        rocketData.m_Altimeter.append(tmpData.altitude);
        rocketData.m_time.append(tmpData.curTime);

        int latDeg = tmpData.latDegrees;
        int lonDeg = tmpData.lonDegrees;
        double latMin = tmpData.latMins;
        double lonMin = tmpData.lonMins;

        if(isValidCoord(latDeg, latMin, lonDeg, lonMin))
        {
            rocketData.m_timeGPS.append(tmpData.curTimeString);
            rocketData.m_AltimeterGPS.append(tmpData.altGPSMeter);

            rocketData.m_latGPS.append(tmpData.latitude);
            rocketData.m_longGPS.append(tmpData.longitude);

            rocketData.m_humanLat.append(tmpData.humanLat);
            rocketData.m_humanLon.append(tmpData.humanLon);

            rocketData.m_latDegrees.append(QString::number(tmpData.latDegrees));
            rocketData.m_latMins.append(QString::number(tmpData.latMins));
            rocketData.m_lonDegrees.append(QString::number(tmpData.lonDegrees));
            rocketData.m_lonMins.append(QString::number(tmpData.lonMins));

            rocketData.m_lonDegreesVel.append(QString::number(tmpData.lonDegrees));
            rocketData.m_lonMinsVel.append(QString::number(tmpData.lonMins));
            rocketData.m_latDegreesVel.append(QString::number(tmpData.latDegrees));
            rocketData.m_latMinsVel.append(QString::number(tmpData.latMins));
        }
        else
        {
            rocketData.m_timeGPS.push_back("GPS ERROR");
            rocketData.m_AltimeterGPS.push_back("GPS ERROR");

            rocketData.m_latGPS.push_back("GPS ERROR");
            rocketData.m_longGPS.push_back("GPS ERROR");

            rocketData.m_humanLat.push_back("GPS ERROR");
            rocketData.m_humanLon.push_back("GPS ERROR");

            rocketData.m_latDegrees.push_back("GPS ERROR");
            rocketData.m_latMins.push_back("GPS ERROR");
            rocketData.m_latDegreesVel.push_back("GPS ERROR");
            rocketData.m_latMinsVel.push_back("GPS ERROR");

            rocketData.m_lonDegrees.push_back("GPS ERROR");
            rocketData.m_lonMins.push_back("GPS ERROR");
            rocketData.m_lonDegreesVel.push_back("GPS ERROR");
            rocketData.m_lonMinsVel.push_back("GPS ERROR");
        }

    }    

    if(demo)
    {
        rocketData = csvData;
    }

}

/****************************************************************
 * Function: calculateDistance
 * Description: Calculates distance between two gps coordinates (using latitude and longitude)
 * Input: source to get lat and long from (ie. file or sensor)
 * Output: distance between the two points in feet
 * Other: This algorithm was developed by: http://www.ridgesolutions.ie/index.php/2013/11/14/
 * algorithm-to-calculate-speed-from-two-gps-latitude-and-longitude-points-and-time-difference/
 * Found on March 6th 2017 by Natalie Suderman
 * *************************************************************/
double DataProcessing::calculateDistance(int source)
{
   /*double lat1 = getAttributeFromSource(source, VEL_LAT_DEG, 1);
   double lon1 = getAttributeFromSource(source, VEL_LON_DEG, 1);

   lat1 += getAttributeFromSource(source, VEL_LAT_MIN, 1);
   lon1 += getAttributeFromSource(source, VEL_LON_MIN, 1);

   double lat2 = getAttributeFromSource(source, VEL_LAT_DEG, 1);
   double lon2 = getAttributeFromSource(source, VEL_LON_DEG, 1);

   lat2 += getAttributeFromSource(source, VEL_LAT_MIN, 1);
   lon2 += getAttributeFromSource(source, VEL_LON_MIN, 1);

    // Convert degrees to radians
    lat1 = lat1 * M_PI / 180.0;
    lon1 = lon1 * M_PI / 180.0;

    lat2 = lat2 * M_PI / 180.0;
    lon2 = lon2 * M_PI / 180.0;

    // radius of earth in metres
    double r = 6378100;

    // P
    double rho1 = r * cos(lat1);
    double z1 = r * sin(lat1);
    double x1 = rho1 * cos(lon1);
    double y1 = rho1 * sin(lon1);

    // Q
    double rho2 = r * cos(lat2);
    double z2 = r * sin(lat2);
    double x2 = rho2 * cos(lon2);
    double y2 = rho2 * sin(lon2);

    // Dot product
    double dot = (x1 * x2 + y1 * y2 + z1 * z2);
    double cos_theta = dot / (r * r);

    //qDebug() << "DOT" << dot << "x y z " << x1 << y1 << z1 << "x y z 2" << x2 << y2 << z2 << endl;

    double theta = acos(cos_theta);

    //qDebug() << "THETA" << theta << "R " << r << endl;

    return r * theta;*/
return 0;

}

/************************************************
 * Function: getNextVelocity
 * Description: calculates velocity using distance traveled over time elapsed
 * Input: Source to get time, lat, and long coordinates from ie. a file or a sensor
 * Output: velocity in feet per second as a double value
 * **********************************************/
double DataProcessing::getNextVelocity(int source, double delta_time, double alt1, double alt2)
{
  //double dist = calculateDistance(source);
  //qDebug() << "DISTANCE " << dist << endl;
  //double time_s = getAttributeFromSource(source, GPS_TIME, 1);
  //qDebug() << "TIME " << time_s << endl;
  //qDebug() << "Velocity Calculated " << dist / time_s << endl;

  //double curVel = prevVel + accel_mag * delta_time;

  double curVel = alt2 - alt1;

  return curVel;
}

/****************************************************************
 * Function: Get Next Altitude
 * Description: Calculates altitude based on pressure data received from sensor, using the barometric formula
 * Inputs: source to get data from, barometric formula info including an initial temp, pressure and altitude
 * Output: Height/Altitude in feet (as a double)
 *
 * **************************************************************/
double DataProcessing::getNextAltitude(int source, Attribute alt, struct baseAltitudeInfo altInfo)
{
   double nextPressure = getAttributeFromSource(source, alt, 1);

   double feetHeight = ((1 - qPow(((nextPressure/100) / 1012.25),0.190284)) * 145366.45) - altInfo.baseHeight;
   return feetHeight;
}

double DataProcessing::getGForce(int source, int isLow)
{
    double accel_X;
    double accel_Y;
    double accel_Z;

    if(isLow)
    {
        accel_X = getAttributeFromSource(source, X_ACCEL, 1);
        accel_Y = getAttributeFromSource(source, Y_ACCEL, 1);
        accel_Z = getAttributeFromSource(source, Z_ACCEL, 1);
    }
    else
    {
        accel_X = getAttributeFromSource(source, X_HACCEL, 1);
        accel_Y = getAttributeFromSource(source, Y_HACCEL, 1);
        accel_Z = getAttributeFromSource(source, Z_HACCEL, 1);
    }

    g_force = sqrt((accel_X*accel_X) + (accel_Y*accel_Y) + (accel_Z*accel_Z)); // |a| = sqrt(ax^2 + ay^2 + az^2)

    return g_force;
}

double DataProcessing::getAccelerationMagnitude()
{
    bool metric = false; //outputs ft/s^2 in imperial mode

    double G0m = 9.80665; //Gravitational Acceleration m/s^2
    double G0i = 32.174; //Gravitational Acceleration  ft/s^2

    if(metric)
    {
        accel_mag = g_force * G0m;
    }
    else
    {
        accel_mag = g_force * G0i;
    }


    return accel_mag;
}

/***************************************************8
 * Function: getAttributeFromSource
 * Description: gets value of attribute from specified source
 * Input: 1 for rocket 0 for csv file, and a MACRO of the desired attribute
 * Output: the nextValue in the attribute's list
 * **************************************************/
double DataProcessing::getAttributeFromSource(int source, Attribute a, int pop)
{
    if (source)
        return nextDataPoint(rocketData, a, pop);
    else
        return nextDataPoint(csvData, a, pop);
}

/***********************************************************************************************
 * Function: nextDatapoint
 * Description: returns double value from nextValue function based on attribute desired
 * Input: struct of data from either a csv or the rocket and the attribute you want to retrieve
 * Output: the next value of the specified attribute
 *
 * **********************************************************************************************/
double DataProcessing::nextDataPoint(sensorData &sourceData, Attribute a, int pop)
{
    double nextValue;

    switch(a)
    {
        case (X_GYRO):
        {
            nextValue = getNextValue(sourceData.m_xGyro, pop);
            break;
        }
        case (Y_GYRO):
        {
            nextValue = getNextValue(sourceData.m_yGyro, pop);
            break;
        }
        case (Z_GYRO):
        {
            nextValue = getNextValue(sourceData.m_zGyro, pop);
            break;
        }
        case (X_MAG):
        {
            nextValue = getNextValue(sourceData.m_xMag, pop);
            break;
        }
        case (Y_MAG):
        {
            nextValue = getNextValue(sourceData.m_yMag, pop);
            break;
        }
        case (Z_MAG):
        {
            nextValue = getNextValue(sourceData.m_zMag, pop);
            break;
        }
        case (X_ACCEL):
        {
            nextValue = getNextValue(sourceData.m_xAccel, pop);
            break;
        }
        case (Y_ACCEL):
        {
            nextValue = getNextValue(sourceData.m_yAccel, pop);
            break;
        }
        case (Z_ACCEL):
        {
            nextValue = getNextValue(sourceData.m_zAccel, pop);
            break;
        }

        case (X_HGYRO):
        {
            nextValue = getNextValue(sourceData.m_xHGyro, pop);
            break;
        }
        case (Y_HGYRO):
        {
            nextValue = getNextValue(sourceData.m_yHGyro, pop);
            break;
        }
        case (Z_HGYRO):
        {
            nextValue = getNextValue(sourceData.m_zHGyro, pop);
            break;
        }
        case (X_HMAG):
        {
            nextValue = getNextValue(sourceData.m_xHMag, pop);
            break;
        }
        case (Y_HMAG):
        {
            nextValue = getNextValue(sourceData.m_yHMag, pop);
            break;
        }
        case (Z_HMAG):
        {
            nextValue = getNextValue(sourceData.m_zHMag, pop);
            break;
        }
        case (X_HACCEL):
        {
            nextValue = getNextValue(sourceData.m_xHAccel, pop);
            break;
        }
        case (Y_HACCEL):
        {
            nextValue = getNextValue(sourceData.m_yHAccel, pop);
            break;
        }
        case (Z_HACCEL):
        {
            nextValue = getNextValue(sourceData.m_zHAccel, pop);
            break;
        }
        case (GPS_LAT):
        {
            nextValue = getNextValue(sourceData.m_latGPS, pop);
            break;
        }
        case (GPS_LONG):
        {
            nextValue = getNextValue(sourceData.m_longGPS, pop);
            break;
        }
        case (GPS_TIME):
        {
            nextValue = getNextValue(sourceData.m_timeGPS, pop);

            break;
        }

        case (ALTITUDE):
        {
            nextValue = getNextValue(sourceData.m_Altimeter, pop);
            break;
        }
        case (ALTITUDE_GPS):
        {
            nextValue = getNextValue(sourceData.m_AltimeterGPS, pop);
            break;
        }
        case (LON_DEG):
        {
            nextValue = getNextValue(sourceData.m_lonDegrees, pop);
            break;
        }
        case (LON_MIN):
        {
            nextValue = getNextValue(sourceData.m_lonMins, pop);
            break;
        }
        case (LAT_MIN):
        {
            nextValue = getNextValue(sourceData.m_latMins, pop);
            break;
        }
        case (LAT_DEG):
        {
            nextValue = getNextValue(sourceData.m_latDegrees, pop);
            break;
        }
        case (VEL_LON_DEG):
        {
            nextValue = getNextValue(sourceData.m_lonDegreesVel, pop);
            break;
        }
        case (VEL_LON_MIN):
        {
            nextValue = getNextValue(sourceData.m_lonMinsVel, pop);
            break;
        }
        case (VEL_LAT_MIN):
        {
            nextValue = getNextValue(sourceData.m_latMinsVel, pop);
            break;
        }
        case (VEL_LAT_DEG):
        {
            nextValue = getNextValue(sourceData.m_latDegreesVel, pop);
            break;
        }
    }
    return nextValue;
}


/***********************************************************************************************
 * Function: getNextValue
 * Description: returns double value from attribute desired and pops value from the list
 * Input: list of the attribute you want the next value of
 * Output: the next value of the specified attribute
 *
 * **********************************************************************************************/
double DataProcessing::getNextValue(QStringList & attribute, int pop)
{
    double nextValue;
    QString nextString;

    if(attribute.length() > 0)
    {
        nextString = attribute.at(0);

        if(nextString == "GPS ERROR")
        {
            if (pop)
                attribute.removeAt(0);
            return 1000;
        }

        nextValue = nextString.toDouble();
       // qDebug() << nextValue;
        if (pop)
            attribute.removeAt(0);
    }
    else
    {
        nextValue = nan("");
    }
    return nextValue;
}


/************************************************************
 * Function: importFile_csv()
 * Description: loads csv file
 *
 * **********************************************************/
void DataProcessing::importFile_csv()
{
    QString file = QFileDialog::getOpenFileName(
                NULL,
                "Import CSV File",
                browse_dir,
                "All files (*.*);;CSV (*.csv)"
                );

    //file = "E:/GitHub/ESRA-CS-Team/BaseApplication/AlphaBuild/TestApplication/accel-Data.csv"; //debugging

    browse_dir = file; //remember where the user last navigated to in file explorer (default C:\\)

    if(file != "")
    {
        QMessageBox::information(NULL, "File Name", file);
        path = file;

        QFile csv(path);

        QFileInfo fileInfo(csv.fileName());
        QString filename(fileInfo.fileName()); //extract .csv file name from import path
        //qDebug() << "Filename: " << filename;

        QString copy_path = "Files/csv/";
        copy_path.append(filename);
        //qDebug() << "Copy file path is: " << copy_path;

        if(!QDir("Files/csv").exists()) //check if csv dir exists
        {
            //qDebug() << "Directory created!";
            QDir().mkpath("Files/csv"); //create dir if it doesn't
        }

        if(QFile(copy_path).exists())
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(NULL, "File Import", "This file already exists. \nOverwrite?", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes)
            {
                QFile::remove(copy_path); //delete old file
                QFile::copy(path, copy_path); //copy new one
                //qDebug() << "Copy file with question";
            }
        }
        else
        {
            QFile::copy(path, copy_path); //move the file to application dir
            //qDebug() << "Copy file without question";
        }

        path = copy_path; //set application read path to new file location
        clear_data();
        ReadFromCSV();
    }
}

void DataProcessing::clear_data()
{
    csvData.m_xGyro.clear();
   csvData.m_yGyro.clear();
   csvData.m_zGyro.clear();
   csvData.m_xAccel.clear();
   csvData.m_yAccel.clear();
   csvData.m_zAccel.clear();

    //qDebug() << "LENGTH AFTER CLEAR: " << csvData.m_xGyro.length();
}

bool DataProcessing::isValidCoord(double latDeg, double latMin, double lonDeg, double lonMin)
{
    int condCount = 0;
    if(latDeg >= -90 && latDeg <= 90 && latDeg)
    {
        condCount++;
    }
    if(lonDeg >= -180 && lonDeg <= 180 && lonDeg)
    {
        condCount++;
    }
    if(latMin < 60 && lonMin < 60 && latMin != nan("") && lonMin)
    {
        condCount++;
    }
    if(condCount == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}



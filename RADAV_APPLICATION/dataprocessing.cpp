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
    ReadFromCSV();

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
           csvData.m_timeGPS.push_back(line.split(',').value(GPS_TIME));

           csvData.m_xGyro.push_back(line.split(',').value(X_GYRO));
           csvData.m_yGyro.push_back(line.split(',').value(Y_GYRO));
           csvData.m_zGyro.push_back(line.split(',').value(Z_GYRO));

           csvData.m_xAccel.push_back(line.split(',').value(X_ACCEL));
           csvData.m_yAccel.push_back(line.split(',').value(Y_ACCEL));
           csvData.m_zAccel.push_back(line.split(',').value(Z_ACCEL));

           csvData.m_xMag.push_back(line.split(',').value(X_MAG));
           csvData.m_yMag.push_back(line.split(',').value(Y_MAG));
           csvData.m_zMag.push_back(line.split(',').value(Z_MAG));

           csvData.m_xHGyro.push_back(line.split(',').value(X_HGYRO));
           csvData.m_yHGyro.push_back(line.split(',').value(Y_HGYRO));
           csvData.m_zHGyro.push_back(line.split(',').value(Z_HGYRO));

           csvData.m_xHAccel.push_back(line.split(',').value(X_HACCEL));
           csvData.m_yHAccel.push_back(line.split(',').value(Y_HACCEL));
           csvData.m_zHAccel.push_back(line.split(',').value(Z_HACCEL));

           csvData.m_xHMag.push_back(line.split(',').value(X_HMAG));
           csvData.m_yHMag.push_back(line.split(',').value(Y_HMAG));
           csvData.m_zHMag.push_back(line.split(',').value(Z_HMAG));

           csvData.m_Altimeter.push_back(line.split(',').value(ALTITUDE));
           csvData.m_latGPS.push_back(line.split(',').value(GPS_LAT));
           csvData.m_longGPS.push_back(line.split(',').value(GPS_LONG));

           csvData.m_AltimeterGPS.push_back(line.split(',').value(ALTITUDE_GPS));

           csvData.m_humanLat.push_back(line.split(',').value(HUMAN_LAT));
           csvData.m_latDegrees.push_back(line.split(',').value(LAT_DEG));
           csvData.m_latMins.push_back(line.split(',').value(LAT_MIN));
           csvData.m_latDegreesVel.push_back(line.split(',').value(LAT_DEG));
           csvData.m_latMinsVel.push_back(line.split(',').value(LAT_MIN));

           csvData.m_humanLon.push_back(line.split(',').value(HUMAN_LON));
           csvData.m_lonDegrees.push_back(line.split(',').value(LON_DEG));
           csvData.m_lonMins.push_back(line.split(',').value(LON_MIN));
           csvData.m_lonDegreesVel.push_back(line.split(',').value(LON_DEG));
           csvData.m_lonMinsVel.push_back(line.split(',').value(LON_MIN));
        }

        qDebug() << "LENGTH AFTER IMPORT: " << csvData.m_xGyro.length();
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

    // convert values here
    convertInputData();

    // write processed values to new .CSV

    while(m_inputDataVector->size() > 0)
    {
        inputData tmpData = m_inputDataVector->front();
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
        rocketData.m_AltimeterGPS.append(tmpData.altGPSMeter);
        rocketData.m_latGPS.append(tmpData.latitude);
        rocketData.m_longGPS.append(tmpData.longitude);
        rocketData.m_timeGPS.append(tmpData.curTimeString);
        rocketData.m_time.append(tmpData.curTime);

        rocketData.m_lonDegrees.append(QString::number(tmpData.lonDegrees));
        rocketData.m_lonMins.append(QString::number(tmpData.lonMins));
        rocketData.m_latDegrees.append(QString::number(tmpData.latDegrees));
        rocketData.m_latMins.append(QString::number(tmpData.latMins));

        rocketData.m_lonDegreesVel.append(QString::number(tmpData.lonDegrees));
        rocketData.m_lonMinsVel.append(QString::number(tmpData.lonMins));
        rocketData.m_latDegreesVel.append(QString::number(tmpData.latDegrees));
        rocketData.m_latMinsVel.append(QString::number(tmpData.latMins));

    }    

}

void DataProcessing::convertInputData()
{
   QVector<inputData>* tmpData;
   tmpData = m_inputDataVector;

   qDebug() << "INITIAL ALTITUDE: " << altInit;

   for(int i = 0; i < m_inputDataVector->size(); i++)
   {
       //Altitude -> ((1 - ((millibars / 1013.25)^0.190284)) * 145366.45) - baseAlt
       tmpData->at(i).altitude.toStdString() = (1 - (qPow((m_inputDataVector->at(i).altitude.toDouble() / 100) / 1013.25, 0.190284) * 145366.45)) - altInit; // (- baseAlt)
       //tmpData->at(i).accX =

       // do the same for all other data
   }

   m_inputDataVector = tmpData; // ok to overwrite m_inputDataVector?
   //m_convertedDataVector = tmpData;
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
double DataProcessing::getNextVelocity(int source, double delta_time)
{
  //double dist = calculateDistance(source);
  //qDebug() << "DISTANCE " << dist << endl;
  //double time_s = getAttributeFromSource(source, GPS_TIME, 1);
  //qDebug() << "TIME " << time_s << endl;
  //qDebug() << "Velocity Calculated " << dist / time_s << endl;

  double curVel = prevVel + accel_mag * delta_time;

  prevVel = curVel;

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
    double pascalPressure = nextPressure * 100;
    double R = 8.3144598; //universal gas constant J/mol/K
    double G0 = 9.80665; //Gravitational Acceleration m/s^2
    double M = 0.0289644; //Molar Mass of Earth's Air kg/mol

   //calculates height in meters
   double nextHeight = altInfo.baseHeight + (((R * altInfo.baseTemp) * (qLn(pascalPressure/altInfo.basePressure))) / (G0 * M));
   //convert height to feet
   double feetHeight = nextHeight * 3.28084;
   return feetHeight;

}



double DataProcessing::getAccelerationMagnitude(int source)
{
    double accel_X = getAttributeFromSource(source, X_ACCEL, 1);
    double accel_Y = getAttributeFromSource(source, Y_ACCEL, 1);
    double accel_Z = getAttributeFromSource(source, Z_ACCEL, 1);

    accel_mag = sqrt((accel_X*accel_X) + (accel_Y*accel_Y) + (accel_Z*accel_Z)); // |a| = sqrt(ax^2 + ay^2 + az^2)

    double G0 = 9.80665; //Gravitational Acceleration m/s^2
    g_force = accel_mag / G0;

    return accel_mag;
}


double DataProcessing::getGForce()
{
    return g_force;
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

    if(attribute.length() > 0)
    {
        nextValue = attribute.at(0).toDouble();
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
        qDebug() << "Filename: " << filename;

        QString copy_path = "Files/csv/";
        copy_path.append(filename);
        qDebug() << "Copy file path is: " << copy_path;

        if(!QDir("Files/csv").exists()) //check if csv dir exists
        {
            qDebug() << "Directory created!";
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
                qDebug() << "Copy file with question";
            }
        }
        else
        {
            QFile::copy(path, copy_path); //move the file to application dir
            qDebug() << "Copy file without question";
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

    qDebug() << "LENGTH AFTER CLEAR: " << csvData.m_xGyro.length();
}



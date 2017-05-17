#include "createprofile.h"
#include "ui_createprofile.h"
#include <QFileDialog>
#include <QDebug>
#include <QThread>
#include <QDateTime>

CreateProfile::CreateProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProfile)
{
    ui->setupUi(this);
    //ui->pushButton->setEnabled(false);
}

CreateProfile::~CreateProfile()
{
    delete ui;
}


/**************************************************************88
 * Function: button box accepted
 * Description: gets info from checkboxes and line edits from ui form
 *
 *
 * ************************************************************/
void CreateProfile::on_buttonBox_accepted()
{
    name = ui->profileName->text();
    location = ui->location->text();
    rocket = ui->rocketName->text();
    baseAltitude = ui->baseHeight->text();
    basePressure = ui->basePressure->text();

    baseTemp = ui->baseTemp->text();
    qDebug() << name << endl;
    doneWithDialog = true;
    createFolder();
}

/**************************************************************
 * Function: get Altitude Info
 * Description: converts user input into double values and stores barometric formula info into a struct
 * Inputs: none
 * Output: struct containing all necessary user-entered values for converting pressure into height
 *
 * ***********************************************************/
struct baseAltitudeInfo CreateProfile::getAltitudeInfo()
{
    struct baseAltitudeInfo altInfo;
    int alt = baseAltitude.toDouble();
    int pre = basePressure.toDouble();

    if(alt > 0 && pre > 0)
    {
        altInfo.baseHeight = alt / 3.28084; // convert to meters
        altInfo.basePressure = pre * 100; //convert to Pascals
    }
    else
    {
        altInfo.baseHeight = alt; // no conversion necessary
    }
    altInfo.baseTemp = baseTemp.toDouble(); // inputted in Kelvin

    return altInfo;
}

/***********************************************************************
 * Function: createFolder
 * Description: Creates folder with name specified by user where all pertinent flight info can be stored
 * and creates a flight log with location, date and name information
 *
 * ********************************************************************/
void CreateProfile::createFolder()
{
    writePath = "../Flights/"; //dialog.getExistingDirectory(nullptr, "","../Flights",QFileDialog::DontResolveSymlinks);
    qDebug() << writePath << endl;
    qDebug() << writePath + name << endl;

    if(!QDir(writePath + name).exists())
    {
        qDebug() << "Folder does not exist so make one " << endl;
        QDir().mkdir(writePath + name);

        QDateTime fileDate;
        QString writeFile = writePath + name + "/FlightLog.txt";
        QFile flight(writeFile);

        if(!flight.open(QFile::WriteOnly | QFile::Text))
        {
            qDebug() << flight.errorString();
            //return 0;
        }
        QTextStream flightStream( &flight );
        flightStream << name << endl;
        flightStream << "Flight log for rocket " + rocket + " On " + fileDate.currentDateTime().toString("MM.dd.yyyy") << endl;
        flightStream << "Location: " << location << endl;
        flightStream << "Initial Altitude: " << baseAltitude << " ft. " << endl;
        flightStream << "Starting Pressure: " << basePressure << " milli bar " << endl;
        flightStream << "Temperature at launch site: " << baseTemp << " Kelvin " << endl;

        flight.close();
    }
}

/***************************************************
 * Setters
 *
 * ************************************************/
void CreateProfile::on_csvCheck_toggled(bool checked)
{
    writeCSV = checked;
}

void CreateProfile::on_pdfCheck_toggled(bool checked)
{
    writePDF = checked;
}

/*************************************************
 * Getters
 *
 * **********************************************/
bool CreateProfile::writeCSVCheck()
{
    return writeCSV;
}

bool CreateProfile::writePDFCheck()
{
    return writePDF;
}

QString CreateProfile::getFlightName()
{
    return name;
}

QString CreateProfile::getProfilePath()
{
    return writePath + name;
}

QString CreateProfile::getLogFile()
{
    return writePath + name + "/FlightLog.txt";
}

#ifndef CREATEPROFILE_H
#define CREATEPROFILE_H

#include <QDialog>
#include "dataprocessing.h"

namespace Ui {
class CreateProfile;
}

class CreateProfile : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProfile(QWidget *parent = 0);
    ~CreateProfile();
    void createFolder();
    bool writeCSVCheck();
    bool writePDFCheck();
    QString getProfilePath();
    QString getLogFile();
    QString getFlightName();

    struct baseAltitudeInfo getAltitudeInfo();
    void check_input_values();


private slots:
    void on_buttonBox_accepted();
    
    void on_csvCheck_toggled(bool checked);

    void on_pdfCheck_toggled(bool checked);

private:
    Ui::CreateProfile *ui;
    QString name;
    QString date;
    QString rocket;
    QString location;
    QString baseAltitude = "0";
    QString basePressure = "0";
    QString baseTemp = "272";
    QString writePath;
    bool writePDF = false;
    bool writeCSV = false;
    bool doneWithDialog = false;
};

#endif // CREATEPROFILE_H

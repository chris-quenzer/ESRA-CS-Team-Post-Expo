#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>

namespace Ui {
class settingsDialog;
}

class settingsDialog : public QDialog
{
    Q_OBJECT

public:

    struct Settings
    {

        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;

    };

    explicit settingsDialog(QWidget *parent = 0);
    ~settingsDialog();
    int openCount;
    Settings settings() const;


private slots:

    void showPortInfo(int idx);
    void on_cancelButton_clicked();
    void on_applyButton_clicked();

    void on_refreshPortInfoButton_clicked();

    void apply();

private:

    void fillPortsInfo();
    void fillPortsParameters();
    void updateSettings();

private:

    Ui::settingsDialog *ui;
    Settings curSettings;

};

#endif // SETTINGSDIALOG_H

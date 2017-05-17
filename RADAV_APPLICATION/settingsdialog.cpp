#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

settingsDialog::settingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsDialog)
{
    ui->setupUi(this);

    //Test value to validate the applyButton slot works
    openCount = 0;

    //This connects the apply button in the settings dialog to the appropriate function
    connect(ui->applyButton, &QPushButton::clicked, this, &settingsDialog::apply);

    //This connection links the objects in the combo box using the showPortInfo() function
    connect(ui->serialPortsComboBox, static_cast <void (QComboBox::*) (int)> (&QComboBox::currentIndexChanged),
            this, &settingsDialog::showPortInfo);

    //Fill in the possible settings for the connection to combo boxes
    fillPortsParameters();

    //Fill in port info for curently connected devices
    fillPortsInfo();

    //THis will store the current connection settings
    updateSettings();
}

settingsDialog::~settingsDialog()
{
    delete ui;
}

/******************************************************************************
* Function: settings() const
* Purpose: This function returns teh current connection parmaeters set in the
*          Comm settings dialog window.
* Parameters: None
* Output: Returns a settings object with the current connection settings
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
settingsDialog::Settings settingsDialog::settings() const
{
    return curSettings;
}

/******************************************************************************
* Function: showPortInfo(int idx)
* Purpose: This function will create a string list for each com connection
*          available at the time of the call. Each ist will be populated
*          with the serial port info or N/A if not available.
* Parameters: An integer used to index the list
* Output: All data on the curent port highlighted in the combo box is displayed
*         by the appropriate label.
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void settingsDialog::showPortInfo(int idx)
{
    //Check if the list is empty
    if (idx == -1)
    {
        return;
    }

    //If not , display the current port info

    QStringList list = ui->serialPortsComboBox->itemData(idx).toStringList();
    ui->descLabel->setText(tr("Description: %1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    ui->manufactLabel->setText(tr("Manufacturer: %1").arg(list.count() > 2 ? list.at(2) : tr(blankString)));
    ui->snLabel->setText(tr("Serial Number: %1").arg(list.count() > 3 ? list.at(3) : tr(blankString)));
    ui->locLabel->setText(tr("Location: %1").arg(list.count() > 4 ? list.at(4) : tr(blankString)));
    ui->vidLabel->setText(tr("Vendor ID: %1").arg(list.count() > 5 ? list.at(5) : tr(blankString)));
    ui->pidLabel->setText(tr("Product ID: %1").arg(list.count() > 6 ? list.at(6) : tr(blankString)));

}

/******************************************************************************
* Function: apply()
* Purpose: This function will update the current connections settings, settings
*          object
* Parameters: None
* Output: The current connections settings vars will be saved
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void settingsDialog::apply()
{
    updateSettings();
    hide();
}

/******************************************************************************
* Function: fillPortsParameters()
* Purpose: To add the possible values for connection to each combo box.
* Parameters: None
* Output: The settings dialog will have a complete list of possible options for
*         the serial connection.
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void settingsDialog::fillPortsParameters()
{
    //Fill the baud rate combo box with the standard available baud rates, and serial port values
    ui->BaudRateComboBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->BaudRateComboBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->BaudRateComboBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->BaudRateComboBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->BaudRateComboBox->setCurrentIndex(3);

    //Fill in the data bits combo box with the standard avaialble data bit values, and serial port values
    ui->dataBitsComboBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitsComboBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitsComboBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitsComboBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitsComboBox->setCurrentIndex(3);

    //Fill in the parity combo box with the standard avaialble parity values, and serial port values
    ui->parityComboBox->addItem(tr("None"), QSerialPort::NoParity);
    ui->parityComboBox->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->parityComboBox->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->parityComboBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->parityComboBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    //Fill in the stop bits combo box with the standard avaialble stop bit values, and serial port values
    ui->stopBitsComboBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);

//Check to see if the OS is windows, if it is, add the 1.5 stop bit option
#ifdef Q_OS_WIN
    ui->stopBitsComboBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->stopBitsComboBox->addItem(tr("2"), QSerialPort::TwoStop);

    //Fill in the flow control combo box with the standard avaialble flow control values, and serial port values
    ui->flowControlComboBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->flowControlComboBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->flowControlComboBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);

}

/******************************************************************************
* Function: updateSettings()
* Purpose: THis will save all the settings in the communication settings window
*          to the settings struct. This will be used to hols the serial
*          connections settings
* Parameters: None
* Output: This will save all the configured connection settings to the settings
*         struct
* Citation: This is adapted from the QT 5.7 Terminal tutorial included with the
*           QT creator IDE
*******************************************************************************/
void settingsDialog::updateSettings()
{
    // Store the currently selected com device name in the settings struct name
    // element
    curSettings.name = ui->serialPortsComboBox->currentText();

    // This saves the curent baud rate selection in the settings dialog and
    // converts it to an int which is static cast to to the serial port baud
    // rate type
    curSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                ui->BaudRateComboBox->itemData(ui->BaudRateComboBox->currentIndex()).toInt());

    //Store the string value of the baud rate for display
    curSettings.stringBaudRate = QString::number(curSettings.baudRate);

    //The next lines will save the data bits static cast and in string form.
    curSettings.dataBits = static_cast<QSerialPort::DataBits>(
                ui->dataBitsComboBox->itemData(ui->dataBitsComboBox->currentIndex()).toInt());
    curSettings.stringDataBits = ui->dataBitsComboBox->currentText();

    // These lines of code will save the parity bits in both static cast and
    // string formats
    curSettings.parity = static_cast<QSerialPort::Parity>(
                ui->dataBitsComboBox->itemData(ui->dataBitsComboBox->currentIndex()).toInt());
    curSettings.stringParity = ui->parityComboBox->currentText();

    // These lines of code will store the current settings for the Stop bits in
    // both static cats and string format
    curSettings.stopBits = static_cast<QSerialPort::StopBits>(
                ui->stopBitsComboBox->itemData(ui->stopBitsComboBox->currentIndex()).toInt());
    curSettings.stringStopBits = ui->stopBitsComboBox->currentText();

    // This will do the same as above but for the Flow control
    curSettings.flowControl = static_cast<QSerialPort::FlowControl>(
                ui->flowControlComboBox->itemData(ui->stopBitsComboBox->currentIndex()).toInt());
    curSettings.stringFlowControl = ui->flowControlComboBox->currentText();


}


/******************************************************************************
* Function: on_cancelButton_clicked()
* Purpose: This function will close the settings dialog without changing
*          application settings
* Parameters: None
* Output: This will close the settings dialog without changing the application
*         settings
*******************************************************************************/

void settingsDialog::on_cancelButton_clicked()
{
   // settingsDialog::~settingsDialog();
    //settingsDialog::~settingsDialog();
}

/******************************************************************************
* Function: on_applyButton_clicked()
* Purpose: This function will take the current settings selections and sve them
*          to the applications settings
* Parameters: None
* Output: This will save the selected settings and close the settings window.
*******************************************************************************/
void settingsDialog::on_applyButton_clicked()
{
    openCount++;
    QString strVal = QString::number(openCount);
    QString finalString = "You clicked apply " + strVal + " times!";

    ui->settingsLabel->setText(finalString);

    //Put in the call to the apply function to save settings.
    settingsDialog::apply();
}

/******************************************************************************
* Function: fillPortsInfo()
* Purpose: This function will poll the computers comports and fill the combobox
*          with the available com ports information.
* Parameters: None
* Output: The combobox and the supporting lables will hold information on the
*         currently selected com device in the combo box.
*******************************************************************************/
void settingsDialog::fillPortsInfo()
{
    ui->serialPortsComboBox->clear();
    QString description;
    QString manufacturer;
    QString serialNum;
    //QString baudRate;

    const auto infos = QSerialPortInfo::availablePorts();

        ui->serialPortsComboBox->addItem(tr("Custom"));

    for (const QSerialPortInfo &info : infos)
    {
        QStringList list;

        //Fill the various strings with port info
        description = info.description();
        manufacturer = info.manufacturer();
        serialNum = info.serialNumber();

        //add port info to string list, if not present, print N/A
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNum.isEmpty() ? serialNum : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        ui->serialPortsComboBox->addItem(list.first(), list);
    }

}

/******************************************************************************
* Function: on_refreshPortInfoButton_clicked()
* Purpose: This function is used to re-poll the com ports in order to facilitate
* device connection after teh application has been started.
* Parameters: None
* Output: The combobox and the supporting lables will hold information on the
*         currently selected com device in the combo box after rescanning for com ports.
*******************************************************************************/
void settingsDialog::on_refreshPortInfoButton_clicked()
{
    fillPortsInfo();
}

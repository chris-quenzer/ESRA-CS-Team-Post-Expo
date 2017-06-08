/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_settingsDialog
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *serialPortsComboBox;
    QPushButton *refreshPortInfoButton;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *descLabel;
    QLabel *manufactLabel;
    QLabel *snLabel;
    QLabel *locLabel;
    QLabel *vidLabel;
    QLabel *pidLabel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *baudRateLabel;
    QLabel *dataBitsLabel;
    QLabel *parityLabel;
    QLabel *stopBitsLabel;
    QLabel *flowControlLabel;
    QVBoxLayout *verticalLayout_3;
    QComboBox *BaudRateComboBox;
    QComboBox *dataBitsComboBox;
    QComboBox *parityComboBox;
    QComboBox *stopBitsComboBox;
    QComboBox *flowControlComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *settingsLabel;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *applyButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *settingsDialog)
    {
        if (settingsDialog->objectName().isEmpty())
            settingsDialog->setObjectName(QStringLiteral("settingsDialog"));
        settingsDialog->resize(413, 332);
        gridLayout_2 = new QGridLayout(settingsDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        serialPortsComboBox = new QComboBox(settingsDialog);
        serialPortsComboBox->setObjectName(QStringLiteral("serialPortsComboBox"));

        horizontalLayout_3->addWidget(serialPortsComboBox);

        refreshPortInfoButton = new QPushButton(settingsDialog);
        refreshPortInfoButton->setObjectName(QStringLiteral("refreshPortInfoButton"));

        horizontalLayout_3->addWidget(refreshPortInfoButton);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(settingsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        descLabel = new QLabel(groupBox);
        descLabel->setObjectName(QStringLiteral("descLabel"));

        verticalLayout->addWidget(descLabel);

        manufactLabel = new QLabel(groupBox);
        manufactLabel->setObjectName(QStringLiteral("manufactLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(manufactLabel->sizePolicy().hasHeightForWidth());
        manufactLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(manufactLabel);

        snLabel = new QLabel(groupBox);
        snLabel->setObjectName(QStringLiteral("snLabel"));

        verticalLayout->addWidget(snLabel);

        locLabel = new QLabel(groupBox);
        locLabel->setObjectName(QStringLiteral("locLabel"));

        verticalLayout->addWidget(locLabel);

        vidLabel = new QLabel(groupBox);
        vidLabel->setObjectName(QStringLiteral("vidLabel"));

        verticalLayout->addWidget(vidLabel);

        pidLabel = new QLabel(groupBox);
        pidLabel->setObjectName(QStringLiteral("pidLabel"));

        verticalLayout->addWidget(pidLabel);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(settingsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        baudRateLabel = new QLabel(groupBox_2);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));

        verticalLayout_4->addWidget(baudRateLabel);

        dataBitsLabel = new QLabel(groupBox_2);
        dataBitsLabel->setObjectName(QStringLiteral("dataBitsLabel"));

        verticalLayout_4->addWidget(dataBitsLabel);

        parityLabel = new QLabel(groupBox_2);
        parityLabel->setObjectName(QStringLiteral("parityLabel"));

        verticalLayout_4->addWidget(parityLabel);

        stopBitsLabel = new QLabel(groupBox_2);
        stopBitsLabel->setObjectName(QStringLiteral("stopBitsLabel"));

        verticalLayout_4->addWidget(stopBitsLabel);

        flowControlLabel = new QLabel(groupBox_2);
        flowControlLabel->setObjectName(QStringLiteral("flowControlLabel"));

        verticalLayout_4->addWidget(flowControlLabel);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        BaudRateComboBox = new QComboBox(groupBox_2);
        BaudRateComboBox->setObjectName(QStringLiteral("BaudRateComboBox"));

        verticalLayout_3->addWidget(BaudRateComboBox);

        dataBitsComboBox = new QComboBox(groupBox_2);
        dataBitsComboBox->setObjectName(QStringLiteral("dataBitsComboBox"));

        verticalLayout_3->addWidget(dataBitsComboBox);

        parityComboBox = new QComboBox(groupBox_2);
        parityComboBox->setObjectName(QStringLiteral("parityComboBox"));

        verticalLayout_3->addWidget(parityComboBox);

        stopBitsComboBox = new QComboBox(groupBox_2);
        stopBitsComboBox->setObjectName(QStringLiteral("stopBitsComboBox"));

        verticalLayout_3->addWidget(stopBitsComboBox);

        flowControlComboBox = new QComboBox(groupBox_2);
        flowControlComboBox->setObjectName(QStringLiteral("flowControlComboBox"));

        verticalLayout_3->addWidget(flowControlComboBox);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_2);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        settingsLabel = new QLabel(settingsDialog);
        settingsLabel->setObjectName(QStringLiteral("settingsLabel"));

        horizontalLayout_5->addWidget(settingsLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        applyButton = new QPushButton(settingsDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout_4->addWidget(applyButton);

        cancelButton = new QPushButton(settingsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_4->addWidget(cancelButton);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(verticalLayout_5, 0, 0, 1, 1);


        retranslateUi(settingsDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), settingsDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(settingsDialog);
    } // setupUi

    void retranslateUi(QDialog *settingsDialog)
    {
        settingsDialog->setWindowTitle(QApplication::translate("settingsDialog", "Communication Settings", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        settingsDialog->setWhatsThis(QApplication::translate("settingsDialog", "The settings dialog box", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        refreshPortInfoButton->setText(QApplication::translate("settingsDialog", "Refresh Ports", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("settingsDialog", "Device Information", Q_NULLPTR));
        descLabel->setText(QApplication::translate("settingsDialog", "Description:", Q_NULLPTR));
        manufactLabel->setText(QApplication::translate("settingsDialog", "Manufacturer:", Q_NULLPTR));
        snLabel->setText(QApplication::translate("settingsDialog", "Serial Number:", Q_NULLPTR));
        locLabel->setText(QApplication::translate("settingsDialog", "Location:", Q_NULLPTR));
        vidLabel->setText(QApplication::translate("settingsDialog", "Vendor ID:", Q_NULLPTR));
        pidLabel->setText(QApplication::translate("settingsDialog", "Product  ID:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("settingsDialog", "Connection  Settings", Q_NULLPTR));
        baudRateLabel->setText(QApplication::translate("settingsDialog", "Baud Rate:", Q_NULLPTR));
        dataBitsLabel->setText(QApplication::translate("settingsDialog", "Data Bits:", Q_NULLPTR));
        parityLabel->setText(QApplication::translate("settingsDialog", "Parity:", Q_NULLPTR));
        stopBitsLabel->setText(QApplication::translate("settingsDialog", "Stop Bits:", Q_NULLPTR));
        flowControlLabel->setText(QApplication::translate("settingsDialog", "Flow Control:", Q_NULLPTR));
        settingsLabel->setText(QString());
        applyButton->setText(QApplication::translate("settingsDialog", "Apply", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("settingsDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settingsDialog: public Ui_settingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H

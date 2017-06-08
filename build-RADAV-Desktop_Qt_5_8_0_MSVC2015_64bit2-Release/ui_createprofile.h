/********************************************************************************
** Form generated from reading UI file 'createprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPROFILE_H
#define UI_CREATEPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateProfile
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *profileName;
    QLineEdit *location;
    QLineEdit *rocketName;
    QLineEdit *basePressure;
    QVBoxLayout *verticalLayout;
    QCheckBox *csvCheck;
    QCheckBox *pdfCheck;
    QLineEdit *baseTemp;
    QLineEdit *baseHeight;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateProfile)
    {
        if (CreateProfile->objectName().isEmpty())
            CreateProfile->setObjectName(QStringLiteral("CreateProfile"));
        CreateProfile->resize(291, 196);
        layoutWidget = new QWidget(CreateProfile);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 270, 181));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        profileName = new QLineEdit(layoutWidget);
        profileName->setObjectName(QStringLiteral("profileName"));

        verticalLayout_2->addWidget(profileName);

        location = new QLineEdit(layoutWidget);
        location->setObjectName(QStringLiteral("location"));

        verticalLayout_2->addWidget(location);

        rocketName = new QLineEdit(layoutWidget);
        rocketName->setObjectName(QStringLiteral("rocketName"));

        verticalLayout_2->addWidget(rocketName);

        basePressure = new QLineEdit(layoutWidget);
        basePressure->setObjectName(QStringLiteral("basePressure"));

        verticalLayout_2->addWidget(basePressure);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        csvCheck = new QCheckBox(layoutWidget);
        csvCheck->setObjectName(QStringLiteral("csvCheck"));

        verticalLayout->addWidget(csvCheck);

        pdfCheck = new QCheckBox(layoutWidget);
        pdfCheck->setObjectName(QStringLiteral("pdfCheck"));

        verticalLayout->addWidget(pdfCheck);

        baseTemp = new QLineEdit(layoutWidget);
        baseTemp->setObjectName(QStringLiteral("baseTemp"));

        verticalLayout->addWidget(baseTemp);

        baseHeight = new QLineEdit(layoutWidget);
        baseHeight->setObjectName(QStringLiteral("baseHeight"));

        verticalLayout->addWidget(baseHeight);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(CreateProfile);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateProfile, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateProfile, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateProfile);
    } // setupUi

    void retranslateUi(QDialog *CreateProfile)
    {
        CreateProfile->setWindowTitle(QApplication::translate("CreateProfile", "Dialog", Q_NULLPTR));
        profileName->setText(QApplication::translate("CreateProfile", "Folder Name", Q_NULLPTR));
        location->setText(QApplication::translate("CreateProfile", "Location", Q_NULLPTR));
        rocketName->setText(QApplication::translate("CreateProfile", "Rocket Name", Q_NULLPTR));
        basePressure->setText(QApplication::translate("CreateProfile", "Starting Pressure (mbar)", Q_NULLPTR));
        csvCheck->setText(QApplication::translate("CreateProfile", "Save to CSV", Q_NULLPTR));
        pdfCheck->setText(QApplication::translate("CreateProfile", "Export graphs to pdf", Q_NULLPTR));
        baseTemp->setText(QApplication::translate("CreateProfile", "Starting Temperature (K)", Q_NULLPTR));
        baseHeight->setText(QApplication::translate("CreateProfile", "Starting Altitude (ft)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateProfile: public Ui_CreateProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROFILE_H

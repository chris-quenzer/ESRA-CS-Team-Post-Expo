/********************************************************************************
** Form generated from reading UI file 'mavproxyint.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAVPROXYINT_H
#define UI_MAVPROXYINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MavProxyInt
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QTextEdit *mavProxyOutput;
    QLabel *label;
    QGridLayout *gridLayout;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QPushButton *closeButton;

    void setupUi(QWidget *MavProxyInt)
    {
        if (MavProxyInt->objectName().isEmpty())
            MavProxyInt->setObjectName(QStringLiteral("MavProxyInt"));
        MavProxyInt->resize(630, 419);
        gridLayout_2 = new QGridLayout(MavProxyInt);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(MavProxyInt);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 522, 399));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        mavProxyOutput = new QTextEdit(scrollAreaWidgetContents);
        mavProxyOutput->setObjectName(QStringLiteral("mavProxyOutput"));

        gridLayout_3->addWidget(mavProxyOutput, 1, 0, 1, 1);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        connectButton = new QPushButton(MavProxyInt);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        gridLayout->addWidget(connectButton, 0, 0, 1, 1);

        disconnectButton = new QPushButton(MavProxyInt);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));

        gridLayout->addWidget(disconnectButton, 1, 0, 1, 1);

        closeButton = new QPushButton(MavProxyInt);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        gridLayout->addWidget(closeButton, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);


        retranslateUi(MavProxyInt);

        QMetaObject::connectSlotsByName(MavProxyInt);
    } // setupUi

    void retranslateUi(QWidget *MavProxyInt)
    {
        MavProxyInt->setWindowTitle(QApplication::translate("MavProxyInt", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("MavProxyInt", "Raw Mavlink Messages", Q_NULLPTR));
        connectButton->setText(QApplication::translate("MavProxyInt", "Connect", Q_NULLPTR));
        disconnectButton->setText(QApplication::translate("MavProxyInt", "Disconnect", Q_NULLPTR));
        closeButton->setText(QApplication::translate("MavProxyInt", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MavProxyInt: public Ui_MavProxyInt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAVPROXYINT_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <LED.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionComm_Settings;
    QAction *action_About;
    QAction *actionAbout_QT;
    QAction *action_New;
    QAction *action_Save;
    QAction *action_Open;
    QAction *actionQuit;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionShow_Graphs;
    QAction *actionRestart;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *Timer_Layout;
    QLabel *label_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLCDNumber *mission_time;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_15;
    QLabel *apo_label_3;
    LED *landing_LED;
    LED *descent_LED;
    QLabel *apo_label_2;
    QLabel *launch_time_label;
    QLabel *apo_label;
    LED *launch_LED;
    QLabel *apo_time_label;
    LED *apo_LED;
    QLabel *launch_label;
    QLabel *apo_label_4;
    QLabel *landing_time_label;
    QLabel *ascent_label;
    LED *ascent_LED;
    QLabel *descent_label;
    QVBoxLayout *verticalLayout_11;
    QLabel *landingLat;
    QLabel *landingLon;
    QLabel *apo_label_5;
    QPushButton *start_stop;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_25;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_18;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_17;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_9;
    QFormLayout *formLayout_3;
    QLabel *label_19;
    QLCDNumber *alt_cur_LCD;
    QLabel *label_7;
    QLCDNumber *alt_max_LCD;
    QLabel *label_22;
    QLCDNumber *vel_cur_LCD;
    QLabel *label_8;
    QLCDNumber *vel_max_LCD;
    QLabel *label_9;
    QLCDNumber *accel_LCD;
    QLabel *label_11;
    QLCDNumber *g_force;
    QLCDNumber *accel_max_LCD;
    QLabel *label_20;
    QLCDNumber *high_g_force;
    QLabel *label_21;
    QLCDNumber *accelH_max_LCD;
    QLabel *label_23;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_17;
    QFormLayout *formLayout;
    QLabel *label_12;
    QLCDNumber *pitch_LCD;
    QLabel *label_13;
    QLCDNumber *roll_LCD;
    QLabel *label_14;
    QLCDNumber *yaw_LCD;
    QFormLayout *formLayout_2;
    QLabel *label_15;
    QLCDNumber *pitchRate_LCD;
    QLabel *label_16;
    QLCDNumber *rollRate_LCD;
    QLabel *label_17;
    QLCDNumber *yawRate_LCD;
    GLWidget *GLwidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_16;
    QSpacerItem *horizontalSpacer_2;
    QLabel *gps_status;
    LED *gps_LED;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QSpinBox *mapSelect;
    QCheckBox *circleCheckBox;
    QCheckBox *focusRocketCheckBox;
    QLCDNumber *zoomLCD;
    QFormLayout *formLayout_4;
    QLabel *label_18;
    QSlider *zoomSlider;
    QFormLayout *formLayout_7;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *decMinSecLat;
    QLabel *decMinSecLon;
    QSpacerItem *verticalSpacer;
    QFrame *mapFrame;
    QGridLayout *gridLayout;
    QWidget *map;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_10;
    QCustomPlot *customPlot;
    QCustomPlot *customPlot_2;
    QCustomPlot *customPlot_3;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *textToSendLabel;
    QPushButton *sndButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QLabel *rxTextLabel;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *pNameLabel;
    QLabel *bRateLabel;
    QLabel *dBitsLabel;
    QLabel *pBitsLabel;
    QLabel *sBitsLabel;
    QLabel *fContLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_16;
    QLabel *timeLabel;
    QLabel *timeOutputLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *mpuStartButton;
    QPushButton *sndtoGrph;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_26;
    QLabel *latLabel;
    QLabel *latDisplay;
    QHBoxLayout *horizontalLayout_25;
    QLabel *lonLabel;
    QLabel *longDisplay;
    QHBoxLayout *horizontalLayout_24;
    QLabel *gpsAltLabel;
    QLabel *gpsAltDisplay;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_15;
    QLabel *altimeterLabel;
    QLabel *altimeterDisplay;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLabel *accXDisplay;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *accYlabel;
    QLabel *accYDisplay;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *accZlabel;
    QLabel *accZDisplay;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *gyroXlabel;
    QLabel *gyroXDisplay;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *gytoYlabel;
    QLabel *gyroYDisplay;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *gyroZlabel;
    QLabel *gyroZDisplay;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *magXlabel;
    QLabel *magXDisplay;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *magYlabel;
    QLabel *magYDisplay;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_14;
    QLabel *magZlabel;
    QLabel *magZDisplay;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_20;
    QLabel *highGXLabel;
    QLabel *highGXDisplay;
    QHBoxLayout *horizontalLayout_22;
    QLabel *highGYLabel_2;
    QLabel *highGYDisplay;
    QHBoxLayout *horizontalLayout_23;
    QLabel *highGZLabel;
    QLabel *highGZDisplay;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_29;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_11;
    QHBoxLayout *horizontalLayout_30;
    QLabel *scaledAccXLabel;
    QLabel *scaledAccXDisp;
    QHBoxLayout *horizontalLayout_31;
    QLabel *scaledAccYLabel;
    QLabel *scaledAccYDisp;
    QHBoxLayout *horizontalLayout_32;
    QLabel *scaledAccZLabel;
    QLabel *scaledAccZDisp;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_33;
    QLabel *scaledGyroXLabel;
    QLabel *scaledGyroXDisp;
    QHBoxLayout *horizontalLayout_34;
    QLabel *scaledGyroYLabel;
    QLabel *scaledGyroYDisp;
    QHBoxLayout *horizontalLayout_35;
    QLabel *scaledGyroZLabel;
    QLabel *scaledGyroZDisp;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_13;
    QHBoxLayout *horizontalLayout_36;
    QLabel *scaledMagXLabel;
    QLabel *scaledMagXDisp;
    QHBoxLayout *horizontalLayout_37;
    QLabel *scaledMagYLabel;
    QLabel *scaledMagYDisp;
    QHBoxLayout *horizontalLayout_38;
    QLabel *scaledMagZLabel;
    QLabel *scaledMagZDisp;
    QPushButton *mavProxyShowButton;
    QCheckBox *expoDemoCheckBox;
    QCheckBox *includeHistoric;
    QCheckBox *receivingCheckBox;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuConfigure;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1340, 936);
        MainWindow->setStyleSheet(QLatin1String("/*QWidget{\n"
"background-color: rgb(70,70,70);\n"
"color: rgb(255,255,255);\n"
"}\n"
"\n"
"QTabWidget::tab{\n"
"background-color: rgb(70,70,70);\n"
"}*/\n"
""));
        actionComm_Settings = new QAction(MainWindow);
        actionComm_Settings->setObjectName(QStringLiteral("actionComm_Settings"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        actionAbout_QT = new QAction(MainWindow);
        actionAbout_QT->setObjectName(QStringLiteral("actionAbout_QT"));
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QStringLiteral("action_New"));
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/images/Disconnected-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/Resources/images/Disconnected-48.png"), QSize(), QIcon::Normal, QIcon::On);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/images/Connected-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/Resources/images/Connected-50.png"), QSize(), QIcon::Disabled, QIcon::On);
        actionDisconnect->setIcon(icon1);
        actionShow_Graphs = new QAction(MainWindow);
        actionShow_Graphs->setObjectName(QStringLiteral("actionShow_Graphs"));
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName(QStringLiteral("actionRestart"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        Timer_Layout = new QVBoxLayout();
        Timer_Layout->setSpacing(6);
        Timer_Layout->setObjectName(QStringLiteral("Timer_Layout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        label_2->setFont(font);

        Timer_Layout->addWidget(label_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        mission_time = new QLCDNumber(centralWidget);
        mission_time->setObjectName(QStringLiteral("mission_time"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mission_time->sizePolicy().hasHeightForWidth());
        mission_time->setSizePolicy(sizePolicy1);
        mission_time->setMinimumSize(QSize(275, 40));
        mission_time->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        font1.setStyleStrategy(QFont::PreferDefault);
        mission_time->setFont(font1);
        mission_time->setInputMethodHints(Qt::ImhNone);
        mission_time->setSmallDecimalPoint(true);
        mission_time->setDigitCount(12);
        mission_time->setSegmentStyle(QLCDNumber::Flat);
        mission_time->setProperty("intValue", QVariant(0));

        verticalLayout_5->addWidget(mission_time);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_5);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_6);


        verticalLayout_5->addLayout(horizontalLayout_4);


        gridLayout_4->addLayout(verticalLayout_5, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 5, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setSpacing(6);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_15->setHorizontalSpacing(6);
        gridLayout_15->setContentsMargins(0, -1, 0, 0);
        apo_label_3 = new QLabel(centralWidget);
        apo_label_3->setObjectName(QStringLiteral("apo_label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(apo_label_3->sizePolicy().hasHeightForWidth());
        apo_label_3->setSizePolicy(sizePolicy2);
        apo_label_3->setMinimumSize(QSize(75, 0));
        apo_label_3->setSizeIncrement(QSize(0, 0));
        apo_label_3->setBaseSize(QSize(0, 0));
        apo_label_3->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(apo_label_3, 2, 4, 1, 1);

        landing_LED = new LED(centralWidget);
        landing_LED->setObjectName(QStringLiteral("landing_LED"));

        gridLayout_15->addWidget(landing_LED, 1, 4, 1, 1);

        descent_LED = new LED(centralWidget);
        descent_LED->setObjectName(QStringLiteral("descent_LED"));

        gridLayout_15->addWidget(descent_LED, 1, 3, 1, 1);

        apo_label_2 = new QLabel(centralWidget);
        apo_label_2->setObjectName(QStringLiteral("apo_label_2"));
        sizePolicy2.setHeightForWidth(apo_label_2->sizePolicy().hasHeightForWidth());
        apo_label_2->setSizePolicy(sizePolicy2);
        apo_label_2->setMinimumSize(QSize(75, 0));
        apo_label_2->setSizeIncrement(QSize(0, 0));
        apo_label_2->setBaseSize(QSize(0, 0));
        apo_label_2->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(apo_label_2, 2, 3, 1, 1);

        launch_time_label = new QLabel(centralWidget);
        launch_time_label->setObjectName(QStringLiteral("launch_time_label"));
        sizePolicy2.setHeightForWidth(launch_time_label->sizePolicy().hasHeightForWidth());
        launch_time_label->setSizePolicy(sizePolicy2);
        launch_time_label->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(launch_time_label, 0, 0, 1, 1);

        apo_label = new QLabel(centralWidget);
        apo_label->setObjectName(QStringLiteral("apo_label"));
        sizePolicy2.setHeightForWidth(apo_label->sizePolicy().hasHeightForWidth());
        apo_label->setSizePolicy(sizePolicy2);
        apo_label->setMinimumSize(QSize(75, 0));
        apo_label->setSizeIncrement(QSize(0, 0));
        apo_label->setBaseSize(QSize(0, 0));
        apo_label->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(apo_label, 2, 2, 1, 1);

        launch_LED = new LED(centralWidget);
        launch_LED->setObjectName(QStringLiteral("launch_LED"));

        gridLayout_15->addWidget(launch_LED, 1, 0, 1, 1);

        apo_time_label = new QLabel(centralWidget);
        apo_time_label->setObjectName(QStringLiteral("apo_time_label"));
        sizePolicy2.setHeightForWidth(apo_time_label->sizePolicy().hasHeightForWidth());
        apo_time_label->setSizePolicy(sizePolicy2);
        apo_time_label->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(apo_time_label, 0, 2, 1, 1);

        apo_LED = new LED(centralWidget);
        apo_LED->setObjectName(QStringLiteral("apo_LED"));

        gridLayout_15->addWidget(apo_LED, 1, 2, 1, 1);

        launch_label = new QLabel(centralWidget);
        launch_label->setObjectName(QStringLiteral("launch_label"));
        sizePolicy2.setHeightForWidth(launch_label->sizePolicy().hasHeightForWidth());
        launch_label->setSizePolicy(sizePolicy2);
        launch_label->setMinimumSize(QSize(75, 0));
        launch_label->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(launch_label, 2, 0, 1, 1);

        apo_label_4 = new QLabel(centralWidget);
        apo_label_4->setObjectName(QStringLiteral("apo_label_4"));
        sizePolicy2.setHeightForWidth(apo_label_4->sizePolicy().hasHeightForWidth());
        apo_label_4->setSizePolicy(sizePolicy2);
        apo_label_4->setMinimumSize(QSize(75, 0));
        apo_label_4->setSizeIncrement(QSize(0, 0));
        apo_label_4->setBaseSize(QSize(0, 0));
        apo_label_4->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(apo_label_4, 2, 1, 1, 1);

        landing_time_label = new QLabel(centralWidget);
        landing_time_label->setObjectName(QStringLiteral("landing_time_label"));
        sizePolicy2.setHeightForWidth(landing_time_label->sizePolicy().hasHeightForWidth());
        landing_time_label->setSizePolicy(sizePolicy2);
        landing_time_label->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(landing_time_label, 0, 4, 1, 1);

        ascent_label = new QLabel(centralWidget);
        ascent_label->setObjectName(QStringLiteral("ascent_label"));
        sizePolicy2.setHeightForWidth(ascent_label->sizePolicy().hasHeightForWidth());
        ascent_label->setSizePolicy(sizePolicy2);
        ascent_label->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(ascent_label, 0, 1, 1, 1);

        ascent_LED = new LED(centralWidget);
        ascent_LED->setObjectName(QStringLiteral("ascent_LED"));

        gridLayout_15->addWidget(ascent_LED, 1, 1, 1, 1);

        descent_label = new QLabel(centralWidget);
        descent_label->setObjectName(QStringLiteral("descent_label"));
        sizePolicy2.setHeightForWidth(descent_label->sizePolicy().hasHeightForWidth());
        descent_label->setSizePolicy(sizePolicy2);
        descent_label->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(descent_label, 0, 3, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        landingLat = new QLabel(centralWidget);
        landingLat->setObjectName(QStringLiteral("landingLat"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        landingLat->setFont(font2);

        verticalLayout_11->addWidget(landingLat);

        landingLon = new QLabel(centralWidget);
        landingLon->setObjectName(QStringLiteral("landingLon"));
        landingLon->setFont(font2);

        verticalLayout_11->addWidget(landingLon);


        gridLayout_15->addLayout(verticalLayout_11, 1, 5, 1, 1);

        apo_label_5 = new QLabel(centralWidget);
        apo_label_5->setObjectName(QStringLiteral("apo_label_5"));
        sizePolicy2.setHeightForWidth(apo_label_5->sizePolicy().hasHeightForWidth());
        apo_label_5->setSizePolicy(sizePolicy2);
        apo_label_5->setMinimumSize(QSize(75, 0));
        apo_label_5->setSizeIncrement(QSize(0, 0));
        apo_label_5->setBaseSize(QSize(0, 0));
        apo_label_5->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(apo_label_5, 2, 5, 1, 1);


        gridLayout_4->addLayout(gridLayout_15, 0, 2, 1, 1);

        start_stop = new QPushButton(centralWidget);
        start_stop->setObjectName(QStringLiteral("start_stop"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(start_stop->sizePolicy().hasHeightForWidth());
        start_stop->setSizePolicy(sizePolicy3);
        start_stop->setMinimumSize(QSize(75, 75));
        start_stop->setMaximumSize(QSize(75, 75));

        gridLayout_4->addWidget(start_stop, 0, 0, 1, 1);


        Timer_Layout->addLayout(gridLayout_4);


        horizontalLayout_19->addLayout(Timer_Layout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_3);

        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMaximumSize(QSize(450, 57));
        label_25->setStyleSheet(QLatin1String("/*QLabel{\n"
"background-color: rgb(110,110,110);\n"
"border-radius: 10px;\n"
"}*/"));
        label_25->setPixmap(QPixmap(QString::fromUtf8(":/Resources/images/OSU_AIAA_Banner.png")));
        label_25->setScaledContents(true);
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(label_25);


        verticalLayout_8->addLayout(horizontalLayout_19);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy4);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_14 = new QGridLayout(tab);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_18 = new QGridLayout();
        gridLayout_18->setSpacing(6);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        scrollArea_2 = new QScrollArea(tab);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        sizePolicy4.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy4);
        scrollArea_2->setMinimumSize(QSize(500, 300));
        scrollArea_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1280, 750));
        gridLayout_17 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy4.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy4);
        groupBox_4->setMaximumSize(QSize(375, 16777215));
        groupBox_4->setStyleSheet(QLatin1String("QLCDNumber{\n"
"	\n"
"}"));
        groupBox_4->setFlat(false);
        verticalLayout_9 = new QVBoxLayout(groupBox_4);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_19);

        alt_cur_LCD = new QLCDNumber(groupBox_4);
        alt_cur_LCD->setObjectName(QStringLiteral("alt_cur_LCD"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(alt_cur_LCD->sizePolicy().hasHeightForWidth());
        alt_cur_LCD->setSizePolicy(sizePolicy5);
        alt_cur_LCD->setFrameShadow(QFrame::Raised);
        alt_cur_LCD->setDigitCount(7);
        alt_cur_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, alt_cur_LCD);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        alt_max_LCD = new QLCDNumber(groupBox_4);
        alt_max_LCD->setObjectName(QStringLiteral("alt_max_LCD"));
        sizePolicy5.setHeightForWidth(alt_max_LCD->sizePolicy().hasHeightForWidth());
        alt_max_LCD->setSizePolicy(sizePolicy5);
        alt_max_LCD->setFrameShadow(QFrame::Raised);
        alt_max_LCD->setDigitCount(7);
        alt_max_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, alt_max_LCD);

        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QStringLiteral("label_22"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_22);

        vel_cur_LCD = new QLCDNumber(groupBox_4);
        vel_cur_LCD->setObjectName(QStringLiteral("vel_cur_LCD"));
        sizePolicy5.setHeightForWidth(vel_cur_LCD->sizePolicy().hasHeightForWidth());
        vel_cur_LCD->setSizePolicy(sizePolicy5);
        vel_cur_LCD->setDigitCount(7);
        vel_cur_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, vel_cur_LCD);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_8);

        vel_max_LCD = new QLCDNumber(groupBox_4);
        vel_max_LCD->setObjectName(QStringLiteral("vel_max_LCD"));
        sizePolicy5.setHeightForWidth(vel_max_LCD->sizePolicy().hasHeightForWidth());
        vel_max_LCD->setSizePolicy(sizePolicy5);
        vel_max_LCD->setDigitCount(7);
        vel_max_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, vel_max_LCD);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_9);

        accel_LCD = new QLCDNumber(groupBox_4);
        accel_LCD->setObjectName(QStringLiteral("accel_LCD"));
        sizePolicy5.setHeightForWidth(accel_LCD->sizePolicy().hasHeightForWidth());
        accel_LCD->setSizePolicy(sizePolicy5);
        accel_LCD->setDigitCount(7);
        accel_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, accel_LCD);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_11);

        g_force = new QLCDNumber(groupBox_4);
        g_force->setObjectName(QStringLiteral("g_force"));
        sizePolicy5.setHeightForWidth(g_force->sizePolicy().hasHeightForWidth());
        g_force->setSizePolicy(sizePolicy5);
        g_force->setDigitCount(7);
        g_force->setSegmentStyle(QLCDNumber::Flat);

        formLayout_3->setWidget(5, QFormLayout::FieldRole, g_force);

        accel_max_LCD = new QLCDNumber(groupBox_4);
        accel_max_LCD->setObjectName(QStringLiteral("accel_max_LCD"));
        sizePolicy5.setHeightForWidth(accel_max_LCD->sizePolicy().hasHeightForWidth());
        accel_max_LCD->setSizePolicy(sizePolicy5);
        accel_max_LCD->setDigitCount(7);
        accel_max_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_3->setWidget(6, QFormLayout::FieldRole, accel_max_LCD);

        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_20);

        high_g_force = new QLCDNumber(groupBox_4);
        high_g_force->setObjectName(QStringLiteral("high_g_force"));
        sizePolicy5.setHeightForWidth(high_g_force->sizePolicy().hasHeightForWidth());
        high_g_force->setSizePolicy(sizePolicy5);
        high_g_force->setDigitCount(7);
        high_g_force->setSegmentStyle(QLCDNumber::Flat);

        formLayout_3->setWidget(7, QFormLayout::FieldRole, high_g_force);

        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_21);

        accelH_max_LCD = new QLCDNumber(groupBox_4);
        accelH_max_LCD->setObjectName(QStringLiteral("accelH_max_LCD"));
        sizePolicy5.setHeightForWidth(accelH_max_LCD->sizePolicy().hasHeightForWidth());
        accelH_max_LCD->setSizePolicy(sizePolicy5);
        accelH_max_LCD->setDigitCount(7);
        accelH_max_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_3->setWidget(8, QFormLayout::FieldRole, accelH_max_LCD);

        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QStringLiteral("label_23"));

        formLayout_3->setWidget(8, QFormLayout::LabelRole, label_23);


        verticalLayout_9->addLayout(formLayout_3);


        verticalLayout_7->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy6);
        groupBox_5->setMaximumSize(QSize(375, 120));
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_12);

        pitch_LCD = new QLCDNumber(groupBox_5);
        pitch_LCD->setObjectName(QStringLiteral("pitch_LCD"));
        QFont font3;
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        pitch_LCD->setFont(font3);
        pitch_LCD->setAutoFillBackground(false);
        pitch_LCD->setFrameShadow(QFrame::Raised);
        pitch_LCD->setSmallDecimalPoint(false);
        pitch_LCD->setDigitCount(7);
        pitch_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(0, QFormLayout::FieldRole, pitch_LCD);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_13);

        roll_LCD = new QLCDNumber(groupBox_5);
        roll_LCD->setObjectName(QStringLiteral("roll_LCD"));
        roll_LCD->setDigitCount(7);
        roll_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(1, QFormLayout::FieldRole, roll_LCD);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_14);

        yaw_LCD = new QLCDNumber(groupBox_5);
        yaw_LCD->setObjectName(QStringLiteral("yaw_LCD"));
        yaw_LCD->setDigitCount(7);
        yaw_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(2, QFormLayout::FieldRole, yaw_LCD);


        horizontalLayout_17->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_15);

        pitchRate_LCD = new QLCDNumber(groupBox_5);
        pitchRate_LCD->setObjectName(QStringLiteral("pitchRate_LCD"));
        pitchRate_LCD->setDigitCount(7);
        pitchRate_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pitchRate_LCD);

        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_16);

        rollRate_LCD = new QLCDNumber(groupBox_5);
        rollRate_LCD->setObjectName(QStringLiteral("rollRate_LCD"));
        rollRate_LCD->setDigitCount(7);
        rollRate_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, rollRate_LCD);

        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_17);

        yawRate_LCD = new QLCDNumber(groupBox_5);
        yawRate_LCD->setObjectName(QStringLiteral("yawRate_LCD"));
        yawRate_LCD->setLayoutDirection(Qt::LeftToRight);
        yawRate_LCD->setDigitCount(7);
        yawRate_LCD->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, yawRate_LCD);


        horizontalLayout_17->addLayout(formLayout_2);


        gridLayout_2->addLayout(horizontalLayout_17, 0, 0, 1, 1);


        verticalLayout_7->addWidget(groupBox_5);

        GLwidget = new GLWidget(scrollAreaWidgetContents_2);
        GLwidget->setObjectName(QStringLiteral("GLwidget"));
        sizePolicy6.setHeightForWidth(GLwidget->sizePolicy().hasHeightForWidth());
        GLwidget->setSizePolicy(sizePolicy6);
        GLwidget->setMinimumSize(QSize(300, 300));
        GLwidget->setMaximumSize(QSize(300, 300));

        verticalLayout_7->addWidget(GLwidget, 0, Qt::AlignBottom);


        gridLayout_17->addLayout(verticalLayout_7, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setSpacing(6);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_16->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        gps_status = new QLabel(scrollAreaWidgetContents_2);
        gps_status->setObjectName(QStringLiteral("gps_status"));
        sizePolicy2.setHeightForWidth(gps_status->sizePolicy().hasHeightForWidth());
        gps_status->setSizePolicy(sizePolicy2);
        QFont font4;
        font4.setPointSize(14);
        gps_status->setFont(font4);

        gridLayout_16->addWidget(gps_status, 0, 1, 1, 1);

        gps_LED = new LED(scrollAreaWidgetContents_2);
        gps_LED->setObjectName(QStringLiteral("gps_LED"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(gps_LED->sizePolicy().hasHeightForWidth());
        gps_LED->setSizePolicy(sizePolicy7);

        gridLayout_16->addWidget(gps_LED, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_16->addItem(verticalSpacer_2, 1, 3, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_10 = new QLabel(scrollAreaWidgetContents_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        mapSelect = new QSpinBox(scrollAreaWidgetContents_2);
        mapSelect->setObjectName(QStringLiteral("mapSelect"));
        mapSelect->setMaximum(8);
        mapSelect->setValue(1);

        horizontalLayout_3->addWidget(mapSelect);


        gridLayout_8->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        circleCheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        circleCheckBox->setObjectName(QStringLiteral("circleCheckBox"));

        gridLayout_8->addWidget(circleCheckBox, 1, 1, 1, 1);

        focusRocketCheckBox = new QCheckBox(scrollAreaWidgetContents_2);
        focusRocketCheckBox->setObjectName(QStringLiteral("focusRocketCheckBox"));
        QSizePolicy sizePolicy8(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(focusRocketCheckBox->sizePolicy().hasHeightForWidth());
        focusRocketCheckBox->setSizePolicy(sizePolicy8);

        gridLayout_8->addWidget(focusRocketCheckBox, 0, 1, 1, 1);

        zoomLCD = new QLCDNumber(scrollAreaWidgetContents_2);
        zoomLCD->setObjectName(QStringLiteral("zoomLCD"));
        QSizePolicy sizePolicy9(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(zoomLCD->sizePolicy().hasHeightForWidth());
        zoomLCD->setSizePolicy(sizePolicy9);
        zoomLCD->setFrameShadow(QFrame::Raised);
        zoomLCD->setSegmentStyle(QLCDNumber::Flat);

        gridLayout_8->addWidget(zoomLCD, 1, 2, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_18 = new QLabel(scrollAreaWidgetContents_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy9.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy9);
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_18);

        zoomSlider = new QSlider(scrollAreaWidgetContents_2);
        zoomSlider->setObjectName(QStringLiteral("zoomSlider"));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(zoomSlider->sizePolicy().hasHeightForWidth());
        zoomSlider->setSizePolicy(sizePolicy10);
        zoomSlider->setMinimum(1);
        zoomSlider->setMaximum(19);
        zoomSlider->setOrientation(Qt::Horizontal);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, zoomSlider);


        gridLayout_8->addLayout(formLayout_4, 0, 2, 1, 1);

        formLayout_7 = new QFormLayout();
        formLayout_7->setSpacing(6);
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        label_26 = new QLabel(scrollAreaWidgetContents_2);
        label_26->setObjectName(QStringLiteral("label_26"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_26);

        label_27 = new QLabel(scrollAreaWidgetContents_2);
        label_27->setObjectName(QStringLiteral("label_27"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_27);

        decMinSecLat = new QLabel(scrollAreaWidgetContents_2);
        decMinSecLat->setObjectName(QStringLiteral("decMinSecLat"));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, decMinSecLat);

        decMinSecLon = new QLabel(scrollAreaWidgetContents_2);
        decMinSecLon->setObjectName(QStringLiteral("decMinSecLon"));

        formLayout_7->setWidget(1, QFormLayout::FieldRole, decMinSecLon);


        gridLayout_8->addLayout(formLayout_7, 0, 0, 1, 1);


        gridLayout_16->addLayout(gridLayout_8, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_16->addItem(verticalSpacer, 2, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_16, 1, 0, 1, 1);

        mapFrame = new QFrame(scrollAreaWidgetContents_2);
        mapFrame->setObjectName(QStringLiteral("mapFrame"));
        sizePolicy4.setHeightForWidth(mapFrame->sizePolicy().hasHeightForWidth());
        mapFrame->setSizePolicy(sizePolicy4);
        mapFrame->setMinimumSize(QSize(512, 512));
        mapFrame->setMaximumSize(QSize(512, 512));
        mapFrame->setFrameShape(QFrame::StyledPanel);
        mapFrame->setFrameShadow(QFrame::Sunken);
        mapFrame->setLineWidth(1);
        mapFrame->setMidLineWidth(0);
        gridLayout = new QGridLayout(mapFrame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        map = new QWidget(mapFrame);
        map->setObjectName(QStringLiteral("map"));
        sizePolicy4.setHeightForWidth(map->sizePolicy().hasHeightForWidth());
        map->setSizePolicy(sizePolicy4);
        map->setAutoFillBackground(true);

        gridLayout->addWidget(map, 0, 0, 1, 1);


        gridLayout_5->addWidget(mapFrame, 0, 0, 1, 1);


        gridLayout_17->addLayout(gridLayout_5, 0, 3, 1, 1);

        scrollArea_3 = new QScrollArea(scrollAreaWidgetContents_2);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        sizePolicy4.setHeightForWidth(scrollArea_3->sizePolicy().hasHeightForWidth());
        scrollArea_3->setSizePolicy(sizePolicy4);
        scrollArea_3->setMinimumSize(QSize(400, 500));
        scrollArea_3->setMaximumSize(QSize(16777215, 16777215));
        scrollArea_3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 384, 930));
        verticalLayout_10 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        customPlot = new QCustomPlot(scrollAreaWidgetContents_3);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        sizePolicy4.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy4);
        customPlot->setMinimumSize(QSize(200, 300));
        customPlot->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_10->addWidget(customPlot);

        customPlot_2 = new QCustomPlot(scrollAreaWidgetContents_3);
        customPlot_2->setObjectName(QStringLiteral("customPlot_2"));
        sizePolicy4.setHeightForWidth(customPlot_2->sizePolicy().hasHeightForWidth());
        customPlot_2->setSizePolicy(sizePolicy4);
        customPlot_2->setMinimumSize(QSize(200, 300));
        customPlot_2->setBaseSize(QSize(0, 0));

        verticalLayout_10->addWidget(customPlot_2);

        customPlot_3 = new QCustomPlot(scrollAreaWidgetContents_3);
        customPlot_3->setObjectName(QStringLiteral("customPlot_3"));
        sizePolicy4.setHeightForWidth(customPlot_3->sizePolicy().hasHeightForWidth());
        customPlot_3->setSizePolicy(sizePolicy4);
        customPlot_3->setMinimumSize(QSize(200, 300));
        customPlot_3->setBaseSize(QSize(0, 0));

        verticalLayout_10->addWidget(customPlot_3);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_17->addWidget(scrollArea_3, 0, 1, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_18->addWidget(scrollArea_2, 0, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_18, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 621, 221));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textToSendLabel = new QLineEdit(layoutWidget);
        textToSendLabel->setObjectName(QStringLiteral("textToSendLabel"));

        horizontalLayout_2->addWidget(textToSendLabel);

        sndButton = new QPushButton(layoutWidget);
        sndButton->setObjectName(QStringLiteral("sndButton"));

        horizontalLayout_2->addWidget(sndButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        scrollArea = new QScrollArea(layoutWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 538, 185));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rxTextLabel = new QLabel(scrollAreaWidgetContents);
        rxTextLabel->setObjectName(QStringLiteral("rxTextLabel"));
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(rxTextLabel->sizePolicy().hasHeightForWidth());
        rxTextLabel->setSizePolicy(sizePolicy11);

        horizontalLayout->addWidget(rxTextLabel);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pNameLabel = new QLabel(layoutWidget);
        pNameLabel->setObjectName(QStringLiteral("pNameLabel"));

        verticalLayout->addWidget(pNameLabel);

        bRateLabel = new QLabel(layoutWidget);
        bRateLabel->setObjectName(QStringLiteral("bRateLabel"));

        verticalLayout->addWidget(bRateLabel);

        dBitsLabel = new QLabel(layoutWidget);
        dBitsLabel->setObjectName(QStringLiteral("dBitsLabel"));

        verticalLayout->addWidget(dBitsLabel);

        pBitsLabel = new QLabel(layoutWidget);
        pBitsLabel->setObjectName(QStringLiteral("pBitsLabel"));

        verticalLayout->addWidget(pBitsLabel);

        sBitsLabel = new QLabel(layoutWidget);
        sBitsLabel->setObjectName(QStringLiteral("sBitsLabel"));

        verticalLayout->addWidget(sBitsLabel);

        fContLabel = new QLabel(layoutWidget);
        fContLabel->setObjectName(QStringLiteral("fContLabel"));

        verticalLayout->addWidget(fContLabel);


        verticalLayout_4->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(verticalLayout_4);

        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(630, 120, 411, 73));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        timeLabel = new QLabel(layoutWidget1);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QSizePolicy sizePolicy12(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy12);

        horizontalLayout_16->addWidget(timeLabel);

        timeOutputLabel = new QLabel(layoutWidget1);
        timeOutputLabel->setObjectName(QStringLiteral("timeOutputLabel"));

        horizontalLayout_16->addWidget(timeOutputLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(830, 200, 80, 21));
        mpuStartButton = new QPushButton(tab_2);
        mpuStartButton->setObjectName(QStringLiteral("mpuStartButton"));
        mpuStartButton->setGeometry(QRect(630, 200, 78, 23));
        sndtoGrph = new QPushButton(tab_2);
        sndtoGrph->setObjectName(QStringLiteral("sndtoGrph"));
        sndtoGrph->setGeometry(QRect(710, 200, 111, 23));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(960, 200, 221, 121));
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        latLabel = new QLabel(groupBox_7);
        latLabel->setObjectName(QStringLiteral("latLabel"));
        QSizePolicy sizePolicy13(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(latLabel->sizePolicy().hasHeightForWidth());
        latLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_26->addWidget(latLabel);

        latDisplay = new QLabel(groupBox_7);
        latDisplay->setObjectName(QStringLiteral("latDisplay"));
        QSizePolicy sizePolicy14(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy14.setHorizontalStretch(0);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(latDisplay->sizePolicy().hasHeightForWidth());
        latDisplay->setSizePolicy(sizePolicy14);

        horizontalLayout_26->addWidget(latDisplay);


        gridLayout_7->addLayout(horizontalLayout_26, 0, 0, 1, 1);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        lonLabel = new QLabel(groupBox_7);
        lonLabel->setObjectName(QStringLiteral("lonLabel"));
        sizePolicy13.setHeightForWidth(lonLabel->sizePolicy().hasHeightForWidth());
        lonLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_25->addWidget(lonLabel);

        longDisplay = new QLabel(groupBox_7);
        longDisplay->setObjectName(QStringLiteral("longDisplay"));
        sizePolicy14.setHeightForWidth(longDisplay->sizePolicy().hasHeightForWidth());
        longDisplay->setSizePolicy(sizePolicy14);

        horizontalLayout_25->addWidget(longDisplay);


        gridLayout_7->addLayout(horizontalLayout_25, 1, 0, 1, 1);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        gpsAltLabel = new QLabel(groupBox_7);
        gpsAltLabel->setObjectName(QStringLiteral("gpsAltLabel"));
        sizePolicy13.setHeightForWidth(gpsAltLabel->sizePolicy().hasHeightForWidth());
        gpsAltLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_24->addWidget(gpsAltLabel);

        gpsAltDisplay = new QLabel(groupBox_7);
        gpsAltDisplay->setObjectName(QStringLiteral("gpsAltDisplay"));
        sizePolicy14.setHeightForWidth(gpsAltDisplay->sizePolicy().hasHeightForWidth());
        gpsAltDisplay->setSizePolicy(sizePolicy14);

        horizontalLayout_24->addWidget(gpsAltDisplay);


        gridLayout_7->addLayout(horizontalLayout_24, 2, 0, 1, 1);

        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(1050, 120, 131, 56));
        gridLayout_10 = new QGridLayout(groupBox_8);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        altimeterLabel = new QLabel(groupBox_8);
        altimeterLabel->setObjectName(QStringLiteral("altimeterLabel"));
        sizePolicy13.setHeightForWidth(altimeterLabel->sizePolicy().hasHeightForWidth());
        altimeterLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_15->addWidget(altimeterLabel);

        altimeterDisplay = new QLabel(groupBox_8);
        altimeterDisplay->setObjectName(QStringLiteral("altimeterDisplay"));

        horizontalLayout_15->addWidget(altimeterDisplay);


        gridLayout_10->addLayout(horizontalLayout_15, 0, 0, 1, 1);

        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(631, 1, 541, 100));
        gridLayout_9 = new QGridLayout(layoutWidget2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 30, 102, 15));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy12.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy12);

        horizontalLayout_6->addWidget(label);

        accXDisplay = new QLabel(layoutWidget3);
        accXDisplay->setObjectName(QStringLiteral("accXDisplay"));

        horizontalLayout_6->addWidget(accXDisplay);

        layoutWidget4 = new QWidget(groupBox);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 50, 102, 15));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        accYlabel = new QLabel(layoutWidget4);
        accYlabel->setObjectName(QStringLiteral("accYlabel"));
        sizePolicy12.setHeightForWidth(accYlabel->sizePolicy().hasHeightForWidth());
        accYlabel->setSizePolicy(sizePolicy12);

        horizontalLayout_7->addWidget(accYlabel);

        accYDisplay = new QLabel(layoutWidget4);
        accYDisplay->setObjectName(QStringLiteral("accYDisplay"));

        horizontalLayout_7->addWidget(accYDisplay);

        layoutWidget5 = new QWidget(groupBox);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 70, 102, 15));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        accZlabel = new QLabel(layoutWidget5);
        accZlabel->setObjectName(QStringLiteral("accZlabel"));
        sizePolicy12.setHeightForWidth(accZlabel->sizePolicy().hasHeightForWidth());
        accZlabel->setSizePolicy(sizePolicy12);

        horizontalLayout_8->addWidget(accZlabel);

        accZDisplay = new QLabel(layoutWidget5);
        accZDisplay->setObjectName(QStringLiteral("accZDisplay"));

        horizontalLayout_8->addWidget(accZDisplay);


        gridLayout_9->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(layoutWidget2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 30, 102, 15));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        gyroXlabel = new QLabel(layoutWidget_2);
        gyroXlabel->setObjectName(QStringLiteral("gyroXlabel"));
        sizePolicy12.setHeightForWidth(gyroXlabel->sizePolicy().hasHeightForWidth());
        gyroXlabel->setSizePolicy(sizePolicy12);

        horizontalLayout_9->addWidget(gyroXlabel);

        gyroXDisplay = new QLabel(layoutWidget_2);
        gyroXDisplay->setObjectName(QStringLiteral("gyroXDisplay"));

        horizontalLayout_9->addWidget(gyroXDisplay);

        layoutWidget_3 = new QWidget(groupBox_2);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 50, 102, 15));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        gytoYlabel = new QLabel(layoutWidget_3);
        gytoYlabel->setObjectName(QStringLiteral("gytoYlabel"));
        sizePolicy12.setHeightForWidth(gytoYlabel->sizePolicy().hasHeightForWidth());
        gytoYlabel->setSizePolicy(sizePolicy12);

        horizontalLayout_10->addWidget(gytoYlabel);

        gyroYDisplay = new QLabel(layoutWidget_3);
        gyroYDisplay->setObjectName(QStringLiteral("gyroYDisplay"));

        horizontalLayout_10->addWidget(gyroYDisplay);

        layoutWidget_4 = new QWidget(groupBox_2);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 70, 102, 15));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        gyroZlabel = new QLabel(layoutWidget_4);
        gyroZlabel->setObjectName(QStringLiteral("gyroZlabel"));
        sizePolicy12.setHeightForWidth(gyroZlabel->sizePolicy().hasHeightForWidth());
        gyroZlabel->setSizePolicy(sizePolicy12);

        horizontalLayout_11->addWidget(gyroZlabel);

        gyroZDisplay = new QLabel(layoutWidget_4);
        gyroZDisplay->setObjectName(QStringLiteral("gyroZDisplay"));

        horizontalLayout_11->addWidget(gyroZDisplay);


        gridLayout_9->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(layoutWidget2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        layoutWidget_5 = new QWidget(groupBox_3);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 30, 102, 15));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        magXlabel = new QLabel(layoutWidget_5);
        magXlabel->setObjectName(QStringLiteral("magXlabel"));
        sizePolicy12.setHeightForWidth(magXlabel->sizePolicy().hasHeightForWidth());
        magXlabel->setSizePolicy(sizePolicy12);

        horizontalLayout_12->addWidget(magXlabel);

        magXDisplay = new QLabel(layoutWidget_5);
        magXDisplay->setObjectName(QStringLiteral("magXDisplay"));

        horizontalLayout_12->addWidget(magXDisplay);

        layoutWidget_6 = new QWidget(groupBox_3);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 50, 102, 15));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        magYlabel = new QLabel(layoutWidget_6);
        magYlabel->setObjectName(QStringLiteral("magYlabel"));
        sizePolicy12.setHeightForWidth(magYlabel->sizePolicy().hasHeightForWidth());
        magYlabel->setSizePolicy(sizePolicy12);

        horizontalLayout_13->addWidget(magYlabel);

        magYDisplay = new QLabel(layoutWidget_6);
        magYDisplay->setObjectName(QStringLiteral("magYDisplay"));

        horizontalLayout_13->addWidget(magYDisplay);

        layoutWidget_7 = new QWidget(groupBox_3);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 70, 102, 15));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        magZlabel = new QLabel(layoutWidget_7);
        magZlabel->setObjectName(QStringLiteral("magZlabel"));
        sizePolicy12.setHeightForWidth(magZlabel->sizePolicy().hasHeightForWidth());
        magZlabel->setSizePolicy(sizePolicy12);

        horizontalLayout_14->addWidget(magZlabel);

        magZDisplay = new QLabel(layoutWidget_7);
        magZDisplay->setObjectName(QStringLiteral("magZDisplay"));

        horizontalLayout_14->addWidget(magZDisplay);


        gridLayout_9->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox_6 = new QGroupBox(layoutWidget2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        highGXLabel = new QLabel(groupBox_6);
        highGXLabel->setObjectName(QStringLiteral("highGXLabel"));
        sizePolicy13.setHeightForWidth(highGXLabel->sizePolicy().hasHeightForWidth());
        highGXLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_20->addWidget(highGXLabel);

        highGXDisplay = new QLabel(groupBox_6);
        highGXDisplay->setObjectName(QStringLiteral("highGXDisplay"));
        sizePolicy14.setHeightForWidth(highGXDisplay->sizePolicy().hasHeightForWidth());
        highGXDisplay->setSizePolicy(sizePolicy14);

        horizontalLayout_20->addWidget(highGXDisplay);


        gridLayout_6->addLayout(horizontalLayout_20, 0, 0, 1, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        highGYLabel_2 = new QLabel(groupBox_6);
        highGYLabel_2->setObjectName(QStringLiteral("highGYLabel_2"));
        sizePolicy13.setHeightForWidth(highGYLabel_2->sizePolicy().hasHeightForWidth());
        highGYLabel_2->setSizePolicy(sizePolicy13);

        horizontalLayout_22->addWidget(highGYLabel_2);

        highGYDisplay = new QLabel(groupBox_6);
        highGYDisplay->setObjectName(QStringLiteral("highGYDisplay"));
        sizePolicy14.setHeightForWidth(highGYDisplay->sizePolicy().hasHeightForWidth());
        highGYDisplay->setSizePolicy(sizePolicy14);

        horizontalLayout_22->addWidget(highGYDisplay);


        gridLayout_6->addLayout(horizontalLayout_22, 1, 0, 1, 1);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        highGZLabel = new QLabel(groupBox_6);
        highGZLabel->setObjectName(QStringLiteral("highGZLabel"));
        sizePolicy13.setHeightForWidth(highGZLabel->sizePolicy().hasHeightForWidth());
        highGZLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_23->addWidget(highGZLabel);

        highGZDisplay = new QLabel(groupBox_6);
        highGZDisplay->setObjectName(QStringLiteral("highGZDisplay"));
        sizePolicy14.setHeightForWidth(highGZDisplay->sizePolicy().hasHeightForWidth());
        highGZDisplay->setSizePolicy(sizePolicy14);

        horizontalLayout_23->addWidget(highGZDisplay);


        gridLayout_6->addLayout(horizontalLayout_23, 2, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_6, 0, 3, 1, 1);

        groupBox_9 = new QGroupBox(tab_2);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(70, 280, 711, 231));
        horizontalLayout_29 = new QHBoxLayout(groupBox_9);
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        groupBox_10 = new QGroupBox(groupBox_9);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        gridLayout_11 = new QGridLayout(groupBox_10);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        scaledAccXLabel = new QLabel(groupBox_10);
        scaledAccXLabel->setObjectName(QStringLiteral("scaledAccXLabel"));
        sizePolicy13.setHeightForWidth(scaledAccXLabel->sizePolicy().hasHeightForWidth());
        scaledAccXLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_30->addWidget(scaledAccXLabel);

        scaledAccXDisp = new QLabel(groupBox_10);
        scaledAccXDisp->setObjectName(QStringLiteral("scaledAccXDisp"));
        sizePolicy14.setHeightForWidth(scaledAccXDisp->sizePolicy().hasHeightForWidth());
        scaledAccXDisp->setSizePolicy(sizePolicy14);

        horizontalLayout_30->addWidget(scaledAccXDisp);


        gridLayout_11->addLayout(horizontalLayout_30, 0, 0, 1, 1);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        scaledAccYLabel = new QLabel(groupBox_10);
        scaledAccYLabel->setObjectName(QStringLiteral("scaledAccYLabel"));
        sizePolicy13.setHeightForWidth(scaledAccYLabel->sizePolicy().hasHeightForWidth());
        scaledAccYLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_31->addWidget(scaledAccYLabel);

        scaledAccYDisp = new QLabel(groupBox_10);
        scaledAccYDisp->setObjectName(QStringLiteral("scaledAccYDisp"));
        sizePolicy14.setHeightForWidth(scaledAccYDisp->sizePolicy().hasHeightForWidth());
        scaledAccYDisp->setSizePolicy(sizePolicy14);

        horizontalLayout_31->addWidget(scaledAccYDisp);


        gridLayout_11->addLayout(horizontalLayout_31, 1, 0, 1, 1);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        scaledAccZLabel = new QLabel(groupBox_10);
        scaledAccZLabel->setObjectName(QStringLiteral("scaledAccZLabel"));
        sizePolicy13.setHeightForWidth(scaledAccZLabel->sizePolicy().hasHeightForWidth());
        scaledAccZLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_32->addWidget(scaledAccZLabel);

        scaledAccZDisp = new QLabel(groupBox_10);
        scaledAccZDisp->setObjectName(QStringLiteral("scaledAccZDisp"));
        sizePolicy14.setHeightForWidth(scaledAccZDisp->sizePolicy().hasHeightForWidth());
        scaledAccZDisp->setSizePolicy(sizePolicy14);

        horizontalLayout_32->addWidget(scaledAccZDisp);


        gridLayout_11->addLayout(horizontalLayout_32, 2, 0, 1, 1);


        horizontalLayout_29->addWidget(groupBox_10);

        groupBox_11 = new QGroupBox(groupBox_9);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        gridLayout_12 = new QGridLayout(groupBox_11);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        scaledGyroXLabel = new QLabel(groupBox_11);
        scaledGyroXLabel->setObjectName(QStringLiteral("scaledGyroXLabel"));
        sizePolicy13.setHeightForWidth(scaledGyroXLabel->sizePolicy().hasHeightForWidth());
        scaledGyroXLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_33->addWidget(scaledGyroXLabel);

        scaledGyroXDisp = new QLabel(groupBox_11);
        scaledGyroXDisp->setObjectName(QStringLiteral("scaledGyroXDisp"));
        sizePolicy14.setHeightForWidth(scaledGyroXDisp->sizePolicy().hasHeightForWidth());
        scaledGyroXDisp->setSizePolicy(sizePolicy14);

        horizontalLayout_33->addWidget(scaledGyroXDisp);


        gridLayout_12->addLayout(horizontalLayout_33, 0, 0, 1, 1);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        scaledGyroYLabel = new QLabel(groupBox_11);
        scaledGyroYLabel->setObjectName(QStringLiteral("scaledGyroYLabel"));
        sizePolicy13.setHeightForWidth(scaledGyroYLabel->sizePolicy().hasHeightForWidth());
        scaledGyroYLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_34->addWidget(scaledGyroYLabel);

        scaledGyroYDisp = new QLabel(groupBox_11);
        scaledGyroYDisp->setObjectName(QStringLiteral("scaledGyroYDisp"));
        sizePolicy14.setHeightForWidth(scaledGyroYDisp->sizePolicy().hasHeightForWidth());
        scaledGyroYDisp->setSizePolicy(sizePolicy14);

        horizontalLayout_34->addWidget(scaledGyroYDisp);


        gridLayout_12->addLayout(horizontalLayout_34, 1, 0, 1, 1);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        scaledGyroZLabel = new QLabel(groupBox_11);
        scaledGyroZLabel->setObjectName(QStringLiteral("scaledGyroZLabel"));
        sizePolicy13.setHeightForWidth(scaledGyroZLabel->sizePolicy().hasHeightForWidth());
        scaledGyroZLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_35->addWidget(scaledGyroZLabel);

        scaledGyroZDisp = new QLabel(groupBox_11);
        scaledGyroZDisp->setObjectName(QStringLiteral("scaledGyroZDisp"));
        sizePolicy14.setHeightForWidth(scaledGyroZDisp->sizePolicy().hasHeightForWidth());
        scaledGyroZDisp->setSizePolicy(sizePolicy14);

        horizontalLayout_35->addWidget(scaledGyroZDisp);


        gridLayout_12->addLayout(horizontalLayout_35, 2, 0, 1, 1);


        horizontalLayout_29->addWidget(groupBox_11);

        groupBox_12 = new QGroupBox(groupBox_9);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        gridLayout_13 = new QGridLayout(groupBox_12);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        scaledMagXLabel = new QLabel(groupBox_12);
        scaledMagXLabel->setObjectName(QStringLiteral("scaledMagXLabel"));
        sizePolicy13.setHeightForWidth(scaledMagXLabel->sizePolicy().hasHeightForWidth());
        scaledMagXLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_36->addWidget(scaledMagXLabel);

        scaledMagXDisp = new QLabel(groupBox_12);
        scaledMagXDisp->setObjectName(QStringLiteral("scaledMagXDisp"));
        sizePolicy14.setHeightForWidth(scaledMagXDisp->sizePolicy().hasHeightForWidth());
        scaledMagXDisp->setSizePolicy(sizePolicy14);

        horizontalLayout_36->addWidget(scaledMagXDisp);


        gridLayout_13->addLayout(horizontalLayout_36, 0, 0, 1, 1);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        scaledMagYLabel = new QLabel(groupBox_12);
        scaledMagYLabel->setObjectName(QStringLiteral("scaledMagYLabel"));
        sizePolicy13.setHeightForWidth(scaledMagYLabel->sizePolicy().hasHeightForWidth());
        scaledMagYLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_37->addWidget(scaledMagYLabel);

        scaledMagYDisp = new QLabel(groupBox_12);
        scaledMagYDisp->setObjectName(QStringLiteral("scaledMagYDisp"));
        sizePolicy14.setHeightForWidth(scaledMagYDisp->sizePolicy().hasHeightForWidth());
        scaledMagYDisp->setSizePolicy(sizePolicy14);

        horizontalLayout_37->addWidget(scaledMagYDisp);


        gridLayout_13->addLayout(horizontalLayout_37, 1, 0, 1, 1);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        scaledMagZLabel = new QLabel(groupBox_12);
        scaledMagZLabel->setObjectName(QStringLiteral("scaledMagZLabel"));
        sizePolicy13.setHeightForWidth(scaledMagZLabel->sizePolicy().hasHeightForWidth());
        scaledMagZLabel->setSizePolicy(sizePolicy13);

        horizontalLayout_38->addWidget(scaledMagZLabel);

        scaledMagZDisp = new QLabel(groupBox_12);
        scaledMagZDisp->setObjectName(QStringLiteral("scaledMagZDisp"));
        sizePolicy14.setHeightForWidth(scaledMagZDisp->sizePolicy().hasHeightForWidth());
        scaledMagZDisp->setSizePolicy(sizePolicy14);

        horizontalLayout_38->addWidget(scaledMagZDisp);


        gridLayout_13->addLayout(horizontalLayout_38, 2, 0, 1, 1);


        horizontalLayout_29->addWidget(groupBox_12);

        mavProxyShowButton = new QPushButton(tab_2);
        mavProxyShowButton->setObjectName(QStringLiteral("mavProxyShowButton"));
        mavProxyShowButton->setGeometry(QRect(820, 270, 101, 21));
        expoDemoCheckBox = new QCheckBox(tab_2);
        expoDemoCheckBox->setObjectName(QStringLiteral("expoDemoCheckBox"));
        expoDemoCheckBox->setGeometry(QRect(630, 230, 211, 21));
        includeHistoric = new QCheckBox(tab_2);
        includeHistoric->setObjectName(QStringLiteral("includeHistoric"));
        includeHistoric->setGeometry(QRect(630, 250, 321, 17));
        receivingCheckBox = new QCheckBox(tab_2);
        receivingCheckBox->setObjectName(QStringLiteral("receivingCheckBox"));
        receivingCheckBox->setGeometry(QRect(880, 380, 70, 17));
        receivingCheckBox->setChecked(false);
        tabWidget->addTab(tab_2, QString());

        verticalLayout_8->addWidget(tabWidget);


        verticalLayout_6->addLayout(verticalLayout_8);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1340, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuConfigure = new QMenu(menuBar);
        menuConfigure->setObjectName(QStringLiteral("menuConfigure"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuConfigure->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(action_New);
        menuFile->addAction(action_Save);
        menuFile->addAction(action_Open);
        menuFile->addSeparator();
        menuFile->addAction(actionRestart);
        menuFile->addAction(actionQuit);
        menuConfigure->addAction(actionComm_Settings);
        menuHelp->addAction(action_About);
        menuHelp->addAction(actionAbout_QT);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RADAV - Alpha", Q_NULLPTR));
        actionComm_Settings->setText(QApplication::translate("MainWindow", "Co&mm Settings...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionComm_Settings->setToolTip(QApplication::translate("MainWindow", "Open communication settings window", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_About->setText(QApplication::translate("MainWindow", "&About...", Q_NULLPTR));
        actionAbout_QT->setText(QApplication::translate("MainWindow", "About &QT...", Q_NULLPTR));
        action_New->setText(QApplication::translate("MainWindow", "&New", Q_NULLPTR));
        action_Save->setText(QApplication::translate("MainWindow", "&Save", Q_NULLPTR));
        action_Open->setText(QApplication::translate("MainWindow", "&Open", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to device", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from device", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionShow_Graphs->setText(QApplication::translate("MainWindow", "Show Graphs", Q_NULLPTR));
        actionRestart->setText(QApplication::translate("MainWindow", "Restart", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Mission Time:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "HH", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "MM", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "SS", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "MS", Q_NULLPTR));
        apo_label_3->setText(QApplication::translate("MainWindow", "Landing", Q_NULLPTR));
        apo_label_2->setText(QApplication::translate("MainWindow", "Descent", Q_NULLPTR));
        launch_time_label->setText(QString());
        apo_label->setText(QApplication::translate("MainWindow", "Apogee", Q_NULLPTR));
        apo_time_label->setText(QString());
        launch_label->setText(QApplication::translate("MainWindow", "Launch", Q_NULLPTR));
        apo_label_4->setText(QApplication::translate("MainWindow", "Ascent", Q_NULLPTR));
        landing_time_label->setText(QString());
        ascent_label->setText(QString());
        descent_label->setText(QString());
        landingLat->setText(QString());
        landingLon->setText(QString());
        apo_label_5->setText(QApplication::translate("MainWindow", "Final Location", Q_NULLPTR));
        start_stop->setText(QApplication::translate("MainWindow", "LAUNCH", Q_NULLPTR));
        label_25->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Altitude and Speed", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Current Altitude (ft)", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Max Altitude (ft)", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Current Velocity (ft/s)", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Max Velocity (ft/s)", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Acceleration ft/s^2", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "G Force (G)", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Max Gs", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "High-G Force (G)", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Max Hig- Gs", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Orientation", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Pitch", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Roll", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Yaw", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Pitch Rate", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Roll Rate", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Yaw Rate", Q_NULLPTR));
        gps_status->setText(QApplication::translate("MainWindow", "GPS status: NO GPS LOCK", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Map Type", Q_NULLPTR));
        circleCheckBox->setText(QApplication::translate("MainWindow", "Range Circle", Q_NULLPTR));
        focusRocketCheckBox->setText(QApplication::translate("MainWindow", "Focus Rocket", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Zoom Level", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "Latitude:", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "Longitude:", Q_NULLPTR));
        decMinSecLat->setText(QApplication::translate("MainWindow", "----", Q_NULLPTR));
        decMinSecLon->setText(QApplication::translate("MainWindow", "----", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Data", Q_NULLPTR));
        sndButton->setText(QApplication::translate("MainWindow", "Send Text", Q_NULLPTR));
        rxTextLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pNameLabel->setText(QApplication::translate("MainWindow", "Port name: ", Q_NULLPTR));
        bRateLabel->setText(QApplication::translate("MainWindow", "Baud Rate:", Q_NULLPTR));
        dBitsLabel->setText(QApplication::translate("MainWindow", "Data Bits:", Q_NULLPTR));
        pBitsLabel->setText(QApplication::translate("MainWindow", "Parity Bits:", Q_NULLPTR));
        sBitsLabel->setText(QApplication::translate("MainWindow", "Stop Bits:", Q_NULLPTR));
        fContLabel->setText(QApplication::translate("MainWindow", "Flow Control: ", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("MainWindow", "Time (ms) :", Q_NULLPTR));
        timeOutputLabel->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        mpuStartButton->setText(QApplication::translate("MainWindow", "MPU-925 Start", Q_NULLPTR));
        sndtoGrph->setText(QApplication::translate("MainWindow", "Send Data to Graph", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "GPS Data", Q_NULLPTR));
        latLabel->setText(QApplication::translate("MainWindow", "Latitude: ", Q_NULLPTR));
        latDisplay->setText(QString());
        lonLabel->setText(QApplication::translate("MainWindow", "Longitude: ", Q_NULLPTR));
        longDisplay->setText(QString());
        gpsAltLabel->setText(QApplication::translate("MainWindow", "Altitude: ", Q_NULLPTR));
        gpsAltDisplay->setText(QString());
        groupBox_8->setTitle(QApplication::translate("MainWindow", "HP Altimeter", Q_NULLPTR));
        altimeterLabel->setText(QApplication::translate("MainWindow", "HP Altimeter :", Q_NULLPTR));
        altimeterDisplay->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Accelerometer", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "X :", Q_NULLPTR));
        accXDisplay->setText(QString());
        accYlabel->setText(QApplication::translate("MainWindow", "Y :", Q_NULLPTR));
        accYDisplay->setText(QString());
        accZlabel->setText(QApplication::translate("MainWindow", "Z :", Q_NULLPTR));
        accZDisplay->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Gyroscope", Q_NULLPTR));
        gyroXlabel->setText(QApplication::translate("MainWindow", "X :", Q_NULLPTR));
        gyroXDisplay->setText(QString());
        gytoYlabel->setText(QApplication::translate("MainWindow", "Y :", Q_NULLPTR));
        gyroYDisplay->setText(QString());
        gyroZlabel->setText(QApplication::translate("MainWindow", "Z :", Q_NULLPTR));
        gyroZDisplay->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Magnetometer", Q_NULLPTR));
        magXlabel->setText(QApplication::translate("MainWindow", "X :", Q_NULLPTR));
        magXDisplay->setText(QString());
        magYlabel->setText(QApplication::translate("MainWindow", "Y :", Q_NULLPTR));
        magYDisplay->setText(QString());
        magZlabel->setText(QApplication::translate("MainWindow", "Z :", Q_NULLPTR));
        magZDisplay->setText(QString());
        groupBox_6->setTitle(QApplication::translate("MainWindow", "High Accelerometer", Q_NULLPTR));
        highGXLabel->setText(QApplication::translate("MainWindow", "X: ", Q_NULLPTR));
        highGXDisplay->setText(QString());
        highGYLabel_2->setText(QApplication::translate("MainWindow", "Y: ", Q_NULLPTR));
        highGYDisplay->setText(QString());
        highGZLabel->setText(QApplication::translate("MainWindow", "Z: ", Q_NULLPTR));
        highGZDisplay->setText(QString());
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Scaled Sensor Data from MPU-9250", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Accelerometer Scaled (g force)", Q_NULLPTR));
        scaledAccXLabel->setText(QApplication::translate("MainWindow", "X: ", Q_NULLPTR));
        scaledAccXDisp->setText(QString());
        scaledAccYLabel->setText(QApplication::translate("MainWindow", "Y: ", Q_NULLPTR));
        scaledAccYDisp->setText(QString());
        scaledAccZLabel->setText(QApplication::translate("MainWindow", "Z: ", Q_NULLPTR));
        scaledAccZDisp->setText(QString());
        groupBox_11->setTitle(QApplication::translate("MainWindow", "Gyroscope Scaled (Deg/Sec)", Q_NULLPTR));
        scaledGyroXLabel->setText(QApplication::translate("MainWindow", "X: ", Q_NULLPTR));
        scaledGyroXDisp->setText(QString());
        scaledGyroYLabel->setText(QApplication::translate("MainWindow", "Y: ", Q_NULLPTR));
        scaledGyroYDisp->setText(QString());
        scaledGyroZLabel->setText(QApplication::translate("MainWindow", "Z: ", Q_NULLPTR));
        scaledGyroZDisp->setText(QString());
        groupBox_12->setTitle(QApplication::translate("MainWindow", "Magnetometer Scaled (Micro-Teslas)", Q_NULLPTR));
        scaledMagXLabel->setText(QApplication::translate("MainWindow", "X: ", Q_NULLPTR));
        scaledMagXDisp->setText(QString());
        scaledMagYLabel->setText(QApplication::translate("MainWindow", "Y: ", Q_NULLPTR));
        scaledMagYDisp->setText(QString());
        scaledMagZLabel->setText(QApplication::translate("MainWindow", "Z: ", Q_NULLPTR));
        scaledMagZDisp->setText(QString());
        mavProxyShowButton->setText(QApplication::translate("MainWindow", "Show MavProxy", Q_NULLPTR));
        expoDemoCheckBox->setText(QApplication::translate("MainWindow", "Expo Demo (Check before loading CSV)", Q_NULLPTR));
        includeHistoric->setText(QApplication::translate("MainWindow", "Include Historic Data", Q_NULLPTR));
        receivingCheckBox->setText(QApplication::translate("MainWindow", "Receiving", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Serial Devices", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", Q_NULLPTR));
        menuConfigure->setTitle(QApplication::translate("MainWindow", "&Configure ", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

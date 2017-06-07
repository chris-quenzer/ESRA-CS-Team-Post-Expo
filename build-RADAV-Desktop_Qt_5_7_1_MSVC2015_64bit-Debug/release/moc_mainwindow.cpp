/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RADAV_APPLICATION/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[56];
    char stringdata0[999];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "mapTypeChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "latitudeChanged"
QT_MOC_LITERAL(4, 43, 16), // "longitudeChanged"
QT_MOC_LITERAL(5, 60, 11), // "zoomChanged"
QT_MOC_LITERAL(6, 72, 13), // "circleChanged"
QT_MOC_LITERAL(7, 86, 18), // "focusOptionChanged"
QT_MOC_LITERAL(8, 105, 18), // "focusRocketChanged"
QT_MOC_LITERAL(9, 124, 17), // "rocketPathChanged"
QT_MOC_LITERAL(10, 142, 11), // "NoseAviByte"
QT_MOC_LITERAL(11, 154, 7), // "aboutQt"
QT_MOC_LITERAL(12, 162, 5), // "about"
QT_MOC_LITERAL(13, 168, 32), // "on_actionComm_Settings_triggered"
QT_MOC_LITERAL(14, 201, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(15, 225, 27), // "on_actionAbout_QT_triggered"
QT_MOC_LITERAL(16, 253, 14), // "openSerialPort"
QT_MOC_LITERAL(17, 268, 15), // "closeSerialPort"
QT_MOC_LITERAL(18, 284, 8), // "readData"
QT_MOC_LITERAL(19, 293, 11), // "handleError"
QT_MOC_LITERAL(20, 305, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(21, 334, 5), // "error"
QT_MOC_LITERAL(22, 340, 25), // "on_action_About_triggered"
QT_MOC_LITERAL(23, 366, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(24, 393, 29), // "on_actionDisconnect_triggered"
QT_MOC_LITERAL(25, 423, 24), // "on_action_Open_triggered"
QT_MOC_LITERAL(26, 448, 25), // "on_mpuStartButton_clicked"
QT_MOC_LITERAL(27, 474, 20), // "on_sndtoGrph_clicked"
QT_MOC_LITERAL(28, 495, 23), // "on_action_New_triggered"
QT_MOC_LITERAL(29, 519, 21), // "on_start_stop_clicked"
QT_MOC_LITERAL(30, 541, 16), // "realtimeDataSlot"
QT_MOC_LITERAL(31, 558, 26), // "on_actionRestart_triggered"
QT_MOC_LITERAL(32, 585, 26), // "on_includeHistoric_toggled"
QT_MOC_LITERAL(33, 612, 7), // "checked"
QT_MOC_LITERAL(34, 620, 29), // "on_mavProxyShowButton_clicked"
QT_MOC_LITERAL(35, 650, 27), // "on_expoDemoCheckBox_clicked"
QT_MOC_LITERAL(36, 678, 25), // "on_mapSelect_valueChanged"
QT_MOC_LITERAL(37, 704, 4), // "arg1"
QT_MOC_LITERAL(38, 709, 26), // "on_zoomSlider_valueChanged"
QT_MOC_LITERAL(39, 736, 5), // "value"
QT_MOC_LITERAL(40, 742, 25), // "on_circleCheckBox_clicked"
QT_MOC_LITERAL(41, 768, 30), // "on_focusRocketCheckBox_clicked"
QT_MOC_LITERAL(42, 799, 16), // "map_focus_update"
QT_MOC_LITERAL(43, 816, 15), // "convertGPSCoord"
QT_MOC_LITERAL(44, 832, 7), // "degrees"
QT_MOC_LITERAL(45, 840, 7), // "minutes"
QT_MOC_LITERAL(46, 848, 16), // "updateRocketPath"
QT_MOC_LITERAL(47, 865, 10), // "randomPath"
QT_MOC_LITERAL(48, 876, 11), // "get_mapType"
QT_MOC_LITERAL(49, 888, 8), // "get_zoom"
QT_MOC_LITERAL(50, 897, 7), // "get_lat"
QT_MOC_LITERAL(51, 905, 8), // "get_long"
QT_MOC_LITERAL(52, 914, 15), // "get_circleState"
QT_MOC_LITERAL(53, 930, 20), // "get_focusRocketState"
QT_MOC_LITERAL(54, 951, 14), // "get_rocketPath"
QT_MOC_LITERAL(55, 966, 32) // "QList<MainWindow::GPSCoordinate>"

    },
    "MainWindow\0mapTypeChanged\0\0latitudeChanged\0"
    "longitudeChanged\0zoomChanged\0circleChanged\0"
    "focusOptionChanged\0focusRocketChanged\0"
    "rocketPathChanged\0NoseAviByte\0aboutQt\0"
    "about\0on_actionComm_Settings_triggered\0"
    "on_actionQuit_triggered\0"
    "on_actionAbout_QT_triggered\0openSerialPort\0"
    "closeSerialPort\0readData\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "on_action_About_triggered\0"
    "on_actionConnect_triggered\0"
    "on_actionDisconnect_triggered\0"
    "on_action_Open_triggered\0"
    "on_mpuStartButton_clicked\0"
    "on_sndtoGrph_clicked\0on_action_New_triggered\0"
    "on_start_stop_clicked\0realtimeDataSlot\0"
    "on_actionRestart_triggered\0"
    "on_includeHistoric_toggled\0checked\0"
    "on_mavProxyShowButton_clicked\0"
    "on_expoDemoCheckBox_clicked\0"
    "on_mapSelect_valueChanged\0arg1\0"
    "on_zoomSlider_valueChanged\0value\0"
    "on_circleCheckBox_clicked\0"
    "on_focusRocketCheckBox_clicked\0"
    "map_focus_update\0convertGPSCoord\0"
    "degrees\0minutes\0updateRocketPath\0"
    "randomPath\0get_mapType\0get_zoom\0get_lat\0"
    "get_long\0get_circleState\0get_focusRocketState\0"
    "get_rocketPath\0QList<MainWindow::GPSCoordinate>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  244,    2, 0x06 /* Public */,
       3,    0,  245,    2, 0x06 /* Public */,
       4,    0,  246,    2, 0x06 /* Public */,
       5,    0,  247,    2, 0x06 /* Public */,
       6,    0,  248,    2, 0x06 /* Public */,
       7,    0,  249,    2, 0x06 /* Public */,
       8,    0,  250,    2, 0x06 /* Public */,
       9,    0,  251,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  252,    2, 0x08 /* Private */,
      11,    0,  253,    2, 0x08 /* Private */,
      12,    0,  254,    2, 0x08 /* Private */,
      13,    0,  255,    2, 0x08 /* Private */,
      14,    0,  256,    2, 0x08 /* Private */,
      15,    0,  257,    2, 0x08 /* Private */,
      16,    0,  258,    2, 0x08 /* Private */,
      17,    0,  259,    2, 0x08 /* Private */,
      18,    0,  260,    2, 0x08 /* Private */,
      19,    1,  261,    2, 0x08 /* Private */,
      22,    0,  264,    2, 0x08 /* Private */,
      23,    0,  265,    2, 0x08 /* Private */,
      24,    0,  266,    2, 0x08 /* Private */,
      25,    0,  267,    2, 0x08 /* Private */,
      26,    0,  268,    2, 0x08 /* Private */,
      27,    0,  269,    2, 0x08 /* Private */,
      28,    0,  270,    2, 0x08 /* Private */,
      29,    0,  271,    2, 0x08 /* Private */,
      30,    0,  272,    2, 0x08 /* Private */,
      31,    0,  273,    2, 0x08 /* Private */,
      32,    1,  274,    2, 0x08 /* Private */,
      34,    0,  277,    2, 0x08 /* Private */,
      35,    1,  278,    2, 0x08 /* Private */,
      36,    1,  281,    2, 0x08 /* Private */,
      38,    1,  284,    2, 0x0a /* Public */,
      40,    1,  287,    2, 0x0a /* Public */,
      41,    1,  290,    2, 0x0a /* Public */,
      42,    0,  293,    2, 0x0a /* Public */,
      43,    2,  294,    2, 0x0a /* Public */,
      46,    0,  299,    2, 0x0a /* Public */,
      47,    0,  300,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      48,    0,  301,    2, 0x02 /* Public */,
      49,    0,  302,    2, 0x02 /* Public */,
      50,    0,  303,    2, 0x02 /* Public */,
      51,    0,  304,    2, 0x02 /* Public */,
      52,    0,  305,    2, 0x02 /* Public */,
      53,    0,  306,    2, 0x02 /* Public */,
      54,    0,  307,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void,
    QMetaType::Double, QMetaType::Double, QMetaType::Double,   44,   45,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Bool,
    QMetaType::Bool,
    0x80000000 | 55,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mapTypeChanged(); break;
        case 1: _t->latitudeChanged(); break;
        case 2: _t->longitudeChanged(); break;
        case 3: _t->zoomChanged(); break;
        case 4: _t->circleChanged(); break;
        case 5: _t->focusOptionChanged(); break;
        case 6: _t->focusRocketChanged(); break;
        case 7: _t->rocketPathChanged(); break;
        case 8: _t->NoseAviByte(); break;
        case 9: _t->aboutQt(); break;
        case 10: _t->about(); break;
        case 11: _t->on_actionComm_Settings_triggered(); break;
        case 12: _t->on_actionQuit_triggered(); break;
        case 13: _t->on_actionAbout_QT_triggered(); break;
        case 14: _t->openSerialPort(); break;
        case 15: _t->closeSerialPort(); break;
        case 16: _t->readData(); break;
        case 17: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 18: _t->on_action_About_triggered(); break;
        case 19: _t->on_actionConnect_triggered(); break;
        case 20: _t->on_actionDisconnect_triggered(); break;
        case 21: _t->on_action_Open_triggered(); break;
        case 22: _t->on_mpuStartButton_clicked(); break;
        case 23: _t->on_sndtoGrph_clicked(); break;
        case 24: _t->on_action_New_triggered(); break;
        case 25: _t->on_start_stop_clicked(); break;
        case 26: _t->realtimeDataSlot(); break;
        case 27: _t->on_actionRestart_triggered(); break;
        case 28: _t->on_includeHistoric_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_mavProxyShowButton_clicked(); break;
        case 30: _t->on_expoDemoCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_mapSelect_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->on_zoomSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_circleCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->on_focusRocketCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->map_focus_update(); break;
        case 36: { double _r = _t->convertGPSCoord((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 37: _t->updateRocketPath(); break;
        case 38: _t->randomPath(); break;
        case 39: { double _r = _t->get_mapType();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 40: { double _r = _t->get_zoom();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 41: { double _r = _t->get_lat();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 42: { double _r = _t->get_long();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 43: { bool _r = _t->get_circleState();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 44: { bool _r = _t->get_focusRocketState();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 45: { QList<MainWindow::GPSCoordinate> _r = _t->get_rocketPath();
            if (_a[0]) *reinterpret_cast< QList<MainWindow::GPSCoordinate>*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::mapTypeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::latitudeChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::longitudeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::zoomChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::circleChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::focusOptionChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::focusRocketChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::rocketPathChanged)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 46;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::mapTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::latitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::longitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::zoomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::circleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::focusOptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MainWindow::focusRocketChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void MainWindow::rocketPathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

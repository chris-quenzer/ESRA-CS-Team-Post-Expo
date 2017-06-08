/****************************************************************************
** Meta object code from reading C++ file 'LED.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RADAV_APPLICATION/LED.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LED.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LED_t {
    QByteArrayData data[16];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LED_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LED_t qt_meta_stringdata_LED = {
    {
QT_MOC_LITERAL(0, 0, 3), // "LED"
QT_MOC_LITERAL(1, 4, 8), // "setState"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 5), // "state"
QT_MOC_LITERAL(4, 20, 11), // "toggleState"
QT_MOC_LITERAL(5, 32, 11), // "setFlashing"
QT_MOC_LITERAL(6, 44, 8), // "flashing"
QT_MOC_LITERAL(7, 53, 12), // "setFlashRate"
QT_MOC_LITERAL(8, 66, 4), // "rate"
QT_MOC_LITERAL(9, 71, 13), // "startFlashing"
QT_MOC_LITERAL(10, 85, 12), // "stopFlashing"
QT_MOC_LITERAL(11, 98, 8), // "diameter"
QT_MOC_LITERAL(12, 107, 5), // "color"
QT_MOC_LITERAL(13, 113, 9), // "alignment"
QT_MOC_LITERAL(14, 123, 13), // "Qt::Alignment"
QT_MOC_LITERAL(15, 137, 9) // "flashRate"

    },
    "LED\0setState\0\0state\0toggleState\0"
    "setFlashing\0flashing\0setFlashRate\0"
    "rate\0startFlashing\0stopFlashing\0"
    "diameter\0color\0alignment\0Qt::Alignment\0"
    "flashRate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LED[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       6,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,
       9,    0,   54,    2, 0x0a /* Public */,
      10,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      11, QMetaType::Double, 0x00095103,
      12, QMetaType::QColor, 0x00095103,
      13, 0x80000000 | 14, 0x0009510b,
       3, QMetaType::Bool, 0x00095103,
       6, QMetaType::Bool, 0x00095103,
      15, QMetaType::Int, 0x00095103,

       0        // eod
};

void LED::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LED *_t = static_cast<LED *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->toggleState(); break;
        case 2: _t->setFlashing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setFlashRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->startFlashing(); break;
        case 5: _t->stopFlashing(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        LED *_t = static_cast<LED *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->diameter(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->color(); break;
        case 2: *reinterpret_cast< Qt::Alignment*>(_v) = _t->alignment(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->state(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isFlashing(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->flashRate(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        LED *_t = static_cast<LED *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDiameter(*reinterpret_cast< double*>(_v)); break;
        case 1: _t->setColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setAlignment(*reinterpret_cast< Qt::Alignment*>(_v)); break;
        case 3: _t->setState(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setFlashing(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setFlashRate(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject LED::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LED.data,
      qt_meta_data_LED,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LED::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LED::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LED.stringdata0))
        return static_cast<void*>(const_cast< LED*>(this));
    return QWidget::qt_metacast(_clname);
}

int LED::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

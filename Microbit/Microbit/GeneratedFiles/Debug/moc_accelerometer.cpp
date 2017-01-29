/****************************************************************************
** Meta object code from reading C++ file 'accelerometer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../accelerometer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accelerometer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Accelerometer_t {
    QByteArrayData data[13];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Accelerometer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Accelerometer_t qt_meta_stringdata_Accelerometer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Accelerometer"
QT_MOC_LITERAL(1, 14, 10), // "paintEvent"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "QPaintEvent*"
QT_MOC_LITERAL(4, 39, 1), // "e"
QT_MOC_LITERAL(5, 41, 10), // "setHeightX"
QT_MOC_LITERAL(6, 52, 1), // "x"
QT_MOC_LITERAL(7, 54, 10), // "setHeightY"
QT_MOC_LITERAL(8, 65, 1), // "y"
QT_MOC_LITERAL(9, 67, 10), // "setHeightZ"
QT_MOC_LITERAL(10, 78, 1), // "z"
QT_MOC_LITERAL(11, 80, 11), // "setWidthAll"
QT_MOC_LITERAL(12, 92, 1) // "w"

    },
    "Accelerometer\0paintEvent\0\0QPaintEvent*\0"
    "e\0setHeightX\0x\0setHeightY\0y\0setHeightZ\0"
    "z\0setWidthAll\0w"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Accelerometer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,
       9,    1,   48,    2, 0x08 /* Private */,
      11,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,

       0        // eod
};

void Accelerometer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Accelerometer *_t = static_cast<Accelerometer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 1: _t->setHeightX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setHeightY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setHeightZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setWidthAll((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Accelerometer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Accelerometer.data,
      qt_meta_data_Accelerometer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Accelerometer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Accelerometer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Accelerometer.stringdata0))
        return static_cast<void*>(const_cast< Accelerometer*>(this));
    return QWidget::qt_metacast(_clname);
}

int Accelerometer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'tomatotimer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tomatotimer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tomatotimer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TomatoTimer_t {
    QByteArrayData data[8];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TomatoTimer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TomatoTimer_t qt_meta_stringdata_TomatoTimer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TomatoTimer"
QT_MOC_LITERAL(1, 12, 7), // "showLCD"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 20), // "workTimerButtonEvent"
QT_MOC_LITERAL(4, 42, 7), // "checked"
QT_MOC_LITERAL(5, 50, 20), // "restTimerButtonEvent"
QT_MOC_LITERAL(6, 71, 18), // "setTimeActionEvent"
QT_MOC_LITERAL(7, 90, 20) // "setTimeLineEditEvent"

    },
    "TomatoTimer\0showLCD\0\0workTimerButtonEvent\0"
    "checked\0restTimerButtonEvent\0"
    "setTimeActionEvent\0setTimeLineEditEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TomatoTimer[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       5,    1,   43,    2, 0x08 /* Private */,
       6,    0,   46,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TomatoTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TomatoTimer *_t = static_cast<TomatoTimer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLCD(); break;
        case 1: _t->workTimerButtonEvent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->restTimerButtonEvent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setTimeActionEvent(); break;
        case 4: _t->setTimeLineEditEvent(); break;
        default: ;
        }
    }
}

const QMetaObject TomatoTimer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TomatoTimer.data,
      qt_meta_data_TomatoTimer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TomatoTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TomatoTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TomatoTimer.stringdata0))
        return static_cast<void*>(const_cast< TomatoTimer*>(this));
    return QDialog::qt_metacast(_clname);
}

int TomatoTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

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
    QByteArrayData data[9];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TomatoTimer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TomatoTimer_t qt_meta_stringdata_TomatoTimer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TomatoTimer"
QT_MOC_LITERAL(1, 12, 14), // "lcdDisplaySlot"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "workTimerButtonSlot"
QT_MOC_LITERAL(4, 48, 7), // "checked"
QT_MOC_LITERAL(5, 56, 19), // "restTimerButtonSlot"
QT_MOC_LITERAL(6, 76, 18), // "timerSetActionSlot"
QT_MOC_LITERAL(7, 95, 20), // "timerSetLineEditSlot"
QT_MOC_LITERAL(8, 116, 18) // "timerSetDialogSlot"

    },
    "TomatoTimer\0lcdDisplaySlot\0\0"
    "workTimerButtonSlot\0checked\0"
    "restTimerButtonSlot\0timerSetActionSlot\0"
    "timerSetLineEditSlot\0timerSetDialogSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TomatoTimer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    1,   45,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
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
        case 0: _t->lcdDisplaySlot(); break;
        case 1: _t->workTimerButtonSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->restTimerButtonSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->timerSetActionSlot(); break;
        case 4: _t->timerSetLineEditSlot(); break;
        case 5: _t->timerSetDialogSlot(); break;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

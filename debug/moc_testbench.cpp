/****************************************************************************
** Meta object code from reading C++ file 'testbench.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../testbench.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testbench.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TestBench_t {
    QByteArrayData data[13];
    char stringdata[324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TestBench_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TestBench_t qt_meta_stringdata_TestBench = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 28),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 30),
QT_MOC_LITERAL(4, 71, 30),
QT_MOC_LITERAL(5, 102, 30),
QT_MOC_LITERAL(6, 133, 30),
QT_MOC_LITERAL(7, 164, 30),
QT_MOC_LITERAL(8, 195, 30),
QT_MOC_LITERAL(9, 226, 29),
QT_MOC_LITERAL(10, 256, 21),
QT_MOC_LITERAL(11, 278, 20),
QT_MOC_LITERAL(12, 299, 23)
    },
    "TestBench\0on_ARGBOX_IT_editingFinished\0"
    "\0on_ARGBOX_PA_1_editingFinished\0"
    "on_ARGBOX_PA_2_editingFinished\0"
    "on_ARGBOX_PB_1_editingFinished\0"
    "on_ARGBOX_PB_2_editingFinished\0"
    "on_ARGBOX_MINF_editingFinished\0"
    "on_ARGBOX_SIZE_editingFinished\0"
    "on_ARGBOX_NOR_editingFinished\0"
    "on_pushButton_clicked\0on_playVideo_clicked\0"
    "on_pushButton_2_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestBench[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08,
       3,    0,   70,    2, 0x08,
       4,    0,   71,    2, 0x08,
       5,    0,   72,    2, 0x08,
       6,    0,   73,    2, 0x08,
       7,    0,   74,    2, 0x08,
       8,    0,   75,    2, 0x08,
       9,    0,   76,    2, 0x08,
      10,    0,   77,    2, 0x08,
      11,    0,   78,    2, 0x08,
      12,    0,   79,    2, 0x08,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestBench::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestBench *_t = static_cast<TestBench *>(_o);
        switch (_id) {
        case 0: _t->on_ARGBOX_IT_editingFinished(); break;
        case 1: _t->on_ARGBOX_PA_1_editingFinished(); break;
        case 2: _t->on_ARGBOX_PA_2_editingFinished(); break;
        case 3: _t->on_ARGBOX_PB_1_editingFinished(); break;
        case 4: _t->on_ARGBOX_PB_2_editingFinished(); break;
        case 5: _t->on_ARGBOX_MINF_editingFinished(); break;
        case 6: _t->on_ARGBOX_SIZE_editingFinished(); break;
        case 7: _t->on_ARGBOX_NOR_editingFinished(); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_playVideo_clicked(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TestBench::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestBench.data,
      qt_meta_data_TestBench,  qt_static_metacall, 0, 0}
};


const QMetaObject *TestBench::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestBench::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestBench.stringdata))
        return static_cast<void*>(const_cast< TestBench*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TestBench::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

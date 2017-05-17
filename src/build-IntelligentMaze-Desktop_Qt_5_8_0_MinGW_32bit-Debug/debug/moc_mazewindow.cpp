/****************************************************************************
** Meta object code from reading C++ file 'mazewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IntelligentMaze/mazewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mazewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MazeWindow_t {
    QByteArrayData data[17];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MazeWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MazeWindow_t qt_meta_stringdata_MazeWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MazeWindow"
QT_MOC_LITERAL(1, 11, 10), // "createMaze"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "setMazeCol"
QT_MOC_LITERAL(4, 34, 3), // "col"
QT_MOC_LITERAL(5, 38, 10), // "setMazeRow"
QT_MOC_LITERAL(6, 49, 1), // "r"
QT_MOC_LITERAL(7, 51, 9), // "setStartX"
QT_MOC_LITERAL(8, 61, 1), // "x"
QT_MOC_LITERAL(9, 63, 9), // "setStartY"
QT_MOC_LITERAL(10, 73, 1), // "y"
QT_MOC_LITERAL(11, 75, 11), // "setStepTime"
QT_MOC_LITERAL(12, 87, 1), // "t"
QT_MOC_LITERAL(13, 89, 8), // "findPath"
QT_MOC_LITERAL(14, 98, 1), // "i"
QT_MOC_LITERAL(15, 100, 11), // "setFindPath"
QT_MOC_LITERAL(16, 112, 1) // "b"

    },
    "MazeWindow\0createMaze\0\0setMazeCol\0col\0"
    "setMazeRow\0r\0setStartX\0x\0setStartY\0y\0"
    "setStepTime\0t\0findPath\0i\0setFindPath\0"
    "b"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MazeWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    1,   55,    2, 0x0a /* Public */,
       5,    1,   58,    2, 0x0a /* Public */,
       7,    1,   61,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      11,    1,   67,    2, 0x0a /* Public */,
      13,    1,   70,    2, 0x0a /* Public */,
      15,    1,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Bool,   16,

       0        // eod
};

void MazeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MazeWindow *_t = static_cast<MazeWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createMaze(); break;
        case 1: _t->setMazeCol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setMazeRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setStartX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setStartY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setStepTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->findPath((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setFindPath((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MazeWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MazeWindow.data,
      qt_meta_data_MazeWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MazeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MazeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MazeWindow.stringdata0))
        return static_cast<void*>(const_cast< MazeWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MazeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

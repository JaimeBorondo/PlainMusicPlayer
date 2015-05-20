/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PlainMusicPlayer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "Update"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 13), // "scrobbletimer"
QT_MOC_LITERAL(4, 33, 8), // "AddSongs"
QT_MOC_LITERAL(5, 42, 17), // "SongDoubleClicked"
QT_MOC_LITERAL(6, 60, 1), // "i"
QT_MOC_LITERAL(7, 62, 16), // "scrobblereleased"
QT_MOC_LITERAL(8, 79, 9), // "SetVolume"
QT_MOC_LITERAL(9, 89, 15), // "SelectedLibrary"
QT_MOC_LITERAL(10, 105, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(11, 122, 7), // "current"
QT_MOC_LITERAL(12, 130, 8), // "previous"
QT_MOC_LITERAL(13, 139, 9), // "PauseSong"
QT_MOC_LITERAL(14, 149, 8), // "NextSong"
QT_MOC_LITERAL(15, 158, 12) // "PreviousSong"

    },
    "MainWindow\0Update\0\0scrobbletimer\0"
    "AddSongs\0SongDoubleClicked\0i\0"
    "scrobblereleased\0SetVolume\0SelectedLibrary\0"
    "QTreeWidgetItem*\0current\0previous\0"
    "PauseSong\0NextSong\0PreviousSong"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    1,   66,    2, 0x08 /* Private */,
       5,    1,   69,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    1,   73,    2, 0x08 /* Private */,
       9,    2,   76,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    0,   82,    2, 0x08 /* Private */,
      15,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->Update(); break;
        case 1: _t->scrobbletimer(); break;
        case 2: _t->AddSongs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->SongDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->scrobblereleased(); break;
        case 5: _t->SetVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->SelectedLibrary((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 7: _t->PauseSong(); break;
        case 8: _t->NextSong(); break;
        case 9: _t->PreviousSong(); break;
        default: ;
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
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

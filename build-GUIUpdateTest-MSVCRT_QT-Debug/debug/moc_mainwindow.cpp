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
    QByteArrayData data[25];
    char stringdata[321];
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
QT_MOC_LITERAL(5, 42, 11), // "SaveLibrary"
QT_MOC_LITERAL(6, 54, 15), // "PlayFromCurrent"
QT_MOC_LITERAL(7, 70, 17), // "SongDoubleClicked"
QT_MOC_LITERAL(8, 88, 1), // "i"
QT_MOC_LITERAL(9, 90, 16), // "scrobblereleased"
QT_MOC_LITERAL(10, 107, 9), // "SetVolume"
QT_MOC_LITERAL(11, 117, 15), // "SelectedLibrary"
QT_MOC_LITERAL(12, 133, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(13, 150, 7), // "current"
QT_MOC_LITERAL(14, 158, 8), // "previous"
QT_MOC_LITERAL(15, 167, 9), // "PauseSong"
QT_MOC_LITERAL(16, 177, 8), // "NextSong"
QT_MOC_LITERAL(17, 186, 12), // "PreviousSong"
QT_MOC_LITERAL(18, 199, 19), // "onCustomContextMenu"
QT_MOC_LITERAL(19, 219, 5), // "point"
QT_MOC_LITERAL(20, 225, 25), // "onCustomContextMenu_table"
QT_MOC_LITERAL(21, 251, 19), // "PlaylistFromLibrary"
QT_MOC_LITERAL(22, 271, 14), // "AddSongToQueue"
QT_MOC_LITERAL(23, 286, 19), // "RemoveSongFromQueue"
QT_MOC_LITERAL(24, 306, 14) // "AddNewPlaylist"

    },
    "MainWindow\0Update\0\0scrobbletimer\0"
    "AddSongs\0SaveLibrary\0PlayFromCurrent\0"
    "SongDoubleClicked\0i\0scrobblereleased\0"
    "SetVolume\0SelectedLibrary\0QTreeWidgetItem*\0"
    "current\0previous\0PauseSong\0NextSong\0"
    "PreviousSong\0onCustomContextMenu\0point\0"
    "onCustomContextMenu_table\0PlaylistFromLibrary\0"
    "AddSongToQueue\0RemoveSongFromQueue\0"
    "AddNewPlaylist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    1,  106,    2, 0x08 /* Private */,
       5,    1,  109,    2, 0x08 /* Private */,
       6,    0,  112,    2, 0x08 /* Private */,
       7,    1,  113,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    1,  117,    2, 0x08 /* Private */,
      11,    2,  120,    2, 0x08 /* Private */,
      15,    0,  125,    2, 0x08 /* Private */,
      16,    0,  126,    2, 0x08 /* Private */,
      17,    0,  127,    2, 0x08 /* Private */,
      18,    1,  128,    2, 0x08 /* Private */,
      20,    1,  131,    2, 0x08 /* Private */,
      21,    0,  134,    2, 0x08 /* Private */,
      22,    0,  135,    2, 0x08 /* Private */,
      23,    0,  136,    2, 0x08 /* Private */,
      24,    0,  137,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   19,
    QMetaType::Void, QMetaType::QPoint,   19,
    QMetaType::Void,
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
        case 3: _t->SaveLibrary((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->PlayFromCurrent(); break;
        case 5: _t->SongDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->scrobblereleased(); break;
        case 7: _t->SetVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->SelectedLibrary((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 9: _t->PauseSong(); break;
        case 10: _t->NextSong(); break;
        case 11: _t->PreviousSong(); break;
        case 12: _t->onCustomContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 13: _t->onCustomContextMenu_table((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 14: _t->PlaylistFromLibrary(); break;
        case 15: _t->AddSongToQueue(); break;
        case 16: _t->RemoveSongFromQueue(); break;
        case 17: _t->AddNewPlaylist(); break;
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

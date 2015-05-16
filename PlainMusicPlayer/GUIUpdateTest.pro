#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T15:45:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIUpdateTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Library.cpp \
    Playlist.cpp \
    Song.cpp \
    SoundSystem.cpp \
    PlaylistManager.cpp \
    SongInfoPTRModel.cpp

HEADERS  += mainwindow.h \
    Library.h \
    Playlist.h \
    Song.h \
    SoundSystem.h \
    PlaylistManager.h \
    SongInfoPTRModel.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -ltag
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -ltag

INCLUDEPATH += $$PWD/inc/taglib
DEPENDPATH += $$PWD/inc/taglib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lfmod_vc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lfmod_vc

INCLUDEPATH += $$PWD/inc/fmod
DEPENDPATH += $$PWD/inc/fmod

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lfmod64_vc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lfmod64_vc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lfmodL64_vc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lfmodL64_vc
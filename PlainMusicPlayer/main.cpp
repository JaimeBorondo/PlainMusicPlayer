#include "mainwindow.h"
#include <QApplication>

#include "SoundSystem.h"
#include "Library.h"

int main(int argc, char *argv[])
{
    SoundSystem::Initialize();

   // SongInfo f(L"test.mp3");
    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

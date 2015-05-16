#include "mainwindow.h"
#include <QApplication>

#include "SoundSystem.h"

int main(int argc, char *argv[])
{
    SoundSystem::Initialize();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

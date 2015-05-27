#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

#include "SoundSystem.h"
#include "Library.h"

int main(int argc, char *argv[])
{
    SoundSystem::Initialize();

    QApplication a(argc, argv);

    a.setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.show();

    return a.exec();
}

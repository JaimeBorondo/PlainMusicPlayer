#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtimer.h"

#include "SoundSystem.h"

void MainWindow::Update()
{
    //PlaylistManager.Update();
    SoundSystem::Update();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTimer *timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));

    timer->setInterval(16);
    timer->start();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

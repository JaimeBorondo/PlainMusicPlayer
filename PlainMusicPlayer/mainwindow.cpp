#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtimer.h"

#include "SoundSystem.h"
#include "PlaylistManager.h"
#include "Library.h"

#include <QFileDialog>

void MainWindow::Update()
{
    PlaylistManager::UpdateCurrentPlaylist();
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

    //We will now try to add a button that makes a song play, just for fun
    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(buttonclicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonclicked()
{
    QString str = QFileDialog::getOpenFileName();

    SongInfo si(str.toStdWString());
}

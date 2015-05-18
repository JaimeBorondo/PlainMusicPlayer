#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtimer.h"

#include "SoundSystem.h"
#include "PlaylistManager.h"
#include "Library.h"
#include "SongInfoPTRModel.h"

#include <QFileDialog>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QGridLayout>

#include <fcntl.h>
#include <io.h>

void MainWindow::Update()
{
    PlaylistManager::UpdateCurrentPlaylist();
    SoundSystem::Update();
}

void MainWindow::scrobbletimer()
{
    Song *s = PlaylistManager::GetCurrentSong();
    if(s != nullptr && !ui->horizontalSlider->isSliderDown())
    {
        int value = (1000*s->GetPosition()) / s->GetLength();
        ui->horizontalSlider->setValue(value);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTimer *mainupdatetimer = new QTimer();
    connect(mainupdatetimer, SIGNAL(timeout()), this, SLOT(Update()));
    mainupdatetimer->setInterval(16);
    mainupdatetimer->start();
    
    QTimer *scrobbletimer = new QTimer();
    connect(scrobbletimer, SIGNAL(timeout()), this, SLOT(scrobbletimer()));
    scrobbletimer->setInterval(1000);
    scrobbletimer->start();
    
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(buttonclicked()));
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(SongDoubleClicked(const QModelIndex &)));
    connect(ui->horizontalSlider, SIGNAL(sliderReleased()),this, SLOT(scrobblereleased()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonclicked()
{
    QString l = QFileDialog::getOpenFileName();
    std::vector<std::wstring> filenames;

    //for(QString &s : l)
      //  filenames.push_back(s.toStdWString());

    filenames.push_back(l.toStdWString());
    std::vector<const SongInfo *> songs = TopLevelLibrary::AddSongs(filenames);

    QTableView *view = ui->tableView;
    
    for(const SongInfo *sinfo : songs)
        mmodel.append(sinfo);
    
    view->setModel(&mmodel);
}

void MainWindow::SongDoubleClicked(const QModelIndex &i)
{
    const SongInfo *sptr = mmodel.GetSongInfoPTR(i.row());
    PlaylistInfo pl({sptr});
    PlaylistManager::SetCurrentPlaylist(pl);
}

void MainWindow::scrobblereleased()
{
    //Set the song's position
    Song *s = PlaylistManager::GetCurrentSong();
    
    if(s != nullptr)
    {
        int value = ui->horizontalSlider->value();
        
        float pct = static_cast<float>(value)/ui->horizontalSlider->maximum();
        s->SetPosition(pct);
    }
}

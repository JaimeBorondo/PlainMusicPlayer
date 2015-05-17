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
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(SongDoubleClicked(const QModelIndex &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonclicked()
{
    QStringList l = QFileDialog::getOpenFileNames();
    std::vector<std::wstring> filenames;

    for(QString &s : l)
        filenames.push_back(s.toStdWString());

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

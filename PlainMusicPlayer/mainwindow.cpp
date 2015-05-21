#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtimer.h"

#include "SoundSystem.h"
#include "PlaylistManager.h"
#include "Library.h"
#include "SongInfoPTRModel.h"

#include <QFileDialog>
#include <QStringListModel>

#include <iostream>

void MainWindow::Update()
{
    Song *s = PlaylistManager::GetCurrentSong();
    if(s != nullptr)
    {
       ui->NowPlaying->setText(QString::fromStdWString(s->GetDisplayName()));
    }
    else
        ui->NowPlaying->clear();

    SoundSystem::Update();
}

void MainWindow::scrobbletimer()
{
    Song *s = PlaylistManager::GetCurrentSong();
    if(s != nullptr && !ui->horizontalSlider->isSliderDown())
    {
        unsigned len = s->GetLength();
        unsigned pos = s->GetPosition();

        int value = (1000*pos) / len;
        ui->horizontalSlider->setValue(value);

        unsigned min_c = pos / 60;
        unsigned sec_c = pos % 60;

        unsigned min_t = len / 60;
        unsigned sec_t = len % 60;


        ui->textBrowser_2->setText(QString::fromStdWString(std::to_wstring(min_c) + L":" + std::to_wstring(sec_c) + L" / " + std::to_wstring(min_t) + L":" + std::to_wstring(sec_t)));
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("Plain Music Player");

    mainupdatetimer = new QTimer();
    connect(mainupdatetimer, SIGNAL(timeout()), this, SLOT(Update()));
    mainupdatetimer->setInterval(16);
    mainupdatetimer->start();
    
    scrobble_timer = new QTimer();
    connect(scrobble_timer, SIGNAL(timeout()), this, SLOT(scrobbletimer()));
    scrobble_timer->setInterval(1000);
    scrobble_timer->start();
    
    ui->setupUi(this);

    ui->LibraryMenu->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->LibraryMenu, SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onCustomContextMenu(const QPoint &)));
    connect(ui->actionAdd_Songs_To_Libary, SIGNAL(triggered(bool)),this, SLOT(AddSongs(bool)));
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(SongDoubleClicked(const QModelIndex &)));
    connect(ui->horizontalSlider, SIGNAL(sliderReleased()),this, SLOT(scrobblereleased()));
    connect(ui->volumeslider, SIGNAL(valueChanged(int)),this,SLOT(SetVolume(int)));
    connect(ui->LibraryMenu, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(SelectedLibrary(QTreeWidgetItem*,QTreeWidgetItem*)));
    connect(ui->playpauseButton, SIGNAL(clicked(bool)),this,SLOT(PauseSong()));
    connect(ui->nextButton,SIGNAL(clicked(bool)),this,SLOT(NextSong()));
    connect(ui->previousButton, SIGNAL(clicked(bool)), this, SLOT(PreviousSong()));


    //Initialize the main library sections in the GUI
    all = new QTreeWidgetItem(QStringList{"All Songs"});
    by_art = new QTreeWidgetItem(QStringList{"By Artist"});
    by_alb = new QTreeWidgetItem(QStringList{"By Album"});

    ui->LibraryMenu->addTopLevelItem(all);
    ui->LibraryMenu->addTopLevelItem(by_art);
    ui->LibraryMenu->addTopLevelItem(by_alb);
 }

MainWindow::~MainWindow()
{
    delete ui;
    delete all;
    delete by_art;
    delete by_alb;
    delete mainupdatetimer;
    delete scrobble_timer;
}

void MainWindow::AddSongs(bool)
{
    QStringList l = QFileDialog::getOpenFileNames();
    std::vector<std::wstring> filenames;

    for(QString &s : l)
      filenames.push_back(s.toStdWString());

    std::vector<const SongInfo *> songs = TopLevelLibrary::AddSongs(filenames);
   // QTableView *view = ui->tableView;

    for(const SongInfo *sinfo : songs)
    {
        all_songs_model.append(sinfo);
        by_artist_[sinfo->get_artist()].append(sinfo);
        by_album_[sinfo->get_album()].append(sinfo);
    }
    ui->LibraryMenu->setCurrentItem(all);

    //Need a function that sets the model contents per artist and album.
    UpdateLibrary();
}

bool MainWindow::isNewAlbum(const std::wstring &al)
{
    return albums_so_far_.find(al) == albums_so_far_.end();
}

bool MainWindow::isNewArtist(const std::wstring &al)
{
    return artists_so_far_.find(al) == artists_so_far_.end();
}

void MainWindow::UpdateLibrary()
{
    std::vector<std::wstring> albums = TopLevelLibrary::GetAlbums();
    std::vector<std::wstring> artists = TopLevelLibrary::GetArtists();

    for(const std::wstring &s : albums)
        if(isNewAlbum(s))
        {
            by_alb->addChild(new QTreeWidgetItem(QStringList{QString::fromStdWString(s)}));
            albums_so_far_.insert(s);
        }

    for(const std::wstring &s : artists)
        if(isNewArtist(s))
        {
            by_art->addChild(new QTreeWidgetItem(QStringList{QString::fromStdWString(s)}));
            artists_so_far_.insert(s);
        }
}

void MainWindow::SongDoubleClicked(const QModelIndex &i)
{
    const SongInfo *sptr = current_model_->GetSongInfoPTR(i.row());
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

void MainWindow::SetVolume(int value)
{
    float volume = static_cast<float>(value) / ui->volumeslider->maximum();
    Playlist::SetVolume(volume);
    PlaylistManager::GetCurrentSong()->SetVolume(volume);
}


void MainWindow::SelectedLibrary(QTreeWidgetItem * current, QTreeWidgetItem *)
{
    //Need to set the current model
    QTableView *view = ui->tableView;
    SongInfoPTRModel *model;

    std::wstring identifier = current->text(0).toStdWString();

    if(identifier == L"All Songs")
        model = &all_songs_model;

    if(current->parent())
    {
        QString parent_id = current->parent()->text(0);

        if(parent_id == "By Album")//This is an album
        {
            model = &by_album_[identifier];
        }
        else    //We selected an artist
        {
            model = &by_artist_[identifier];
        }
    }

    current_model_ = model;
    view->setModel(current_model_);
}

void MainWindow::PauseSong()
{
    Song *s = PlaylistManager::GetCurrentSong();
    if(s != nullptr)
        s->Pause();
}

void MainWindow::NextSong()
{
    PlaylistManager::NextSong();
}

void MainWindow::PreviousSong()
{
    PlaylistManager::PreviousSong();
}

void MainWindow::onCustomContextMenu(const QPoint &point)
{
    QModelIndex index = ui->LibraryMenu->indexAt(point);

    if (index.isValid()) {
        QMenu contextMenu;
        contextMenu.addAction("Set as current playlist",this,SLOT(PlaylistFromLibrary()));
        contextMenu.exec(ui->LibraryMenu->mapToGlobal(point));
    }
}

void MainWindow::PlaylistFromLibrary()
{
    bool isalbum;
    QTreeWidgetItem * current = ui->LibraryMenu->selectedItems()[0];
    QString text = current->text(0);

    isalbum = current->parent()->text(0) == QString("By Album");

    if(isalbum)
    {
        PlaylistManager::SetCurrentPlaylist(TopLevelLibrary::PlaylistFromAlbum(text.toStdWString()));
    }
    else
    {
        PlaylistManager::SetCurrentPlaylist(TopLevelLibrary::PlaylistFromArtist(text.toStdWString()));
    }
}

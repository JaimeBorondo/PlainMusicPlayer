#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtimer.h"

#include "SoundSystem.h"
#include "PlaylistManager.h"
#include "Library.h"
#include "SongInfoPTRModel.h"

#include <QFileDialog>
#include <QStringListModel>
#include <QInputDialog>
#include <QErrorMessage>

#include <iostream>
#include <fstream>
#include <codecvt>

void MainWindow::Update()
{
    PlaylistManager::UpdateCurrentPlaylist();
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
        
        int maximum = ui->horizontalSlider->maximum();
        int minimum = ui->horizontalSlider->minimum();
        
        int value = minimum + ((maximum - minimum) * (pos) / len);
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
    mainupdatetimer->setInterval(16);
    mainupdatetimer->start();
    
    scrobble_timer = new QTimer();
    scrobble_timer->setInterval(1000);
    scrobble_timer->start();
    
    ui->setupUi(this);

    ui->LibraryMenu->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);


    ConnectSignals();

    //Initialize the main library sections in the GUI
    all = new QTreeWidgetItem(QStringList{"All Songs"});
    by_art = new QTreeWidgetItem(QStringList{"By Artist"});
    by_alb = new QTreeWidgetItem(QStringList{"By Album"});
    playlists = new QTreeWidgetItem(QStringList{"Playlists"});

    ui->LibraryMenu->addTopLevelItem(all);
    ui->LibraryMenu->addTopLevelItem(by_art);
    ui->LibraryMenu->addTopLevelItem(by_alb);
    ui->LibraryMenu->addTopLevelItem(playlists);

    nowplaying = new QTreeWidgetItem(QStringList{"Now Playing"});
    playlists->addChild(nowplaying);
 }

MainWindow::~MainWindow()
{
    delete ui;
    delete all;
    delete by_art;
    delete by_alb;
    delete mainupdatetimer;
    delete scrobble_timer;
    delete nowplaying;
    
    BASS_Free();
}

void MainWindow::AddSongs(bool)
{
    QStringList l = QFileDialog::getOpenFileNames();
    std::vector<std::wstring> filenames;

    for(QString &s : l)
      filenames.push_back(s.toStdWString());

    std::vector<const SongInfo *> songs = TopLevelLibrary::AddSongs(filenames);

    for(const SongInfo *sinfo : songs)
    {
        all_songs_model.append(sinfo);
        by_artist_[sinfo->get_artist()].append(sinfo);
        by_album_[sinfo->get_album()].append(sinfo);
    }
    ui->LibraryMenu->setCurrentItem(all);

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
    PlaylistInfo pl(current_model_->GetSongs());
    
    playlists_map_[L"Now Playing"].pl = pl;
    playlists_map_[L"Now Playing"].model.from_songinfo_vec(current_model_->GetSongs());
    
    PlaylistManager::SetCurrentPlaylist(playlists_map_[L"Now Playing"].pl);
    PlaylistManager::SetCurrentSong(i.row());
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
    Song *s = PlaylistManager::GetCurrentSong();
    
    if(s != nullptr)
        s->SetVolume(volume);
}

void MainWindow::SelectedLibrary(QTreeWidgetItem * current, QTreeWidgetItem *)
{
    //Need to set the current model
    QTableView *view = ui->tableView;
    SongInfoPTRModel *model;

    std::wstring identifier = current->text(0).toStdWString();

    if(identifier == L"All Songs")
        model = &all_songs_model;
    
    if(identifier == L"By Album" || identifier == L"By Artist" || identifier == L"Playlists" )
        return;

    if(current->parent())
    {
        QString parent_id = current->parent()->text(0);

        if(parent_id == "By Album")//This is an album
        {
            model = &by_album_[identifier];
            currently_displayed_playlist_ = L"";
        }
        else if(parent_id == "By Artist") //We selected an artist
        {
            model = &by_artist_[identifier];
            currently_displayed_playlist_ = L"";
        }
        else
        {            
            model = &playlists_map_[identifier].model;
            currently_displayed_playlist_ = identifier;
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
        
        if(ui->LibraryMenu->selectedItems()[0]->text(0) == QString("Playlists"))
        contextMenu.addAction("Add new Playlist", this, SLOT(AddNewPlaylist()));
        
        contextMenu.addAction("Set as current playlist",this,SLOT(PlaylistFromLibrary()));
        contextMenu.exec(ui->LibraryMenu->mapToGlobal(point));
    }
}

void MainWindow::AddNewPlaylist()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter New Playlist Name"),
                                             tr("Name:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
    {
        if(playlists_map_.find(text.toStdWString()) != playlists_map_.end())
        {
            QErrorMessage ermsg;
            ermsg.showMessage("Playlist by that name already exists.");
        }
        else
        {
            playlist_model pl;
            playlists_map_[text.toStdWString()] = pl;   
            playlists->addChild(new QTreeWidgetItem(QStringList{text}));
        }        
    }
}

void MainWindow::PlayFromCurrent()
{
    QModelIndex i = ui->tableView->selectionModel()->selectedIndexes()[0];
    SongDoubleClicked(i);
}

void MainWindow::onCustomContextMenu_table(const QPoint &point)
{
    QModelIndex index = ui->tableView->indexAt(point);

    if (index.isValid()) {
        QMenu contextMenu;
        
        if(currently_displayed_playlist_ != L"")
            contextMenu.addAction("Remove from playlist", this, SLOT(RemoveSongFromQueue()));
        
        contextMenu.addAction("Add to queue",this, SLOT(AddSongToQueue()));
        
        QMenu * playlist_menu = contextMenu.addMenu("Add to Playlist");
        FillPlaylistMenu(playlist_menu);
        
        contextMenu.addAction("Play from here", this, SLOT(PlayFromCurrent()));
        contextMenu.exec(ui->tableView->mapToGlobal(point));
    }
}

void MainWindow::FillPlaylistMenu(QMenu * playlist_menu)
{
    for(const std::pair<const std::wstring &, const playlist_model &> &cur : playlists_map_)
    {
        std::wstring id = cur.first;
        
        QAction *temp = new QAction(QString::fromStdWString(cur.first),nullptr);
        connect(temp,&QAction::triggered,[temp, this, id]()
        {
            //Add the selected song(/s) to the playlist
            QModelIndexList idcs = ui->tableView->selectionModel()->selectedRows();
            for(const QModelIndex &i : idcs)
            {
                const SongInfo *ptr = current_model_->GetSongInfoPTR(i.row());
                playlist_model & m = playlists_map_[id];
                m.model.append(ptr);
                m.pl = PlaylistInfo(m.model.GetSongs());
            }            
        });
        
        playlist_menu->addAction(temp);
    }
}

void MainWindow::RemoveSongFromQueue()
{
    QModelIndexList list = ui->tableView->selectionModel()->selectedRows();
    
    std::sort(list.begin(), list.end(),
    [](const QModelIndex &l, const QModelIndex &r)
    {
        return l.row() > r.row();        
    });
    
    for(const QModelIndex &i : list)
    {
        const SongInfo *sel = playlists_map_[currently_displayed_playlist_].model.GetSongInfoPTR(i.row());
        
        if(currently_displayed_playlist_ == L"Now Playing")
        {
            PlaylistManager::RemoveSong(sel);
        }
        
        playlists_map_[currently_displayed_playlist_].model.removeElement(i.row());
        playlists_map_[currently_displayed_playlist_].pl.RemoveAt(i.row());
    }
}

void MainWindow::AddSongToQueue()
{
    //Add the selected song to the currently playing playlist
    QModelIndex index = ui->tableView->selectionModel()->selectedRows()[0];
    
    const SongInfo *selected = current_model_->GetSongInfoPTR(index.row());
    playlists_map_[L"Now Playing"].model.append(selected);
    playlists_map_[L"Now Playing"].pl = PlaylistInfo(playlists_map_[L"Now Playing"].model.GetSongs());

    PlaylistManager::AppendToCurrentPlaylist(selected);
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

    playlists_map_[L"Now Playing"].model.from_songinfo_vec(PlaylistManager::GetCurrentSongList());
    playlists_map_[L"Now Playing"].pl = PlaylistInfo(PlaylistManager::GetCurrentSongList());    
}

void MainWindow::SaveMusicLibrary(bool)
{
    QString filename = QFileDialog::getSaveFileName();
    
    const std::vector<const SongInfo *> songs = TopLevelLibrary::DumpSongs();
    std::wofstream save(filename.toStdWString().c_str(), std::ios::out | std::ios::binary);
    save.imbue(std::locale(save.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    
    //Really only save filenames for now
    for(const SongInfo *p : songs)
    {
        save << p->get_filename() << std::endl;
    }
}

void MainWindow::LoadMusicLibrary(bool)
{
    QString filename = QFileDialog::getOpenFileName();
    std::wifstream load(filename.toStdWString().c_str(), std::ios::out | std::ios::binary);
    load.imbue(std::locale(load.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    
    std::vector<std::wstring> filenames;
    
    std::wstring line;
    while (std::getline(load, line))
    {
        if(line == L"")
            break;
        
        filenames.push_back(line);
    }
    
    std::vector<const SongInfo *> songs = TopLevelLibrary::AddSongs(filenames);

    for(const SongInfo *sinfo : songs)
    {
        all_songs_model.append(sinfo);
        by_artist_[sinfo->get_artist()].append(sinfo);
        by_album_[sinfo->get_album()].append(sinfo);
    }
    ui->LibraryMenu->setCurrentItem(all);

    UpdateLibrary();
}

void MainWindow::ConnectSignals()
{
    connect(ui->LibraryMenu, SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onCustomContextMenu(const QPoint &)));
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onCustomContextMenu_table(const QPoint &)));
    connect(ui->actionAdd_Songs_To_Libary, SIGNAL(triggered(bool)),this, SLOT(AddSongs(bool)));
    connect(ui->actionSave_Library, SIGNAL(triggered(bool)),this,SLOT(SaveMusicLibrary(bool)));
    connect(ui->actionLoad_Library, SIGNAL(triggered(bool)),this,SLOT(LoadMusicLibrary(bool)));
    
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(SongDoubleClicked(const QModelIndex &)));
    connect(ui->horizontalSlider, SIGNAL(sliderReleased()),this, SLOT(scrobblereleased()));
    connect(ui->volumeslider, SIGNAL(valueChanged(int)),this,SLOT(SetVolume(int)));
    connect(ui->LibraryMenu, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(SelectedLibrary(QTreeWidgetItem*,QTreeWidgetItem*)));
    connect(ui->playpauseButton, SIGNAL(clicked(bool)),this,SLOT(PauseSong()));
    connect(ui->nextButton,SIGNAL(clicked(bool)),this,SLOT(NextSong()));
    connect(ui->previousButton, SIGNAL(clicked(bool)), this, SLOT(PreviousSong()));

    connect(mainupdatetimer, SIGNAL(timeout()), this, SLOT(Update()));
    connect(scrobble_timer, SIGNAL(timeout()), this, SLOT(scrobbletimer()));
}

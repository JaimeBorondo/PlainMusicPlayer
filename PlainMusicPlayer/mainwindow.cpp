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

    connect(ui->actionAdd_Songs_To_Libary, SIGNAL(triggered(bool)),this, SLOT(AddSongs(bool)));
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)),this,SLOT(SongDoubleClicked(const QModelIndex &)));
    connect(ui->horizontalSlider, SIGNAL(sliderReleased()),this, SLOT(scrobblereleased()));
    connect(ui->volumeslider, SIGNAL(valueChanged(int)),this,SLOT(SetVolume(int)));
    connect(ui->LibraryMenu, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(SelectedLibrary(QTreeWidgetItem*,QTreeWidgetItem*)));


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

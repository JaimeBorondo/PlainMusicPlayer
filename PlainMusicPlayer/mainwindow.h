#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <set>

#include <QMainWindow>
#include <QTreeWidget>
#include "SongInfoPTRModel.h"
#include "Playlist.h"

struct playlist_model
{
    PlaylistInfo pl;
    SongInfoPTRModel model;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void Update();
    void scrobbletimer();


private slots:
    void AddSongs(bool);
    void PlayFromCurrent();
    void SongDoubleClicked(const QModelIndex &i);
    void scrobblereleased();
    void SetVolume(int);
    void SelectedLibrary(QTreeWidgetItem * current, QTreeWidgetItem * previous);
    void PauseSong();
    void NextSong();
    void PreviousSong();
    void onCustomContextMenu(const QPoint &point);
    void onCustomContextMenu_table(const QPoint &point);
    void PlaylistFromLibrary();
    void AddSongToQueue();
    void RemoveSongFromQueue();
    void AddNewPlaylist();
    
private:
    void ConnectSignals();

    void UpdateLibrary();
    bool isNewAlbum(const std::wstring &al);
    bool isNewArtist(const std::wstring &al);

    SongInfoPTRModel *current_model_;

    Ui::MainWindow *ui;
    SongInfoPTRModel all_songs_model;
    SongInfoPTRModel now_playing_model;

    std::map<std::wstring, SongInfoPTRModel> by_artist_;
    std::map<std::wstring, SongInfoPTRModel> by_album_;

    QTreeWidgetItem * all;
    QTreeWidgetItem * by_art;
    QTreeWidgetItem * by_alb;
    QTreeWidgetItem * playlists;
    QTreeWidgetItem * nowplaying;

    QTimer *mainupdatetimer;
    QTimer *scrobble_timer;

    std::set<std::wstring> albums_so_far_;
    std::set<std::wstring> artists_so_far_;
    
    std::map<std::wstring, playlist_model> playlists_map_;
    std::wstring currently_displayed_playlist_;
};

#endif // MAINWINDOW_H

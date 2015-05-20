#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <set>

#include <QMainWindow>
#include <QTreeWidget>
#include "SongInfoPTRModel.h"

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
    void SongDoubleClicked(const QModelIndex &i);
    void scrobblereleased();
    void SetVolume(int);
    void SelectedLibrary(QTreeWidgetItem * current, QTreeWidgetItem * previous);
    void PauseSong();
    void NextSong();
    void PreviousSong();

private:
    void UpdateLibrary();
    bool isNewAlbum(const std::wstring &al);
    bool isNewArtist(const std::wstring &al);

    SongInfoPTRModel *current_model_;

    Ui::MainWindow *ui;
    SongInfoPTRModel all_songs_model;
    std::map<std::wstring, SongInfoPTRModel> by_artist_;
    std::map<std::wstring, SongInfoPTRModel> by_album_;
    QTreeWidgetItem * all;
    QTreeWidgetItem * by_art;
    QTreeWidgetItem * by_alb;

    std::set<std::wstring> albums_so_far_;
    std::set<std::wstring> artists_so_far_;
};

#endif // MAINWINDOW_H

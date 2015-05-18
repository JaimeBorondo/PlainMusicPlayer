#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    
private:
    Ui::MainWindow *ui;
    SongInfoPTRModel mmodel;
};

#endif // MAINWINDOW_H

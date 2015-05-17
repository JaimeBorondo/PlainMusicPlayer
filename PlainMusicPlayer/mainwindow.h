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


private slots:
    void buttonclicked();
    void SongDoubleClicked(const QModelIndex &i);

private:
    Ui::MainWindow *ui;
    SongInfoPTRModel mmodel;
};

#endif // MAINWINDOW_H

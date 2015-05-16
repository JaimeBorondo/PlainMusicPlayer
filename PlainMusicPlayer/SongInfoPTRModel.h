#ifndef SONGINFOPTRMODEL_H
#define SONGINFOPTRMODEL_H

#include <QAbstractTableModel>
#include "Song.h"


class SongInfoPTRModel : public QAbstractTableModel
{
    QList<SongInfo *> m_data;

public:
    SongInfoPTRModel(QObject *parent = 0);
};

#endif // SONGINFOPTRMODEL_H

#ifndef SONGINFOPTRMODEL_H
#define SONGINFOPTRMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "Song.h"


class SongInfoPTRModel : public QAbstractTableModel
{
    QList<const SongInfo *> m_data;

public:
    SongInfoPTRModel(QObject *parent = 0);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void removeElement(unsigned row);
    void append(const SongInfo *p);
    const SongInfo *GetSongInfoPTR(unsigned index);
    std::vector<const SongInfo *> GetSongs();
    void from_songinfo_vec(const std::vector<const SongInfo *> &songs);
};

#endif // SONGINFOPTRMODEL_H

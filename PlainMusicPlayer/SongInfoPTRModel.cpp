#include "SongInfoPTRModel.h"

std::wstring seconds_to_formatted_string(unsigned int seconds)
{
    //Number of minutes
    unsigned min = seconds / 60;
    unsigned sec = seconds % 60;
    
    return std::to_wstring(min) + L":" + std::to_wstring(sec);
}

SongInfoPTRModel::SongInfoPTRModel(QObject *parent) : QAbstractTableModel(parent)
{}

int SongInfoPTRModel::rowCount(const QModelIndex &) const
{return m_data.count();}

int SongInfoPTRModel::columnCount(const QModelIndex &parent) const
{return 5;}

QVariant SongInfoPTRModel::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    const SongInfo *p = m_data[index.row()];

    switch(index.column())
    {
    case 0: return p->get_title();
    case 1: return p->get_artist();
    case 2: return p->get_album();
    case 3: return seconds_to_formatted_string(p->get_length());
    case 4: return std::to_wstring(p->get_bitrate()/1000) + L"kbps";
    default: return QVariant();
    };
}

QVariant SongInfoPTRModel::headerData(int section, Qt::Orientation orientation, int role) const
{
        if (orientation != Qt::Horizontal)
            return QVariant();

        if (role != Qt::DisplayRole)
            return QVariant();

        switch (section)
        {
        case 0: return "Title";
        case 1: return "Artist";
        case 2: return "Album";
        case 3: return "Length";
        case 4: return "Bitrate";
        default: return QVariant();
        }
}

void SongInfoPTRModel::append(const SongInfo *p)
{
    beginInsertRows(QModelIndex(), m_data.count(), m_data.count());
    m_data.append(p);
    endInsertRows();
}

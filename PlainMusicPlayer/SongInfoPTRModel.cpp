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
    if(role == Qt::TextAlignmentRole)
        switch(index.column())
        {
        case 0: case 1: case 2: return Qt::AlignLeft;
        case 3: case 4: return Qt::AlignRight;
        }
    
    if(role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    const SongInfo *p = m_data[index.row()];

    switch(index.column())
    {
    case 0: return QString::fromWCharArray(p->get_title().c_str());
    case 1: return QString::fromWCharArray(p->get_artist().c_str());
    case 2: return QString::fromWCharArray(p->get_album().c_str());
    case 3: return QString::fromWCharArray(seconds_to_formatted_string(p->get_length()).c_str());
    case 4: return QString::fromWCharArray((std::to_wstring(p->get_bitrate()) + L"kbps").c_str());
    default: return QVariant();
    };
}

QVariant SongInfoPTRModel::headerData(int section, Qt::Orientation orientation, int role) const
{   
        if (orientation != Qt::Horizontal)
            return QVariant();

        if(role == Qt::TextAlignmentRole)
            switch(section)
            {
            case 0: case 1: case 2: return Qt::AlignLeft;
            case 3: case 4: return Qt::AlignRight;
            }
        
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


const SongInfo *SongInfoPTRModel::GetSongInfoPTR(unsigned index)
{
    return m_data.at(index);
}

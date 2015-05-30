#include "PlaylistInfo.h"

PlaylistInfo::PlaylistInfo() : name_(L"")
{}

PlaylistInfo::PlaylistInfo(const std::vector<const SongInfo *> &songs) : name_(L""), songs_(songs)
{}

const std::vector<const SongInfo *> &PlaylistInfo::GetSongList() const
{return songs_;}

void PlaylistInfo::AddSongs(const std::vector<const SongInfo *> &songs)
{
    std::copy(songs.begin(), songs.end(), std::back_inserter(songs_));
}

void PlaylistInfo::RemoveAt(unsigned idx)
{
    songs_.erase(songs_.begin() + idx);
}

const std::wstring &PlaylistInfo::GetName() const
{
    return name_;
}

void PlaylistInfo::SetName(const std::wstring &name)
{
    name_ = name;
}

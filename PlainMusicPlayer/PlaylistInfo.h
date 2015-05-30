#ifndef PLAYLISTINFO_H
#define PLAYLISTINFO_H

#include "Song.h"

#include <vector>

class PlaylistInfo
{
public:
    PlaylistInfo();
    PlaylistInfo(const std::vector<const SongInfo *> &songs);
    void AddSongs(const std::vector<const SongInfo *> &songs);
    void RemoveAt(unsigned idx);
    const std::vector<const SongInfo *> &GetSongList() const;
    const std::wstring &GetName() const;
    void SetName(const std::wstring &name);
    
private:
    std::wstring name_;
	std::vector<const SongInfo *> songs_;
};

#endif // PLAYLISTINFO_H

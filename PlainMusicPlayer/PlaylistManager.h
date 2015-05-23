#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include "Playlist.h"

class PlaylistManager
{
public:
   static void UpdateCurrentPlaylist(void);
   static void SetCurrentPlaylist(const Playlist &pl);
   static Song *GetCurrentSong();
   static void NextSong();
   static void PreviousSong();
   static void AddToPlaylist(const std::wstring &plname, const std::vector<const SongInfo *> &songs);
   
private:
   static Playlist *current_;
   static std::map<std::wstring, PlaylistInfo> playlists_;
};

#endif // PLAYLISTMANAGER_H

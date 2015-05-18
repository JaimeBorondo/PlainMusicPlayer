#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include "Playlist.h"

class PlaylistManager
{
public:
   static void UpdateCurrentPlaylist(void);
   static void SetCurrentPlaylist(const Playlist &pl);
   static Song *GetCurrentSong();

private:
   static Playlist current_;
};

#endif // PLAYLISTMANAGER_H

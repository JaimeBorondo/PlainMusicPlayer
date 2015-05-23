#include "PlaylistManager.h"

Playlist PlaylistManager::current_;
std::map<std::wstring, PlaylistInfo> PlaylistManager::playlists_;

void PlaylistManager::UpdateCurrentPlaylist(void)
{
    current_.Update();
}

void PlaylistManager::SetCurrentPlaylist(const Playlist &pl)
{
    current_.Pause();
    current_ = Playlist(pl);
    current_.SetCurrentSong(0);//Automatically play for now
}

Song *PlaylistManager::GetCurrentSong()
{
    return current_.GetCurrentSong();
}


void PlaylistManager::NextSong()
{
    current_.NextSong();
}

void PlaylistManager::PreviousSong()
{
    current_.PreviousSong();
}

void PlaylistManager::AddToPlaylist(const std::wstring &plname, const std::vector<const SongInfo *> &songs)
{
    //std::map<std::wstring, Playlist>::iterator it = playlists_.find(plname);

}

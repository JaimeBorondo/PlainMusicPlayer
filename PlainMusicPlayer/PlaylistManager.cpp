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

void PlaylistManager::SetCurrentSong(unsigned int index)
{
    current_.SetCurrentSong(index);//Automatically play for now
}

Song *PlaylistManager::GetCurrentSong()
{
    return current_.GetCurrentSong();
}

const std::vector<const SongInfo *> &PlaylistManager::GetCurrentSongList()
{
    return current_.GetSongs();
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
    playlists_[plname].AddSongs(songs);
}


void PlaylistManager::AppendToCurrentPlaylist(const SongInfo *song)
{
    current_.Append(song);
}

void PlaylistManager::RemoveSong(const SongInfo *song)
{
    //If the song currently playing is this one, advance to the next one
    if(current_.GetCurrentSong()->GetDisplayName() ==  song->get_display_name())
    {
        current_.Stop();
    }
    
    current_.Remove(song);
}

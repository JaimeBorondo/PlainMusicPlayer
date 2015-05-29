#pragma once

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

//A playlist will be initialized from a playlist info, 
//and will be managed by an external entity (Playlist controller maybe??)
class Playlist
{
public:
    Playlist();
    Playlist(const Playlist &pl);
	Playlist(const PlaylistInfo &pi);
	~Playlist();

	void Update();

	//These functions will construct a Song object and play it
	void SetCurrentSong(unsigned idx);
	void NextSong();
	void PreviousSong();
	void Pause();

	void Shuffle();
    
    Song *GetCurrentSong();
    
    const std::vector<const SongInfo *> &GetSongs();
    static void SetVolume(float vol);
    const std::wstring &GetName() const;
    void SetName(const std::wstring &name);
    
private:
    
    static float volume_;
	void UpdateCurrentSong();
	unsigned current_song_idx_;
    //might seem redundant, but I like the abstraction
    std::vector<const SongInfo *> songs_;
	Song *current_song_;
    std::wstring name_;
};

#pragma once
#include "PlaylistInfo.h"

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
    void Stop();
    void Remove(const SongInfo *s);
	void Shuffle();
    
    Song *GetCurrentSong();
    
    void Append(const SongInfo *song);
    const std::vector<const SongInfo *> &GetSongs();
    static void SetVolume(float vol);
    const std::wstring &GetName() const;
    void SetName(const std::wstring &name);
    
    void UpdateCurrentSong();
    
private:
    
    static float volume_;
	unsigned current_song_idx_;
    //might seem redundant, but I like the abstraction
    std::vector<const SongInfo *> songs_;
	Song *current_song_;
    std::wstring name_;
};

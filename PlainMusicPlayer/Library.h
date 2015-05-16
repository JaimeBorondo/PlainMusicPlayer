#pragma once

#include "Song.h"
#include "Playlist.h"

#include <vector>
#include <map>
#include <string>

//A library will be built from the top-level library
class Library
{
public:
	Library();
	void AddSong(const SongInfo *song);
	void RemoveSong(const SongInfo *song);
	Playlist ToPlaylist();
private:
	std::vector<const SongInfo *> songs_;
};

class TopLevelLibrary
{
public:
	//Should build a sublibrary with all songs, and sublibraries grouped by artist and by album
    static void AddSongs(const std::vector<std::wstring> &files);

    static std::vector<std::wstring> GetArtists();
    static std::vector<std::wstring> GetAlbums();
	
    static Playlist PlaylistFromArtist(const std::wstring &artist);
    static Playlist PlaylistFromAlbum(const std::wstring &album);

private:
	//Indexed by filename, pointer validity remains between insertions
    static std::map<std::wstring, SongInfo> song_db_;

    static std::map<std::wstring, Library> by_artist_;
    static std::map<std::wstring, Library> by_album_;
};


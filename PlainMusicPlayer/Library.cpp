#include "Library.h"
#include <algorithm>

//Indexed by filename, pointer validity remains between insertions
std::map<std::wstring, SongInfo> TopLevelLibrary::song_db_;

std::map<std::wstring, Library> TopLevelLibrary::by_artist_;
std::map<std::wstring, Library> TopLevelLibrary::by_album_;

Library::Library()
{
    //Nothing to do here yet
}

void Library::AddSong(const SongInfo *song)
{
	songs_.push_back(song);
}

void Library::RemoveSong(const SongInfo *song)
{
	std::remove_if(songs_.begin(), songs_.end(), 
		[&song](const SongInfo *cmp)
		{return cmp->get_filename() == song->get_filename();});
}

Playlist Library::ToPlaylist()
{
	PlaylistInfo pinfo(songs_);
	return Playlist(pinfo);
}

//TopLevelLibrary definition begins here
void TopLevelLibrary::AddSongs(const std::vector<std::wstring> &files)
{
	//Go through each of the files
	for (const std::wstring &ws : files)
	{
		SongInfo tmp(ws);
		//add them to our main library
		song_db_[ws] = tmp;

		//And add their pointer to their respective artist and album sublibraries
		by_artist_[tmp.get_artist()].AddSong(&song_db_[ws]);
		by_album_[tmp.get_album()].AddSong(&song_db_[ws]);
	}
}

std::vector<std::wstring> TopLevelLibrary::GetArtists()
{
	std::vector<std::wstring> ret;

	for (const std::pair<std::wstring, Library> &p : by_artist_)
		ret.push_back(p.first);

	return ret;
}

std::vector<std::wstring> TopLevelLibrary::GetAlbums()
{
	std::vector<std::wstring> ret;

	for (const std::pair<std::wstring, Library> &p : by_album_)
		ret.push_back(p.first);

	return ret;
}
	
Playlist TopLevelLibrary::PlaylistFromArtist(const std::wstring &artist)
{
	std::map<std::wstring, Library>::iterator find;
	find = by_artist_.find(artist);

	if (find != by_artist_.end())
		return find->second.ToPlaylist();
	else
		return Playlist(PlaylistInfo({})); //Empty playlist
}

Playlist TopLevelLibrary::PlaylistFromAlbum(const std::wstring &album)
{
	std::map<std::wstring, Library>::iterator find;
	find = by_album_.find(album);

	if (find != by_album_.end())
		return find->second.ToPlaylist();
	else
		return Playlist(PlaylistInfo({})); //Empty playlist
}

#include "Library.h"
#include <algorithm>

Library::Library()
{
	//Nothing to do here
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

//TopLevelLibrary definition begins here
TopLevelLibrary::TopLevelLibrary(const std::vector<std::wstring> &files)
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
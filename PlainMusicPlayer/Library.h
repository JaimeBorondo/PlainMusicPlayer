#include "Song.h"

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
private:
	std::vector<const SongInfo *> songs_;
};

class TopLevelLibrary
{
public:
	//Should build a sublibrary with all songs, and sublibraries grouped by artist and by album
	TopLevelLibrary(const std::vector<std::wstring> &files);
	~TopLevelLibrary();

private:
	//Indexed by filename, pointer validity remains between insertions
	std::map<std::wstring, SongInfo> song_db_;

	std::map<std::wstring, Library> by_artist_;
	std::map<std::wstring, Library> by_album_;
};


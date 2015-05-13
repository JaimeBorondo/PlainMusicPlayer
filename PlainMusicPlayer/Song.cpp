#include "Song.h"

Song::Song(const SongInfo &info) : info_(info)
{
	channel_ = nullptr;
}

Song::~Song()
{}

SongInfo::SongInfo(const std::string &filename) : filename_(filename)
{
	//Find out how to use id3lib to get the rest of the data
}


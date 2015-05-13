#include <fmod.hpp>
#include <string>

//Songinfo doesnt need to be playable, only contain information about the track,
//An actual song will be created from it, and will store its channel.
class SongInfo
{
public:
	SongInfo(const std::string &filename);
	~SongInfo();

	const std::string &get_filename();
	const std::string &get_name();
	const std::string &get_artist();
	const std::string &get_album();

private:
	std::string filename_;
	std::string name_;
	std::string artist_;
	std::string album_;
};

class Song
{
public:
	Song(const SongInfo &info);
	~Song();
private:
	const SongInfo &info_;
	FMOD::Channel *channel_;
};
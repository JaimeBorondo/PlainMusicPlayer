#include <fmod.hpp>
#include <string>

//Songinfo doesnt need to be playable, only contain information about the track,
//An actual song will be created from it, and will store its channel.
class SongInfo
{
public:
	SongInfo(const std::wstring &filename);
	~SongInfo();

	const std::wstring &get_filename();
	const std::wstring &get_name();
	const std::wstring &get_artist();
	const std::wstring &get_album();

private:
	std::wstring filename_;
	std::wstring name_;
	std::wstring artist_;
	std::wstring album_;
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
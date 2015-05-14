#include <fmod.hpp>
#include <string>
#include <locale>
#include <codecvt>

//Songinfo doesnt need to be playable, only contain information about the track,
//An actual song will be created from it, and will store its channel.
class SongInfo
{
public:
	SongInfo(const std::string &filename);
	~SongInfo();

	const std::string &get_filename();
	const std::wstring &get_title();
	const std::wstring &get_artist();
	const std::wstring &get_album();
	const unsigned &get_length();
	const unsigned &get_bitrate();
	const unsigned &get_frequency();
	bool is_stereo();

private:
	std::string filename_;
	std::wstring title_;
	std::wstring artist_;
	std::wstring album_;

	unsigned length_;
	unsigned bitrate_;
	unsigned frequency_;
	bool stereo_;
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
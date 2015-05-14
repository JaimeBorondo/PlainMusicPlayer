#include "Song.h"
#include <unordered_map>
#include <id3\tag.h>
#include <Windows.h>

Song::Song(const SongInfo &info) : info_(info)
{
	channel_ = nullptr;
}

Song::~Song()
{}

// Convert a wide Unicode string to an UTF8 string
std::string utf8_encode(const std::wstring &wstr)
{
    if( wstr.empty() ) return std::string();
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
    std::string strTo( size_needed, 0 );
    WideCharToMultiByte                  (CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
    return strTo;
}

// Convert an UTF8 string to a wide Unicode String
std::wstring utf8_decode(const std::string &str)
{
    if( str.empty() ) return std::wstring();
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo( size_needed, 0 );
    MultiByteToWideChar                  (CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

std::wstring ExtractInfo(ID3_Frame *frame)
{
	if (frame == NULL)
		return std::wstring(L"Unknown");

	//Need to extract encoding, if it is different from utf16, convert it
	int encoding = frame->Field(ID3FN_TEXTENC).Get();

	if (encoding == ID3TE_UTF16)
		return std::wstring((wchar_t *)frame->Field(ID3FN_TEXT).GetRawUnicodeText());
	else
		return utf8_decode(frame->Field(ID3FN_TEXT).GetRawText());
}

SongInfo::SongInfo(const std::string &filename) : filename_(filename)
{
	ID3_Tag tag(filename.c_str());
	const Mp3_Headerinfo *header = tag.GetMp3HeaderInfo();

	stereo_ = header->channelmode != 3;
	bitrate_ = header->bitrate;
	frequency_ = header->frequency;
	length_ = header->time;

	title_ = ExtractInfo(tag.Find(ID3FID_TITLE));
	album_ = ExtractInfo(tag.Find(ID3FID_ALBUM));
	artist_ = ExtractInfo(tag.Find(ID3FID_LEADARTIST));
}

SongInfo::~SongInfo(){}

const std::string &SongInfo::get_filename()
{
	return filename_;
}

const std::wstring &SongInfo::get_title()
{
	return title_;
}

const std::wstring &SongInfo::get_artist()
{
	return artist_;
}

const std::wstring &SongInfo::get_album()
{
	return album_;
}

const unsigned &SongInfo::get_length()
{
	return length_;
}

const unsigned &SongInfo::get_bitrate()
{
	return bitrate_;
}

const unsigned &SongInfo::get_frequency()
{
	return frequency_;
}

bool SongInfo::is_stereo()
{
	return stereo_;
}
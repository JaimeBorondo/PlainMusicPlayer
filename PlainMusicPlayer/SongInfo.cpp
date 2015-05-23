#include "SongInfo.h"
#include <taglib.h>
#include <fileref.h>

SongInfo::SongInfo(){}

SongInfo::SongInfo(const std::wstring &filename) : filename_(filename)
{
    TagLib::FileRef f(filename.c_str());

    album_ = f.tag()->album().toWString().data();
    artist_ = f.tag()->artist().toWString().data();
    title_ = f.tag()->title().toWString().data();

    if(artist_ == L"")
        artist_ = L"Unknown";

    if(title_== L"")
        title_ = L"Unknown";

    if(album_ == L"")
        album_ = L"Unknown";

    bitrate_ = f.audioProperties()->bitrate();
    frequency_ = f.audioProperties()->sampleRate();
    length_ = f.audioProperties()->length();
    stereo_ = f.audioProperties()->channels() > 1;
}

SongInfo::~SongInfo(){}

const std::wstring &SongInfo::get_filename() const
{
    return filename_;
}

const std::wstring &SongInfo::get_title() const
{
    return title_;
}

const std::wstring &SongInfo::get_artist() const
{
    return artist_;
}

const std::wstring &SongInfo::get_album() const
{
    return album_;
}

const unsigned &SongInfo::get_length() const
{
    return length_;
}

const unsigned &SongInfo::get_bitrate() const
{
    return bitrate_;
}

const unsigned &SongInfo::get_frequency() const
{
    return frequency_;
}

bool SongInfo::is_stereo() const
{
    return stereo_;
}

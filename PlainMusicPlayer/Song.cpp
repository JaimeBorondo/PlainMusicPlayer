#include "Song.h"
#include "SoundSystem.h"

#include <unordered_map>
#include <fileref.h>
#include <Windows.h>
#include <fstream>
#include <iostream>

Song::Song(const SongInfo &info) : info_(info)
{
    channel_ = nullptr;
}

Song::~Song()
{}

void Song::Play()
{
    SoundSystem::Play(&channel_, info_.get_filename());
}

void Song::Pause()
{
    SoundSystem::Pause(channel_);
}

void Song::Stop()
{
    SoundSystem::Stop(channel_);
}


bool Song::isPlaying()
{
    bool isplaying = false;

    if (channel_ != nullptr)
        channel_->isPlaying(&isplaying);

    return isplaying;
}

unsigned Song::GetPosition()
{
    unsigned retval = 0;

    if (channel_ != nullptr)
        channel_->getPosition(&retval, FMOD_TIMEUNIT_MS);

    return retval/1000;
}

void Song::SetPosition(float pct)
{
    if (channel_ != nullptr)
        channel_->setPosition(info_.get_length() * static_cast<unsigned>(pct * 1000), FMOD_TIMEUNIT_MS);
}

unsigned Song::GetLength()
{
    return info_.get_length();
}

//TODO, Separate these into files per class

#include <tbytevectorstream.h>

SongInfo::SongInfo(){}

SongInfo::SongInfo(const std::wstring &filename) : filename_(filename)
{
    TagLib::FileRef f(filename.c_str());
    album_ = f.tag()->album().toWString().data();
    artist_ = f.tag()->artist().toWString().data();
    title_ = f.tag()->title().toWString().data();

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
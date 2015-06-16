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

void Song::SetVolume(float vol)
{
    if(channel_ != nullptr)
        channel_->setVolume(vol);
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

std::wstring Song::GetDisplayName()
{
    return info_.get_display_name();
}

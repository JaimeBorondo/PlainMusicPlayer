#include "Song.h"
#include "SoundSystem.h"

#include <unordered_map>
#include <fileref.h>
#include <Windows.h>
#include <fstream>
#include <iostream>

Song::Song(const SongInfo &info) : info_(info)
{
    channel_ = 0;
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
    BASS_ChannelSetAttribute(channel_,BASS_ATTRIB_VOL,vol);
}

bool Song::isPlaying()
{
   return BASS_ChannelIsActive(channel_) == BASS_ACTIVE_PLAYING;
}

unsigned Song::GetPosition()
{
    QWORD bytes = BASS_ChannelGetPosition(channel_, BASS_POS_BYTE);
    
    int code = BASS_ErrorGetCode();
    
    return static_cast<unsigned>(BASS_ChannelBytes2Seconds(channel_, bytes));
}

void Song::SetPosition(float pct)
{
    QWORD len_bytes = BASS_ChannelGetLength(channel_, BASS_POS_BYTE);
    len_bytes = static_cast<QWORD>(static_cast<float>(len_bytes) * pct);
    
    BASS_ChannelSetPosition(channel_, len_bytes, BASS_POS_BYTE);
}

unsigned Song::GetLength()
{
    QWORD byteslen = BASS_ChannelGetLength(channel_, BASS_POS_BYTE);
    return BASS_ChannelBytes2Seconds(channel_, byteslen);
//    return info_.get_length();
}

std::wstring Song::GetDisplayName()
{
    return info_.get_display_name();
}

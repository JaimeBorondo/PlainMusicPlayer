#pragma once

#include "SongInfo.h"

#include <fmod.hpp>
#include <string>
#include <locale>

#include "bass.h"

class Song
{
public:
	Song(const SongInfo &info);
	~Song();

	void Play();
	void Pause(); //this is a toggle for now
	void Stop();
    void SetVolume(float vol);
    std::wstring GetDisplayName();

	bool isPlaying();

	unsigned GetPosition();
	void SetPosition(float pct);
	unsigned GetLength();
private:
	const SongInfo &info_;
	HCHANNEL channel_;
};

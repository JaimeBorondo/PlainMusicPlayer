#pragma once

#include <fmod.hpp>
#include <string>
#include <locale>
#include <codecvt>

#define TAGLIB_EXPORT
#define TAGLIB_EXPORT_H

//Songinfo doesnt need to be playable, only contain information about the track,
//An actual song will be created from it, and will store its channel.
class SongInfo
{
public:
	SongInfo();
	SongInfo(const std::wstring &filename);
	~SongInfo();

	const std::wstring &get_filename() const;
	const std::wstring &get_title() const;
	const std::wstring &get_artist() const;
	const std::wstring &get_album() const;
	const unsigned &get_length() const;
	const unsigned &get_bitrate() const;
	const unsigned &get_frequency() const;
	bool is_stereo() const;

private:
	std::wstring filename_;
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

	void Play();
	void Pause(); //this is a toggle for now
	void Stop();

	bool isPlaying();

	unsigned GetPosition();
	void SetPosition(float pct);
	unsigned GetLength();
private:
	const SongInfo &info_;
	FMOD::Channel *channel_;
};

#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>

#include "SoundSystem.h"

int main(void)
{
	SoundSystem::Initialize();

	std::locale::global(std::locale(""));

	SongInfo baby("killbill.mp3");
	Song baby_playable(baby);

	std::wofstream file("yesinfo");
	//const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf16<wchar_t>());
	//file.imbue(utf8_locale);
	file << "Artist    : " << baby.get_artist() << std::endl;
	file << "Album     : " << baby.get_album() << std::endl;
	file << "Title     : " << baby.get_title() << std::endl;
	file << "Length    : " << baby.get_length() << " seconds" << std::endl;
	file << "Frequency : " << baby.get_frequency() << " Hz" << std::endl;
	file << "Bitrate   : " << baby.get_bitrate() << " Kbps." << std::endl;

	baby_playable.Play();
	int i = 0;

	unsigned total_seconds = baby_playable.GetLength();
	while (true)
	{
		SoundSystem::Update();
		i++;

		if (i % 200000 == 0)
		{
			std::cout << "Time : " << baby_playable.GetPosition() << " / " << total_seconds << std::endl;
		}
	}

	return 0;
}
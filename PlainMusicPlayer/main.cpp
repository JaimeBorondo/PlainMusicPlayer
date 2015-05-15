#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>

//For debug info printing, remove on release
#include <io.h>
#include <fcntl.h>

#include "SoundSystem.h"

int main(void)
{
	SoundSystem::Initialize();

	SongInfo kb("killbill.mp3");
	Song kb_playable(kb);
    
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << L"Artist: " << kb.get_artist() << std::endl;
	std::wcout << L"Album: " << kb.get_album() << std::endl;
	std::wcout << L"Title: " << kb.get_title() << std::endl;
	
	/*
	kb_playable.Play();
	int i = 0;

	unsigned total_seconds = kb_playable.GetLength();
	while (true)
	{
		SoundSystem::Update();
		i++;

		if (i % 200000 == 0)
		{
			std::cout << "Time : " << kb_playable.GetPosition() << " / " << total_seconds << std::endl;
		}
	}
	*/
	return 0;
}
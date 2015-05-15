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

	SongInfo kb(L"라라랄.mp3");
	Song kb_playable(kb);

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
	
	return 0;
}
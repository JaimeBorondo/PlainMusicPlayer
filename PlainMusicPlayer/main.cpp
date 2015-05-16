#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>

//For debug info printing, remove on release
#include <io.h>
#include <fcntl.h>

#include "SoundSystem.h"
#include "Playlist.h"
#include "Library.h"

int main(void)
{
	SoundSystem::Initialize();

	TopLevelLibrary top(
	{
		L"01 The Boys.mp3",
		L"02 텔레파시 (Telepathy).mp3",
		L"03 Say Yes.mp3",
		L"04 Trick.mp3",
		L"05 봄날 (How Great Is Your Love).mp3",
		L"06 My J.mp3",
		L"07 Oscar.mp3",
		L"08 Top Secret.mp3",
		L"09 Lazy Girl (Dolce Far Niente).mp3",
		L"10 제자리걸음 (Sunflower).mp3",
		L"11 비타민 (Vitamin).mp3"
	}
	);

	Playlist theboys = top.PlaylistFromAlbum(top.GetAlbums()[0]);
	theboys.Shuffle();
	theboys.SetCurrentSong(0);

	while (true)
	{
		SoundSystem::Update();
		theboys.Update();
	}
	
	return 0;
}
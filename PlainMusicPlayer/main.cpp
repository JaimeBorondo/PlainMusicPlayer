#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>

int main(void)
{
	//TODO, move this into an actual parser for tags
	SongInfo baby(L"killbill.mp3");
	SongInfo say(L"yes.mp3");

	std::wofstream file(L"file.txt");

	std::wcout << L"Song 1 :" << std::endl;
	std::wcout << L"\tArtist : " << baby.get_artist() << std::endl;
	std::wcout << L"\tTitle : " << baby.get_name() << std::endl;
	std::wcout << L"\tAlbum : " << baby.get_album() << std::endl;
				  
	std::wcout << L"Song 2 :" << std::endl;
	std::wcout << L"\tArtist : " << say.get_artist() << std::endl;
	std::wcout << L"\tTitle : " << say.get_name() << std::endl;
	std::wcout << L"\tAlbum : " << say.get_album() << std::endl;

	return 0;
}
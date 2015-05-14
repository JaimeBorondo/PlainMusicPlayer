#include "Song.h"
#include <unordered_map>
#include <id3\tag.h>

Song::Song(const SongInfo &info) : info_(info)
{
	channel_ = nullptr;
}

Song::~Song()
{}

SongInfo::SongInfo(const std::wstring &filename) : filename_(filename)
{
	ID3_Tag mytag(reinterpret_cast<const char *>(filename.c_str()));

	//Will probably store this eventually, I can get the length and bitrate from here
	//const Mp3_Headerinfo *h = mytag.GetMp3HeaderInfo();

	std::unordered_map<ID3_FrameID, std::wstring> song_tag;

	ID3_Tag::Iterator *it = mytag.CreateIterator();
	ID3_Frame *fr = nullptr;

	while (NULL != (fr = it->GetNext()))
	{
		ID3_FrameInfo fi;
		ID3_FrameID identifier = fr->GetID();

		if (identifier != ID3FID_TITLE && identifier != ID3FID_ALBUM && identifier != ID3FID_LEADARTIST)
			continue;

		ID3_Frame::Iterator* iter = fr->CreateIterator();
		ID3_Field* field = NULL;

		while (NULL != (field = iter->GetNext()))
			if (field->GetType() == ID3_FieldType::ID3FTY_TEXTSTRING)
			{
				song_tag[identifier] = (wchar_t*)field->GetRawUnicodeText();
			}
	}

	std::unordered_map<ID3_FrameID, std::wstring>::iterator foundtitle, foundalbum, foundartist;
	foundtitle = song_tag.find(ID3FID_TITLE);
	foundalbum = song_tag.find(ID3FID_ALBUM);
	foundartist = song_tag.find(ID3FID_LEADARTIST);
	
	name_ = foundtitle != song_tag.end() ? foundtitle->second : L"Unknown";
	album_ = foundalbum != song_tag.end() ? foundalbum->second : L"Unknown";
	artist_ = foundartist != song_tag.end() ? foundartist->second : L"Unknown";
}

SongInfo::~SongInfo(){}

const std::wstring &SongInfo::get_filename()
{
	return filename_;
}

const std::wstring &SongInfo::get_name()
{
	return name_;
}

const std::wstring &SongInfo::get_artist()
{
	return artist_;
}

const std::wstring &SongInfo::get_album()
{
	return album_;
}

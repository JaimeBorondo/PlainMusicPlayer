#include "inc\id3\tag.h"
#include <unordered_map>

int main(void)
{
	//TODO, move this into an actual parser for tags

	std::unordered_map<std::string, std::string> song_tag;

	ID3_Tag mytag("song.mp3");
	const Mp3_Headerinfo *h = mytag.GetMp3HeaderInfo();
	ID3_Tag::Iterator *it = mytag.CreateIterator();
	ID3_Frame *fr = nullptr;

	while (NULL != (fr = it->GetNext()))
	{
		ID3_FrameInfo fi;
		std::string identifier = fi.Description(fr->GetID());

		ID3_Frame::Iterator* iter = fr->CreateIterator();
		ID3_Field* myField = NULL;
		while (NULL != (myField = iter->GetNext()))
		{
			ID3_FieldID id = myField->GetID();
			
			if (myField->GetType() == ID3_FieldType::ID3FTY_TEXTSTRING)
			{
				song_tag[identifier] = myField->GetRawText();
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
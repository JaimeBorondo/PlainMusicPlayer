#include "SoundSystem.h"
#include <locale>
#include <string>
#include <codecvt>

#include <QMessageBox>

#include "bass.h"

void SoundSystem::Initialize()
{
    int err = BASS_OK;
    
    if(!BASS_Init(-1, 44100, 0, 0, NULL))
        err = BASS_ErrorGetCode();
    
    if(err != BASS_OK)
        throw "BASS Error: " + std::to_string(err) + " raised."; 
}

void SoundSystem::Play(Channel *ch, const std::wstring &filename)
{
//	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> conversion;
	//std::string mbs = conversion.to_bytes((const char16_t *)filename.c_str());
	
    HSTREAM handle = BASS_StreamCreateFile(FALSE,filename.c_str(),0,0,0);
    
    int code = BASS_ErrorGetCode();
    BASS_ChannelPlay(handle,TRUE);
    code = BASS_ErrorGetCode();
    
    *ch = handle;
    /*
	FMOD::Sound *snd;

	FMOD_RESULT res = system_->createStream(mbs.c_str(), FMOD_DEFAULT, 0, &snd);
    
	system_->playSound(snd, nullptr, false, ch);*/
}

void SoundSystem::Pause(Channel ch)
{
	bool ispaused = (BASS_ChannelIsActive(ch) == BASS_ACTIVE_PAUSED);
    
    if(ispaused)
        BASS_ChannelPlay(ch,FALSE);
    else
        BASS_ChannelPause(ch);
}

void SoundSystem::Stop(Channel ch)
{
	BASS_ChannelStop(ch);
}

void SoundSystem::Update()
{
	BASS_Update(16);
}

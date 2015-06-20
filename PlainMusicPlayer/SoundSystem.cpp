﻿#include "SoundSystem.h"
#include <locale>
#include <string>
#include <codecvt>

#include <QMessageBox>

#include "bass.h"

FMOD::System *SoundSystem::system_;

void SoundSystem::Initialize()
{
//	FMOD_RESULT res = FMOD::System_Create(&system_);

	//if (res != FMOD_OK)
		//throw "Initialization unsuccessful";

	//system_->init(32, FMOD_INIT_NORMAL, nullptr);

    if(!BASS_Init(device, freq, 0, 0, NULL))
        err = BASS_ErrorGetCode();
    
    if(err != BASS_OK)
        throw "BASS Error: " + std::to_string(err) + " raised."; 
}

void SoundSystem::Play(ChPtr *ch, const std::wstring &filename)
{
	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> conversion;
	std::string mbs = conversion.to_bytes((const char16_t *)filename.c_str());
	
	FMOD::Sound *snd;

	FMOD_RESULT res = system_->createStream(mbs.c_str(), FMOD_DEFAULT, 0, &snd);
    
	system_->playSound(snd, nullptr, false, ch);
    
    if(res == FMOD_ERR_FORMAT)
    {
        QMessageBox msg;
        msg.setText("Invalid format");
        msg.setInformativeText("Track \"" + QString::fromStdWString(filename) + "\" was skipped.");
        msg.setStandardButtons(QMessageBox::Ok);
        
        msg.exec();
    }
}

void SoundSystem::Pause(ChPtr ch)
{
	bool playing = false;
	ch->getPaused(&playing);
	ch->setPaused(!playing);
}

void SoundSystem::Stop(ChPtr ch)
{
	ch->stop();
}

void SoundSystem::Update()
{
	system_->update();
}

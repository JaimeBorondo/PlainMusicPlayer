﻿#include "SoundSystem.h"
#include <locale>
#include <string>
#include <codecvt>

#include <QMessageBox>

FMOD::System *SoundSystem::system_;

void SoundSystem::Initialize()
{
	FMOD_RESULT res = FMOD::System_Create(&system_);

	if (res != FMOD_OK)
		throw "Initialization unsuccessful";

	system_->init(32, FMOD_INIT_NORMAL, nullptr);
}

void SoundSystem::Play(FMOD::Channel **ch, const std::wstring &filename)
{
	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> conversion;
	std::string mbs = conversion.to_bytes((const char16_t *)filename.c_str());
	
	FMOD::Sound *snd;

	FMOD_RESULT res = system_->createSound(mbs.c_str(), FMOD_LOOP_OFF, nullptr, &snd);
    
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

void SoundSystem::Pause(FMOD::Channel *ch)
{
	bool playing = false;
	ch->getPaused(&playing);
	ch->setPaused(!playing);
}

void SoundSystem::Stop(FMOD::Channel *ch)
{
	ch->stop();
}

void SoundSystem::Update()
{
	system_->update();
}

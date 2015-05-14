#include "SoundSystem.h"

FMOD::System *SoundSystem::system_;

void SoundSystem::Initialize()
{
	FMOD_RESULT res = FMOD::System_Create(&system_);

	if (res != FMOD_OK)
		throw "Initialization unsuccessful";

	system_->init(32, FMOD_INIT_NORMAL, nullptr);
}

void SoundSystem::Play(FMOD::Channel **ch, const std::string &filename)
{
	FMOD::Sound *snd;
	system_->createStream(filename.c_str(), FMOD_LOOP_OFF, nullptr, &snd);
	system_->playSound(snd, nullptr, false, ch);
}

void SoundSystem::Update()
{
	system_->update();
}
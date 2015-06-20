#include <fmod.hpp>
#include <string>

#include "bass.h"

typedef HCHANNEL * ChPtr;

class SoundSystem
{
public:
	static void Initialize();
	
	static void Play(ChPtr *ch, const std::wstring &filename);
	static void Pause(ChPtr ch);
	static void Stop(ChPtr ch);

	static void Update();

private:
	static FMOD::System *system_;
};

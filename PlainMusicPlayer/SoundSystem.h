#include <fmod\fmod.hpp>
#include <string>

class SoundSystem
{
public:
	static void Initialize();
	
	static void Play(FMOD::Channel **ch, const std::wstring &filename);
	static void Pause(FMOD::Channel *ch);
	static void Stop(FMOD::Channel *ch);

	static void Update();

private:
	static FMOD::System *system_;
};
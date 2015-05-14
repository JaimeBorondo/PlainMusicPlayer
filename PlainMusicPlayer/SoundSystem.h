#include <fmod\fmod.hpp>
#include <string>

class SoundSystem
{
public:
	static void Initialize();
	static void Play(FMOD::Channel **ch, const std::string &filename);
	static void Update();

private:
	static FMOD::System *system_;
};
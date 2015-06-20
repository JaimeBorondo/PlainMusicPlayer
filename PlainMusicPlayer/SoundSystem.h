#include <string>

#include "bass.h"

typedef HCHANNEL Channel;

class SoundSystem
{
public:
	static void Initialize();
	
	static void Play(Channel *ch, const std::wstring &filename);
	static void Pause(Channel ch);
	static void Stop(Channel ch);

	static void Update();
};

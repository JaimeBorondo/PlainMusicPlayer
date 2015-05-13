#include "portaudio.h"
#include <cstdio>

void PrintError(int &err)
{
	printf("Portaudio reported error %d : %s\n", err, Pa_GetErrorText(err));
}

int main(void)
{
	int result = Pa_Initialize();

	if (result != paNoError)
	{
		PrintError(result);
		return -1;
	}




	Pa_Terminate();

	return 0;
}
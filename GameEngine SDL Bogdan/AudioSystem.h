#pragma once
#include "../SDL2_mixer-2.0.4/include/SDL_mixer.h"
#include <string>

class AudioSystem
{
public:
	AudioSystem();
	~AudioSystem();


	Mix_Music* menuMusic;

	Mix_Music* gameMusic;

	Mix_Music* winMusic;

	Mix_Chunk* keySound;

	Mix_Chunk* monsterHit;

	Mix_Chunk* buttonClick;

	static AudioSystem& getInstance()
	{
		static AudioSystem    instance;

		return instance;
	}

	bool loadAudio();

	void Close();
};
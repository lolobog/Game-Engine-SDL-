#pragma once
#include "../SDL2_mixer-2.0.4/include/SDL_mixer.h"
#include <string>

class AudioSystem
{
public:
	AudioSystem();
	~AudioSystem();

/**
* Mix_Music variable that will hold the Main Menu Music audio file upon loading the audio
*/
	Mix_Music* menuMusic;

	/**
* Mix_Music variable that will hold the Game Level Music audio file upon loading the audio
*/
	Mix_Music* gameMusic;

	/**
* Mix_Music variable that will hold the Win Screen Music audio file upon loading the audio
*/
	Mix_Music* winMusic;

	/**
* Mix_Chunk variable that will hold the Key Sound audio file upon loading the audio
*/
	Mix_Chunk* keySound;

	/**
* Mix_Chunk variable that will hold the Monster Hit audio file upon loading the audio
*/
	Mix_Chunk* monsterHit;

	/**
* Mix_Chunk variable that will hold the Button Click audio file upon loading the audio
*/
	Mix_Chunk* buttonClick;

	/**
* Create an instance of the class which is accessible anywhere in the project through the function
*/
	static AudioSystem& getInstance()
	{
		static AudioSystem    instance;

		return instance;
	}


	/**
* Loads all of the audio files required for the 
*/
	bool loadAudio();

	/**
* Clears out all the pointers used in the Audio System, clears all the Mix_Music and Mix_Chunk variables and exits Mixer
*/
	void Close();
};
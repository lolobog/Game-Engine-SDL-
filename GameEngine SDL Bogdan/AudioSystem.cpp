#include "AudioSystem.h"

AudioSystem::AudioSystem()
{

}


AudioSystem::~AudioSystem()
{

}

bool AudioSystem::loadAudio()
{
	bool success = true;

	//Load Music

	menuMusic = Mix_LoadMUS("sounds/menuMusic.wav");
	if (menuMusic == NULL)
	{
		printf("Failed to load menu music! SDL_mixer Error: ", Mix_GetError());
		success = false;
	}

	gameMusic = Mix_LoadMUS("sounds/gameMusic.wav");
	if (gameMusic == NULL)
	{
		printf("Failed to load game music! SDL_mixer Error: ", Mix_GetError());
		success = false;
	}

	winMusic = Mix_LoadMUS("sounds/winMusic.wav");
	if (winMusic == NULL)
	{
		printf("Failed to load win music! SDL_mixer Error: ", Mix_GetError());
		success = false;
	}

	//Load Sound effects
	keySound = Mix_LoadWAV("sounds/keyCollect.wav");
	if (keySound == NULL)
	{
		printf("Failed to load key sound! SDL_mixer Error: ", Mix_GetError());
		success = false;
	}

	monsterHit = Mix_LoadWAV("sounds/hurtSound.wav");
	if (monsterHit == NULL)
	{
		printf("Failed to load monster hit sound! SDL_mixer Error: ", Mix_GetError());
		success = false;
	}

	buttonClick= Mix_LoadWAV("sounds/buttonClick.wav");
	if (buttonClick == NULL)
	{
		printf("Failed to load button click sound! SDL_mixer Error: ", Mix_GetError());
		success = false;
	}

	return success;
}

void AudioSystem::Close()
{
	Mix_FreeChunk(keySound);
	Mix_FreeChunk(monsterHit);
	Mix_FreeChunk(buttonClick);
	Mix_FreeMusic(menuMusic);
	Mix_FreeMusic(gameMusic);
	Mix_FreeMusic(winMusic);
	menuMusic = NULL;
	gameMusic = NULL;
	winMusic = NULL;
	keySound = NULL;
	monsterHit = NULL;

	Mix_Quit();
}

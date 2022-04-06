#ifndef GAME_H
#define GAME_H
#include "MenuScene.h"
#include "WinScene.h"
#include "SceneManager.h"
#include <stdio.h>;
#include "bitmap.h";
#include <string>;
#include "SDL_ttf.h";
#include "creature.h";
#include <vector>
#include "input.h"
#include "imgui-master/imgui.h"
#include "imgui-master/backends/imgui_impl_sdl.h"
#include "imgui_sdl-master/imgui_sdl.h"
#include "imgui-master/imgui_internal.h"
#include "FrameTimer.h"
#include <iostream>
#include "../SDL2_image-2.0.5/include/SDL_image.h"
#include "Profiler.h"


using namespace std;

class Game
{
	
private:
	/**
* Main SDL Window
*/
	SDL_Window* m_Window;
	/**
* Main renderer used for generating all the images
*/
	SDL_Renderer* m_Renderer;
	/**
* Frame Timer used to keep track of the game frame times
*/
	FrameTimer m_timer;
	/**
* Counter for loading in the assets
*/
	int count = 119;
	/**
* Vector containing all the assets
*/
	vector<Bitmap*> content;
	/**
* Variable representing the number of assets in the folder
*/
	int numberOfImages = 0;
	/**
* Height of the window
*/
	float windowHeight = 720;
	/**
* Width of the window
*/
	float windowWidth = 960;
	/**
* Reference to the image being dragged
*/
	Bitmap* AssetMouseDrag;
	/**
* Vector storing all profile times
*/
	vector<Sample*> Snapshot;
	/**
* Reference to the previous frame to be displayed on the flame graph
*/
	Sample* previousFrame;
	/**
* Reference to the targeted frame to be displayed on the flame graph
*/
	Sample* targetFrame;
	
	

public:
	/**
* Default Game constructor
*/
	Game();
	/**
* Default Game destructor
*/
	~Game();
	/**
*  Game Scene Manager
*/
	SceneManager sManager;
	/**
*  Display background color set up
*/
	void SetDisplayColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	/**
*  Update the scene, GUI and anything else every frame
*/
	void Update(void) ;
	/**
*  Update the texts 
*/
	void UpdateText(string msg, int x, int y, TTF_Font* font, SDL_Color colour);
	

	
	/**
*  Return a reference to the renderer
*/
	SDL_Renderer& GetRenderer()
	{
		return *m_Renderer;
	}
	
	/**
*  Return a reference to the SDL window
*/
	SDL_Window& GetWindow()
	{
		return *m_Window;
	}
	

	/**
*  Small font Text
*/
	TTF_Font* m_pSmallFont;
	/**
*  Big font Text
*/
	TTF_Font* m_pBigFont;




	

	
};
#endif


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
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	bool m_running;
	Input PlayerInput;
	FrameTimer m_timer;
	int count = 119;
	vector<Bitmap*> content;
	int numberOfImages = 0;
	float screenHeight = 720;
	float screenWidth = 960;
	float menuHeight = 10;
	Bitmap* AssetMouseDrag;
	vector<Sample*> Snapshot;
	Sample* previousFrame;
	Sample* targetFrame;
	
	

public:
	
	Game();
	~Game();
	SceneManager sManager;
	void SetDisplayColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void Update(void) ;
	void CheckEvents(void) {};
	void UpdateText(string msg, int x, int y, TTF_Font* font, SDL_Color colour);
	

	

	SDL_Renderer& GetRenderer()
	{
		return *m_Renderer;
	}
	

	SDL_Window& GetWindow()
	{
		return *m_Window;
	}
	
	Scene* scene;


	TTF_Font* m_pSmallFont;
	TTF_Font* m_pBigFont;




	

	
};
#endif


#ifndef GAME_H
#define GAME_H
#include <stdio.h>;
#include "bitmap.h";
#include <string>;
#include "SDL_ttf.h";
#include "creature.h";
#include <vector>
#include "Scene.h"
#include "input.h"
#include "imgui-master/imgui.h"
#include "imgui-master/backends/imgui_impl_sdl.h"
#include "imgui_sdl-master/imgui_sdl.h"
#include "imgui-master/imgui_internal.h"
#include "FrameTimer.h"
#include <iostream>

using namespace std;

class Game
{
	
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	bool m_running;
	Input PlayerInput;
	FrameTimer m_timer;
	int count = 0;
	

public:
	Game();
	~Game();

	void SetDisplayColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void Update(void) ;
	void CheckEvents(void) {};
	void UpdateText(string msg, int x, int y, TTF_Font* font, SDL_Color colour);

	static Game& getInstance()
	{
		static Game    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}

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


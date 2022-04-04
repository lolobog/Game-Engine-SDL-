#pragma once
#include "Scene.h"

class WinScene : public Scene
{
public:
	WinScene(SDL_Renderer* renderer, ImGuiIO& _io);
	~WinScene();

	void Update();

private:
};
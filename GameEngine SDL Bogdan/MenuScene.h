#pragma once
#include "Scene.h";


class MenuScene : public Scene
{
public:
	MenuScene(SDL_Renderer* renderer, ImGuiIO& _io);
	~MenuScene();
private:
	
	
	void Update();
};
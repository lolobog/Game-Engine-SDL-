#pragma once
#include "Scene.h";


class MenuScene : public Scene
{
public:
	MenuScene(SDL_Renderer* renderer, ImGuiIO& _io);
	~MenuScene();
	void Update();

private:
	ImVec2 buttonSize = ImVec2(700, 300);
	ImVec2 MenuPos = ImVec2(120, 50);
	
	
};
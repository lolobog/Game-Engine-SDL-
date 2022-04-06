#pragma once
#include "Scene.h";


class MenuScene : public Scene
{
public:
	MenuScene(SDL_Renderer* renderer, ImGuiIO& _io);
	~MenuScene();
	/**
* Update the menu scene
*/
	void Update();

private:
	/**
* Size of the menu buttons
*/
	ImVec2 buttonSize = ImVec2(700, 300);
	/**
* Position of the ImGUI window in the SDL window
*/
	ImVec2 MenuPos = ImVec2(120, 50);
	
	
};
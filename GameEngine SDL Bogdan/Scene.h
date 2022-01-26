#pragma once
#include "GameObject.h"
#include "hero.h"
#include <vector>


using namespace std;


enum Layers
{
	background,
	level,
	playerEnemy,
	hud,
	NumLayers

};

class Scene
{
private:
		SDL_Renderer* m_rednerere;
		ImGuiIO* io = nullptr;
public:
	//vector <GameObject> SceneObjects;
	vector <vector <GameObject*>> LayerObjects;
	Hero* Player;
	

	Scene(SDL_Renderer *renderer, ImGuiIO& io);

	


	void Update();
	
};

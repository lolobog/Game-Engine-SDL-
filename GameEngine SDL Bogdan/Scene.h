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
		
		GameObject* Root;
public:
	vector <GameObject*> SceneObjects;
	vector <GameObject*> Walls;
	//vector <vector <GameObject*>> LayerObjects;
	Hero* Player;
	ImGuiIO* io = nullptr;
	

	GameObject* GetRoot()
	{
		return Root;
	}
	Scene(SDL_Renderer *renderer, ImGuiIO& io);

	//vector<vector<GameObject*>> GetGameObjects()
	//{
	//	return LayerObjects;
	//}
	


	void Update();
	
};

#pragma once
#include <Windows.h>
#include "GameObject.h"
#include "hero.h"
#include "creature.h"
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
		GameObject* Root;
public:
	SDL_Renderer* m_rednerere;
	vector <GameObject*> SceneObjects;
	vector <GameObject*> Walls;
	vector <GameObject*> Collidables;
	vector <Creature*>CreatureAIs;
	//vector <vector <GameObject*>> LayerObjects;
	EventManger* EventManager = new EventManger();
	CollectionEvent* keyCollected= new CollectionEvent();
	Hero* Player=nullptr;
	GameObject* Key;
	GameObject* Door;
	ImGuiIO* io = nullptr;
	

	GameObject* GetRoot()
	{
		return Root;
	}
	void ResetLevel()
	{
		Player->transform->x = 40;
		Player->transform->y = 40;
		Player->keyCollected = false;
		Key->transform->w = 70;
		Key->transform->h = 70;
		Key->transform->x = 862;
		Key->transform->y = 505;
	}
	Scene(SDL_Renderer *renderer, ImGuiIO& _io);
	Scene();
	
	


	virtual void Update();
	
};

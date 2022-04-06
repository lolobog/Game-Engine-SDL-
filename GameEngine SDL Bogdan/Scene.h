#pragma once
#include <Windows.h>
#include "GameObject.h"
#include "hero.h"
#include "creature.h"
#include <vector>
#include "AudioSystem.h"


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
		
public:
	/**
* Reference to the renderer
*/
	SDL_Renderer* m_rednerere;
	/**
* Vector containing all the Game Objects present in the scene
*/
	vector <GameObject*> SceneObjects;
	/**
* Vector containing all the collidable Wall Game Objects present in the scene
*/
	vector <GameObject*> Walls;
	/**
* Vector containing all the collidable Game Objects present in the scene(without the Walls)
*/
	vector <GameObject*> Collidables;
	/**
* Vector containing all the Game Objects that use AI present in the scene(without the Walls)
*/
	vector <Creature*>CreatureAIs;
	/**
* Scene Audio Manager 
*/
	AudioSystem audioManager;
	/**
* Scene Event Manager 
*/
	EventManger* EventManager = new EventManger();
	/**
* Event to check for they key being collected
*/
	CollectionEvent* keyCollected= new CollectionEvent();
	/**
* Reference to the Player 
*/
	Hero* Player=nullptr;
	/**
* ImGuiIO reference 
*/
	ImGuiIO* io = nullptr;
	/**
* Key Game Object Reference
*/
	GameObject* Key;
	/**
* Door Game Object Reference
*/
	GameObject* Door;
	/**
* Root Game Object Reference
*/
	GameObject* Root;
	
	
	/**
* Returns a reference to the Root Game Object Reference
*/
	GameObject* GetRoot()
	{
		return Root;
	}
	/**
* Reset the scene to its initial state
*/
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
	
	

	/**
* Update the scene
*/
	virtual void Update();
	
};

 #pragma once
#include "Resource_Manager.h"
#include "input.h"
#include "GameObject.h"


class Hero : public GameObject
{
public: 
	/**
* Boolean representing if the Key was collected
*/
	bool keyCollected = false;

	Hero(SDL_Renderer* renderer, Bitmap* bitmap, ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z = 0);
	~Hero();
	
	/**
* Triggers upon a specific event being fired
*/
	void OnEvent(Event* event)
	{
		keyCollected = true;
		std::cout << "Key collected\n";

	}


	

private:
	
};
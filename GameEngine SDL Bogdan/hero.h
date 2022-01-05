 #pragma once
#include "Resource_Manager.h"
#include "input.h"
#include "GameObject.h"


class Hero : public GameObject
{
public: 
	

	Hero(SDL_Renderer* renderer, Bitmap* bitmap, float _w, float _h, float _x, float _y, float _z = 0);
	~Hero();



	void InputUpdate(Input input);

private:
	int speed = 2;
	int hp = 3;
};
 #pragma once
#include "Resource_Manager.h"
#include "input.h"
#include "GameObject.h"


class Hero : public GameObject
{
public: 
	

	Hero(SDL_Renderer* renderer, Bitmap* bitmap, ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z = 0);
	~Hero();
	
	virtual void OnEvent(Event& event);

	void DrawGUI() override
	{

	}


	void InputUpdate(Input input);

	bool keyCollected = false;

private:
	int speed = 2;
	int hp = 3;
};
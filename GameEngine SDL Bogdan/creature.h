#pragma once
#include "GameObject.h"

class Creature: public GameObject
{
public:
	float target1, target2;
	Creature(SDL_Renderer* renderer, Bitmap* bitmap, ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z = 0);
	Creature();
	~Creature();

	

	void LogicUpdate();
	
	void MoveBetweenPoints(float y1,float y2);
	
private:
	
	bool pointReached = false;
};

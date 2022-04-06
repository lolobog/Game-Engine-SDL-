#pragma once
#include "GameObject.h"

class Creature: public GameObject
{
public:
	/**
* 2 points on the Y axis to which the Creature has to move 
*/
	float target1, target2;
	/**
* Constructor for the Creature class taking a Renderer, Bitmap, ImGuiIO, width, length , position on x, position on y, position on z
*/
	Creature(SDL_Renderer* renderer, Bitmap* bitmap, ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z = 0);
	/**
* Default constructor for the Creature class
*/
	Creature();
	/**
* Default destructor for the Creature class
*/
	~Creature();

	
	/**
* Update the AI logic 
*/
	void LogicUpdate();
	
	/**
* Move the creature on the Y axis between 2 points
*/
	void MoveBetweenPoints(float y1,float y2);
	
private:
	/**
* boolean variable representing if target 1 was reached
*/
	bool pointReached = false;
};

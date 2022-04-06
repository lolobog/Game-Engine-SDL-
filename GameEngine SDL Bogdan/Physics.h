#pragma once

class GameObject;


class Physics
{
private:
	/**
* Reference to the Game Object holding the Physics object
*/
	GameObject* obj;

public:
	/**
* Constructor for the Physics class requiring the owner of the object
*/
	Physics(GameObject* owner);
	/**
* Default Destructor
*/
	~Physics();

	/**
* Check if the Game Object holding the Physics object is colliding with any other Game Object
*/
	bool CheckCollision(GameObject* obj2);
	/**
* Check if the Game Object holding the Physics object is colliding with any other Game Object on the X axis
*/
	bool CheckXCollision(GameObject* obj2);
	/**
* Check if the Game Object holding the Physics object is colliding with any other Game Object on the Y axis
*/
	bool CheckYCollision(GameObject* obj2);

	

	
	
};
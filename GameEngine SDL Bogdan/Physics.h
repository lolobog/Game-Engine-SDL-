#pragma once

class GameObject;


class Physics
{
private:
	GameObject* obj;

public:
	Physics(GameObject* owner);
	
	~Physics();

	bool CheckCollision(GameObject* obj2);

	bool CheckXCollision(GameObject* obj2);

	bool CheckYCollision(GameObject* obj2);

	

	
	
};
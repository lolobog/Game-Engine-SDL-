#pragma once
#include "SDL_render.h"
#include "Vector2D.h"
#include "bitmap.h"
#include "EventManager.h"
#include <Box2D.h>

struct Transform 
{
public :
	float w, h, x, y, z;

	Vector2D position;
	Vector2D velocity;

	Transform() {
		this->w = 100;
		this->h = 100;
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Transform(float w, float h, float x, float y, float z)
	{
		this->w = w;
		this->h = h;
		this->x = x;
		this->y = y;
		this->z = z;

		this->position.x = x;
		this->position.y = y;
	}

};


class GameObject: public IEventHandler
{
	
	

private:
	SDL_Renderer* m_Renderer;
	
public:
	Bitmap* m_bitmap;
	Transform* transform;
	GameObject(SDL_Renderer* renderer,Bitmap* bitmap, float _w, float _h, float _x, float _y, float _z = 0);
	
	GameObject();
	~GameObject();

	virtual void OnEvent(Event& event);

	//Hierarchy
	GameObject* parent = nullptr;
	std::vector <GameObject*> children;

	void SetParent(GameObject* obj) { this->parent = obj; }
	void AddChild(GameObject* obj) 
	{ 
		children.push_back(obj); 
		obj->SetParent(this);
	};

	

	Transform* getTransform() 
	{ 
		return transform; 
	}

	void ChangeTransform(Transform* newTransform) 
{ 
		transform = newTransform; 
	}

	Vector2D getPosition() 
	{
		return transform->position; 
	}
	
	void setPosition(Vector2D newPos);
	void setY(float y);
	void setX(float x);
	

	void Draw();

	void LogicUpdate();


	virtual void Update()
	{
		Draw();
		LogicUpdate();

	}


};
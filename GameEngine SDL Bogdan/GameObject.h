#pragma once
#include "SDL_render.h"
#include "Vector2D.h"
#include "bitmap.h"
#include "EventManager.h"
#include <Box2D.h>
#include "imgui-master/imgui.h"
#include "imgui-master/backends/imgui_impl_sdl.h"
#include "imgui_sdl-master/imgui_sdl.h"
#include "imgui-master/imgui_internal.h"
#include "I_GUI.h"

struct Transform 
{
public :
	float w, h, x, y, z;

	float* getXAddr()
	{
		return &x;
	}
	float* getYAddr()
	{
		return &y;
	}

	//Vector2D position;
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

		//this->position.x = x;
		//this->position.y = y;
	}

};


class GameObject: public IEventHandler, public I_GUI
{
	
	

private:
	SDL_Renderer* m_Renderer;


protected:
	ImGuiIO* io;
	
public:
	Bitmap* m_bitmap;
	Transform* transform;
	std::string objectName;
	GameObject(std::string _objectName,SDL_Renderer* renderer,Bitmap* bitmap,ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z = 0);
	
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
		//return transform->position; 
		return Vector2D(transform->x, transform->y);
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

	bool isClickingOn()
	{
		SDL_Rect rect;
		rect.x = transform->x;
		rect.y = transform->y;
		rect.h = m_bitmap->GetSurface()->h;
		rect.w = m_bitmap->GetSurface()->w;

		SDL_Point point;
		point.x = io->MousePos.x;
		point.y = io->MousePos.y;

		
		return (SDL_PointInRect(&point, &rect)&&io->MouseClicked[0]);
	}

	 void DrawGUI() override
	{
		ImGui::Begin(objectName.c_str());

		ImGui::InputFloat("X", transform->getXAddr(), 0.1f, 1.0f, "%.3f");

		ImGui::InputFloat("Y", transform->getYAddr(), 0.1f, 1.0f, "%.3f");

		ImGui::End();
	}
	
	 void MouseHeld(ImGuiIO& io) override
	 {
		 if (I_GUI::ObjectTargeted==this)
		 {
			 transform->x += io.MouseDelta.x;
			 transform->y += io.MouseDelta.y;

		 }
	 }

};
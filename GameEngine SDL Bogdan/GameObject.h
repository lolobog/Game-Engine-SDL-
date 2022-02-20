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
#include <iostream>

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

		
	}

};


class GameObject: public IEventHandler, public I_GUI
{
	
	

private:
	SDL_Renderer* m_Renderer;
	

protected:
	ImGuiIO* io;
	
public:
	std::vector<std::string> Tags;
	Bitmap* m_bitmap;
	Transform* transform;
	std::string objectName;
	GameObject(std::string _objectName,SDL_Renderer* renderer,Bitmap* bitmap,ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z = 0);

	//GameObject(std::string _objectName, SDL_Renderer* renderer, Bitmap* bitmap, ImGuiIO& _io, float _x, float _y, float _z = 0);

	//GameObject(std::string _objectName, SDL_Renderer* renderer, Bitmap* bitmap, ImGuiIO& _io);

	GameObject(std::string _objectName, SDL_Renderer* renderer,  ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z = 0);
	
	GameObject();

	~GameObject();
	
	virtual void OnEvent(Event& event);

	//Hierarchy
	GameObject* parent = nullptr;
	std::vector <GameObject*> children;
	bool visited = false;

	void RemoveChild(GameObject* obj)
	{
		if (obj->parent != nullptr)
		{
			for (int i = 0; i < obj->parent->children.size(); i++)
			{
				if (obj->parent->children[i] == obj)
				{
					obj->parent->children.erase(obj->parent->children.begin() + i);
				}
			}
		}
	}


	void SetParent(GameObject* obj) 
	{ 
		RemoveChild(this);

		
		this->parent = obj;
		obj->children.push_back(this);
	}
	void AddChild(GameObject* obj) 
	{ 
		RemoveChild(obj);


		children.push_back(obj); 
		obj->parent = this;
		
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


	 void DrawChildGUI()
	 {
		 
		ImGuiTreeNodeFlags nodeFlags = ImGuiTreeNodeFlags_FramePadding | ImGuiTreeNodeFlags_DefaultOpen;
		bool isOpen = ImGui::TreeNodeEx(this->objectName.c_str(), nodeFlags);

		if (ImGui::IsItemClicked())
		{
			I_GUI::EditorToShow = this;
			std::cout << "selected object is: "<<static_cast<GameObject*>(I_GUI::EditorToShow)->objectName << std::endl;
		}
		if (I_GUI::EditorToShow == this && ImGui::BeginDragDropSource())
		{
			ImGui::SetDragDropPayload("_TREENODE", this, sizeof(GameObject*));
			ImGui::Text("This is a drag and drop source");
			ImGui::EndDragDropSource();
		}
		if (ImGui::BeginDragDropTarget())
		{
			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("_TREENODE"))
			{
				GameObject* PayloadAsGameObject = static_cast<GameObject*>(I_GUI::EditorToShow);
				std::cout << PayloadAsGameObject->objectName << " on top of " << this->objectName << std::endl;

				PayloadAsGameObject->SetParent(this);
			}
			ImGui::EndDragDropTarget();
		}








		
		if (isOpen)
		{

			for (GameObject* child : children)
			{

				child->DrawChildGUI();

			}
			ImGui::TreePop();

		}
		
	 }

};
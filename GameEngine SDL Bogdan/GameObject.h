#pragma once
#include "SDL_render.h"
#include "Vector2D.h"
#include "bitmap.h"
#include "EventManager.h"
#include "imgui-master/imgui.h"
#include "imgui-master/backends/imgui_impl_sdl.h"
#include "imgui_sdl-master/imgui_sdl.h"
#include "imgui-master/imgui_internal.h"
#include "I_GUI.h"
#include <iostream>
#include "Physics.h"


struct Transform 
{
public :

	float w, h, x, y, z;
	/**
*  Reference to the position on the X axis 
*/
	float* getXAddr()
	{
		return &x;
	}
	/**
*  Reference to the position on the Y axis
*/
	float* getYAddr()
	{
		return &y;
	}
	/**
*  Default constructor for the Transform structure
*/
	Transform() {
		this->w = 100;
		this->h = 100;
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	/**
*  Constructor that takes the desired width,height and position on the X,Y,Z
*/
	Transform(float w, float h, float x, float y, float z)
	{
		this->w = w;
		this->h = h;
		this->x = x;
		this->y = y;
		this->z = z;

		
	}

};

/**
*  Game Object Class
*/
class GameObject: public IEventHandler, public I_GUI
{
	
	

private:
	/**
*  SDL renderer variable representing the renderer used by the Game Object
*/
	SDL_Renderer* m_Renderer;
	

protected:
	/**
*  ImGuiIO variable which will be passed to all inheriting classes
*/
	ImGuiIO* io;
	
public:
	/**
*  Physics collider of the Game Object
*/
	Physics* collider = new Physics(this);
	/**
*  Reference to the image used by the Game Object
*/
	Bitmap* m_bitmap;
	/**
*  Transform of the Game Object
*/
	Transform* transform;
	/**
*  Name of the Game Object
*/
	std::string objectName;

	GameObject(std::string _objectName,SDL_Renderer* renderer,Bitmap* bitmap,ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z = 0);

	GameObject(std::string _objectName, SDL_Renderer* renderer,  ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z = 0);
	
	GameObject();

	~GameObject();
	
	

	//Hierarchy
	/**
*  Reference to the parent of the Game Object
*/
	GameObject* parent = nullptr;
	/**
*  Vector containing the children of the Game Object
*/
	std::vector <GameObject*> children;

	/**
*  Remove a specific Game Object from the children vector
*/
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

	/**
*  Set the parent of the Game Object
*/
	void SetParent(GameObject* obj) 
	{ 
		RemoveChild(this);

		
		this->parent = obj;
		obj->children.push_back(this);
	}
	/**
*  Add a Game Object to the children vector
*/
	void AddChild(GameObject* obj) 
	{ 
		RemoveChild(obj);


		children.push_back(obj); 
		obj->parent = this;
		
	};

	
	/**
*  Return a refernce to the Game Object Transform
*/
	Transform* getTransform() 
	{ 
		return transform; 
	}
	/**
*  Replace the current transform of the Game Object with the desired new one
*/
	void ChangeTransform(Transform* newTransform) 
{ 
		transform = newTransform; 
	}
	/**
*  Return the position of the Game Object
*/
	Vector2D getPosition() 
	{
		return Vector2D(transform->x, transform->y);
	}
	/**
*  Set the position of the Game Object
*/
	void setPosition(Vector2D newPos);
	/**
*  Set the Y position of the Game Object
*/
	void setY(float y);
	/**
*  Set the X position of the Game Object
*/
	void setX(float x);
	
	/**
*  Draw the Game Object and its children
*/
	void Draw();
	/**
*  Update the AI Logic
*/
	virtual void LogicUpdate();

	/**
* Triggers upon a specific event being fired
*/
	void OnEvent(Event* event)
	{
		this->transform->h = 0;
		this->transform->w = 0;
		this->transform->x = 0;
		this->transform->y = 0;
		this->transform->z = 0;

	}

	/**
* Draws the Game Object and Updates it's logic
*/
	virtual void Update()
	{
		Draw();
		LogicUpdate();

	}

	/**
* Checks if Game Object is being clicked on
*/
	bool isClickingOn()
	{
		if (!ImGui::GetIO().WantCaptureMouse)
		{

			SDL_Rect rect;
			rect.x = transform->x;
			rect.y = transform->y;
			rect.h = transform->h;
			rect.w = transform->w;

			SDL_Point point;
			point.x = io->MousePos.x;
			point.y = io->MousePos.y;


			return (SDL_PointInRect(&point, &rect) && io->MouseClicked[0]);
		}
		else
			return false;
	}
	/**
* Draw the GUI with the information of the Game Object
*/
	 void DrawGUI() override
	{
		 
			 ImVec2 windowSize = ImVec2(200, 100);
			 ImGui::SetNextWindowSize(windowSize, 0);

			 ImGui::Begin(objectName.c_str());

			 ImGui::InputFloat("X", transform->getXAddr(), 0.1f, 1.0f, "%.3f");

			 ImGui::InputFloat("Y", transform->getYAddr(), 0.1f, 1.0f, "%.3f");

			 ImGui::End();
		 
		 
	}
	 /**
 * Changes the position of the Game Object to that of the mouse while left click is being held on the object
 */
	 void MouseHeld(ImGuiIO& io) override
	 {
		 if (!ImGui::GetIO().WantCaptureMouse)
		 {
			 if (I_GUI::ObjectTargeted == this)
			 {
				 transform->x += io.MouseDelta.x;
				 transform->y += io.MouseDelta.y;

			 }
		 }
	 }

	 /**
* Add the Game Object's children to the Game Object hierarchy
*/
	 void DrawChildGUI()
	 {
		 
			 ImGuiTreeNodeFlags nodeFlags = ImGuiTreeNodeFlags_FramePadding | ImGuiTreeNodeFlags_DefaultOpen;
			 bool isOpen = ImGui::TreeNodeEx(this->objectName.c_str(), nodeFlags);
	    
			 if (ImGui::IsItemClicked())
			 {
				 I_GUI::EditorToShow = this;
				 std::cout << "selected object is: " << static_cast<GameObject*>(I_GUI::EditorToShow)->objectName << std::endl;
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
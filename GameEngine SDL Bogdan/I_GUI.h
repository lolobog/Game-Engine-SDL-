#pragma once
#include "imgui-master/imgui.h"



class I_GUI
{

public:

	/**
* Draw the GUI of the owner
*/
	virtual void DrawGUI() = 0;

	/**
* Reference to the editor
*/
	static I_GUI* EditorToShow;

	/**
* Reference to the object that has been targeted
*/
	static I_GUI* ObjectTargeted;

	
	

	
	/**
* Check if the mouse is clicking on the target
*/
	virtual bool isClickingOn() = 0 {};

	/**
* Checks if the mouse is down on the target
*/
	virtual void MouseDown(ImGuiIO& io)
	{
		if(isClickingOn())
		{ 
			EditorToShow = this;
			ObjectTargeted = this;
		}
	}
	/**
* Check if the mouse is being held
*/
	virtual void MouseHeld(ImGuiIO& io)
	{
		if (EditorToShow == this)
		{
			
		}

	}
	/**
* Checks if the mouse click has been released
*/
	virtual void MouseUp(ImGuiIO& io)
	{
		if(!io.MouseDown[0])
			ObjectTargeted = nullptr;
	}

	/**
* Update the GUI
*/
	void UpdateGUI(ImGuiIO& io)
	{
		MouseDown(io);
		MouseHeld(io);
		MouseUp(io);
	};



};

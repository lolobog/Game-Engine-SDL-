#pragma once
#include "imgui-master/imgui.h"



class I_GUI
{

public:

	virtual void DrawGUI() = 0;

	static I_GUI* EditorToShow;

	static I_GUI* ObjectTargeted;



	

	virtual bool isClickingOn() = 0 {};

	virtual void MouseDown(ImGuiIO& io)
	{
		if(isClickingOn())
		{ 
			EditorToShow = this;
			ObjectTargeted = this;
		}
	}

	virtual void MouseHeld(ImGuiIO& io)
	{
		if (EditorToShow == this)
		{
			
		}

	}

	virtual void MouseUp(ImGuiIO& io)
	{
		if(!io.MouseDown[0])
			ObjectTargeted = nullptr;
	}


	void UpdateGUI(ImGuiIO& io)
	{
		MouseDown(io);
		MouseHeld(io);
		MouseUp(io);
	};



};
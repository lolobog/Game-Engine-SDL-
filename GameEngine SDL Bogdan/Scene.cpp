#include "Scene.h"

Scene::Scene(SDL_Renderer* renderer, ImGuiIO& _io)
{
	io = &_io;
	m_rednerere = renderer;

	//0 background
	//1 level
	//2 player / enemy
	//3 hud

	//LayerObjects.resize(4);
	
	

	Root=	new GameObject("Root", renderer, _io, 0, 0, 0, 0, 0);
	SceneObjects.push_back(Root);
	
	SceneObjects.push_back(new GameObject("Monster1", renderer, new Bitmap(renderer, "Assets/monstertrans.bmp", true), _io, 30, 30, 200, 100, 10));
	Root->AddChild(SceneObjects[1]);

	SceneObjects.push_back(new GameObject("Monster2", renderer, new Bitmap(renderer, "Assets/monstertrans.bmp", true), _io, 50, 50, 200, 100, 10));
	Root->AddChild(SceneObjects[2]);

	Player = new Hero(renderer, new Bitmap(renderer, "Assets/hero.bmp", true), _io, 100, 100, 100, 200, 100);
	Root->AddChild(Player);
	SceneObjects.push_back(Player);

	Player->AddChild(SceneObjects[1]);
}

void Scene::Update()
{
	
	
		for (auto object : SceneObjects)
		{
			if (object->objectName != "Root")
			{
				object->UpdateGUI(*io);
				object->Draw();
			}
			
			
		}
	

	if (I_GUI::EditorToShow)
		I_GUI::EditorToShow->DrawGUI();
	
	
}

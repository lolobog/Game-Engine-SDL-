#include "Scene.h"

Scene::Scene(SDL_Renderer* renderer, ImGuiIO& _io)
{
	io = &_io;
	m_rednerere = renderer;

	//0 background
	//1 level
	//2 player / enemy
	//3 hud

	LayerObjects.resize(4);
	
	LayerObjects[playerEnemy].push_back(new GameObject("Monster",renderer, new Bitmap(renderer, "Assets/monstertrans.bmp", true), _io, 30, 30, 200, 100, 10));

	LayerObjects[playerEnemy].push_back(new GameObject("Monster", renderer, new Bitmap(renderer, "Assets/monstertrans.bmp", true), _io, 50, 50, 200, 100, 10));

	Player = new Hero(renderer,new Bitmap(renderer, "Assets/hero.bmp", true),_io,100,100,100,200,100);

	

	LayerObjects[playerEnemy].push_back(Player);
}

void Scene::Update()
{
	
	for (auto Layer : LayerObjects)
	{	
		for (auto object : Layer)
		{
			
			object->UpdateGUI(*io);
			object->Draw();
			
			
		}
	}

	if (I_GUI::EditorToShow)
		I_GUI::EditorToShow->DrawGUI();
	
	
}

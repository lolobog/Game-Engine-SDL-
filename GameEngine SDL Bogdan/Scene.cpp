#include "Scene.h"

Scene::Scene(SDL_Renderer* renderer, ImGuiIO& io)
{
	m_rednerere = renderer;

	//0 background
	//1 level
	//2 player / enemy
	//3 hud

	LayerObjects.resize(4);
	
	LayerObjects[playerEnemy].push_back(new GameObject(renderer, new Bitmap(renderer, "Assets/monstertrans.bmp", true),io, 20, 20, 200, 100, 10));

	Player = new Hero(renderer,new Bitmap(renderer, "Assets/hero.bmp", true),io,100,100,100,200,100);

	LayerObjects[playerEnemy].push_back(Player);
}

void Scene::Update()
{
	static GameObject* selectedGO = nullptr;
	for (auto Layer : LayerObjects)
	{	
		for (auto object : Layer)
		{
			object->Draw();
			if (object->isClickingOn())
			{
				selectedGO = object;
				printf("Clicked\n");
				//object->DrawGUI();
			}

			
		}
	}

	if (selectedGO != nullptr)
	{
		selectedGO->DrawGUI();
	}
	
}

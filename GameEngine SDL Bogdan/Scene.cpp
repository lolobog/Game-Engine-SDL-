#include "Scene.h"

Scene::Scene(SDL_Renderer* renderer)
{
	m_rednerere = renderer;

	//0 background
	//1 level
	//2 player / enemy
	//3 hud

	LayerObjects.resize(4);
	
	
	
	
	
	LayerObjects[2].push_back(new GameObject(renderer, new Bitmap(renderer, "Assets/monstertrans.bmp", true), 0, 0, 10, 10, 10));



	Player = new Hero(renderer,new Bitmap(renderer, "Assets/hero.bmp", true),100,100,100,100,100);
	Player->AddChild(LayerObjects[2][0]);
	LayerObjects[2].push_back(Player);
}

void Scene::Update()
{
	for (auto Layer : LayerObjects)
	{	
		for(auto object: Layer)
			object->Draw();
	}
	
}

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
	
	SceneObjects.push_back(new GameObject("Monster1", renderer, new Bitmap(renderer, "Assets/monstertrans.bmp", true), _io, 30, 30, 200, 100, 0));
	SceneObjects[1]->SetParent(Root);
	//Root->AddChild(SceneObjects[1]);

	SceneObjects.push_back(new GameObject("Monster2", renderer, new Bitmap(renderer, "Assets/monstertrans.bmp", true), _io, 50, 50, 200, 100, 0));
	Root->AddChild(SceneObjects[2]);

	Player = new Hero(renderer, new Bitmap(renderer, "Assets/hero.bmp", true), _io, 100, 100, 100, 200, 0);
	Root->AddChild(Player);
	SceneObjects.push_back(Player);

	Key = new GameObject("Monster2", renderer, new Bitmap(renderer, "Assets/key.png", true), _io, 50, 50, 500, 500, 0);
	Root->AddChild(Key);
	SceneObjects.push_back(Key);
	Collidables.push_back(Key);

	Walls.push_back(new GameObject("Outer Left Wall", renderer, new Bitmap(renderer, "Assets/wall_vertical.png", true), _io, 40, 1000, 0, 0, 0));
	SceneObjects.push_back(Walls[0]);
	Root->AddChild(Walls[0]);

	Walls.push_back(new GameObject("Outer Top Wall", renderer, new Bitmap(renderer, "Assets/wall_horizontal.png", true), _io, 1000, 40, 0, 0, 0));
	SceneObjects.push_back(Walls[1]);
	Root->AddChild(Walls[1]);

	Walls.push_back(new GameObject("Outer Right Wall", renderer, new Bitmap(renderer, "Assets/wall_vertical.png", true), _io, 40, 1000, 920, 0, 0));
	SceneObjects.push_back(Walls[2]);
	Root->AddChild(Walls[2]);

	Walls.push_back(new GameObject("Outer Bottom Wall", renderer, new Bitmap(renderer, "Assets/wall_horizontal.png", true), _io, 1000, 40, 0, 700, 0));
	SceneObjects.push_back(Walls[3]);
	Root->AddChild(Walls[3]);


	

	//Player->AddChild(SceneObjects[1]);

	
}

void Scene::Update()
{
	


	for (auto obj : Walls)
	{
		if (Player->collider->CheckCollision(obj))
		{
			

			if (Player->collider->CheckYCollision(obj))
			{
				if((obj->transform->y - Player->transform->y)<0)
					Player->transform->y = Player->transform->y + 10;
				else
					Player->transform->y = Player->transform->y - 10;
				//cout << "Y collision\n";
			}

			if (Player->collider->CheckXCollision(obj))
			{
				if ((obj->transform->x - Player->transform->x) <= 0)
				{
					Player->transform->x = Player->transform->x + 10;
					Player->transform->y = Player->transform->y - 10;
				}
				else
				{
					Player->transform->x = Player->transform->x - 10;
					Player->transform->y = Player->transform->y - 10;
				}
				//cout << "X collision\n";
			}
			

		}
	}
	if (Player->keyCollected == false)
	{
		if (Player->collider->CheckCollision(Key))
		{
			
			Player->keyCollected = true;
			cout << "Key Collected\n";
		}
	}
	
		

	
	
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

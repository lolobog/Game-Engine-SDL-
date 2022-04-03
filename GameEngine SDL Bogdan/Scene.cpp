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
	

	SceneObjects.push_back(new Creature(renderer, new Bitmap(renderer, "Assets/goomba.png", true), _io, 60, 60, 833, 157, 0));
	SceneObjects[1]->SetParent(Root);
	CreatureAIs.push_back((Creature*)SceneObjects[1]);
	CreatureAIs[0]->target1 = 50; CreatureAIs[0]->target2 = 370;
	Collidables.push_back(CreatureAIs[0]);

	SceneObjects.push_back(new Creature(renderer, new Bitmap(renderer, "Assets/goomba.png", true), _io, 60, 60, 573, 350, 0));
	SceneObjects[2]->SetParent(Root);
	CreatureAIs.push_back((Creature*)SceneObjects[2]);
	CreatureAIs[1]->target1 = 500; CreatureAIs[1]->target2 = 180;
	Collidables.push_back(CreatureAIs[1]);

	SceneObjects.push_back(new Creature(renderer, new Bitmap(renderer, "Assets/goomba.png", true), _io, 60, 60, 373, 350, 0));
	SceneObjects[3]->SetParent(Root);
	CreatureAIs.push_back((Creature*)SceneObjects[3]);
	CreatureAIs[2]->target1 = 180; CreatureAIs[2]->target2 = 500;
	Collidables.push_back(CreatureAIs[2]);


	Player = new Hero(renderer, new Bitmap(renderer, "Assets/hero.bmp", true), _io, 80, 80, 40, 40, 0);
	Root->AddChild(Player);
	SceneObjects.push_back(Player);

	Key = new GameObject("Key", renderer, new Bitmap(renderer, "Assets/key.png", true), _io, 70, 70, 862, 505, 0);
	Root->AddChild(Key);
	SceneObjects.push_back(Key);
	Collidables.push_back(Key);

	Door = new GameObject("Door", renderer, new Bitmap(renderer, "Assets/door.png", true), _io, 100, 100, 843, 610, 0);
	Root->AddChild(Door);
	SceneObjects.push_back(Door);
	Collidables.push_back(Door);

	EventManager->AddListener(Event_Object_Collected, Player);
	EventManager->AddListener(Event_Object_Collected, Key);
	


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

	Walls.push_back(new GameObject("Inner Wall Bottom", renderer, new Bitmap(renderer, "Assets/wall_horizontal.png", true), _io, 1000, 40, 200, 575, 0));
	SceneObjects.push_back(Walls[4]);
	Root->AddChild(Walls[4]);

	Walls.push_back(new GameObject("Inner Wall Top", renderer, new Bitmap(renderer, "Assets/wall_horizontal.png", true), _io, 700, 40, 40, 120, 0));
	SceneObjects.push_back(Walls[5]);
	Root->AddChild(Walls[5]);

	Walls.push_back(new GameObject("Inner Center Wall", renderer, new Bitmap(renderer, "Assets/wall_vertical.png", true), _io, 40, 300, 505, 276, 0));
	SceneObjects.push_back(Walls[6]);
	Root->AddChild(Walls[6]);

	Walls.push_back(new GameObject("Inner Right Top", renderer, new Bitmap(renderer, "Assets/wall_horizontal.png", true), _io, 400, 40, 665, 450, 0));
	SceneObjects.push_back(Walls[7]);
	Root->AddChild(Walls[7]);



	

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

	for (auto obj : Collidables)
	{


		if (obj->objectName == "Key")
		{
			if (Player->keyCollected == false)
			{
				if (Player->collider->CheckCollision(obj))
				{
					cout << "Collided with key\n";
					EventManager->FireEvent(Event_Object_Collected, keyCollected);
				}
			}
		}

		if (obj->objectName == "Door")
		{
			if (Player->collider->CheckCollision(obj))
			{
				if (Player->keyCollected == true)
				{
					cout << "Collided with door\n";
					
				}
			}
		}
		if (obj->objectName == "Creature")
		{
			if (Player->collider->CheckCollision(obj))
			{
				
					cout << "Collided with enemy\n";
					Player->transform->x = 40;
					Player->transform->y = 40;
			}
		}
	}
	
		

	
	
		for (auto object : SceneObjects)
		{
			if (object->objectName != "Root")
			{
				object->UpdateGUI(*io);
				object->Update();
			}
			
			
		}
	

	if (I_GUI::EditorToShow)
		I_GUI::EditorToShow->DrawGUI();
	
	
}

#pragma once
#include "GameObject.h"
#include <vector>

using namespace std;

class Node
{
	GameObject* parent;
	GameObject* obj;
	int z;

	Node(int z,GameObject* obj,GameObject* parent): z(z), obj(obj), parent(parent){}
};



class Scene
{
public:
	vector <GameObject> SceneObjects;

	void Load();
	void Unload();
};

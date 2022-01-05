#pragma once
#include "GameObject.h"
#include "hero.h"
#include <vector>

using namespace std;



class Scene
{
private:
		SDL_Renderer* m_rednerere;
public:
	//vector <GameObject> SceneObjects;
	vector <vector <GameObject*>> LayerObjects;
	Hero* Player;
	

	Scene(SDL_Renderer *renderer);

	


	void Update();
	
};

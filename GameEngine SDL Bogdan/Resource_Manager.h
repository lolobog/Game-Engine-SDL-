#pragma once
#include "bitmap.h"
#include <map>

struct BitmapData
{
public:
	SDL_Texture* tex;
	SDL_Surface* surf;
};

class ResourceManager
{
private:
	 
public:

	static ResourceManager* Manager;
	std::map<std::string, BitmapData*> mTexture;
	static ResourceManager* Instance()
	{
		static ResourceManager* instance;

		if (instance == NULL)
			instance = new ResourceManager();

		return instance;
	}

	void Release();

	 BitmapData* Load(const std::string fileName, bool useTransparancy, SDL_Renderer* renderer);


	ResourceManager();
	~ResourceManager();




};

#pragma once
#include "bitmap.h"
#include <map>
#include "../SDL2_image-2.0.5/include/SDL_image.h"

/**
* Structure that holds pointers to a texture and surface 
*/
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

	/**
* Map containing all the textures and surfaces
*/
	std::map<std::string, BitmapData*> mTexture;
	/**
* Create an instance of the class which is accessible anywhere in the project through the function
*/
	static ResourceManager* Instance()
	{
		static ResourceManager* instance;

		if (instance == NULL)
			instance = new ResourceManager();

		return instance;
	}
	/**
* Deletes instance and clears pointers
*/
	void Release();

	/**
* Load the image into the resource manager
*/
	 BitmapData* Load(const std::string fileName, bool useTransparancy, SDL_Renderer* renderer);


	ResourceManager();
	~ResourceManager();




};

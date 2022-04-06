#pragma once

#include <string>
#include "SDL.h"
#include "SDL_render.h"
#include "Resource_Manager.h"


struct SDL_Surface;

struct SDL_Texture;

struct SDL_Renderer;

class Bitmap
{
private:
	/**
* Surface of the image
*/
	SDL_Texture* m_pbitmapTexture;
	/**
* Texture of the image
*/
	SDL_Surface* m_pbitmapSurface;
	/**
* Renderer of the image
*/
	SDL_Renderer* m_pRenderer;
	/**
* String variable representing the file path of the image
*/
	std::string  FilePath;
	

public:
	/**
* Class constructor requiring a renderer, the file path of the image and the transparency
*/
	Bitmap(SDL_Renderer* renderer, std::string fileName, bool useTransparency=false );
	/**
* Default class constructor for Bitmap
*/
	Bitmap();
	/**
* Default class destructor for Bitmap
*/
	~Bitmap();
	
	
	/**
* Returns the name of the loaded image
*/
	std::string GetFileName()
	{
		std::string base_filename = FilePath.substr(FilePath.find_last_of("/\\") + 1);
		std::string::size_type const p(base_filename.find_last_of('.'));
		std::string file_without_extension = base_filename.substr(0, p);

		return file_without_extension;
	}
	/**
* Returns the file path for the image
*/
	std::string GetFilePath() { return FilePath; }
	/**
* Returns a pointer to the texture variable of the image
*/
	SDL_Texture* GetTexture() { return m_pbitmapTexture; }
	/**
* Returns a pointer to the surface variable of the image
*/
	SDL_Surface* GetSurface() { return m_pbitmapSurface; }
	/**
* Returns a pointer to the renderer variable of the image
*/
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
};



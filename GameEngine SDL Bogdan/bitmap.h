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
	SDL_Texture* m_pbitmapTexture;
	SDL_Surface* m_pbitmapSurface;
	SDL_Renderer* m_pRenderer;
	std::string  FilePath;
	

public:
	Bitmap(SDL_Renderer* renderer, std::string fileName, bool useTransparency=false );
	Bitmap();
	void draw();
	~Bitmap();


	 Bitmap* Instance();
	
	
	std::string GetFileName()
	{
		std::string base_filename = FilePath.substr(FilePath.find_last_of("/\\") + 1);
		std::string::size_type const p(base_filename.find_last_of('.'));
		std::string file_without_extension = base_filename.substr(0, p);

		return file_without_extension;
	}
	std::string GetFilePath() { return FilePath; }
	SDL_Texture* GetTexture() { return m_pbitmapTexture; }
	SDL_Surface* GetSurface() { return m_pbitmapSurface; }
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
};



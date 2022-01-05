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

	

public:
	Bitmap(SDL_Renderer* renderer, std::string fileName, bool useTransparency=false );
	Bitmap();
	void draw();
	~Bitmap();


	 Bitmap* Instance();
	

	

	SDL_Texture* GetTexture() { return m_pbitmapTexture; }
	SDL_Surface* GetSurface() { return m_pbitmapSurface; }
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
};



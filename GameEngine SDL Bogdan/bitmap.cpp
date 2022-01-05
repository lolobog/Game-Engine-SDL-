#include <string>
#include "bitmap.h"


#include "SDL.h"
#include "SDL_render.h"

using namespace std;


Bitmap::Bitmap()
{

}



Bitmap::Bitmap(SDL_Renderer* renderer, std::string fileName, bool useTransparency )
{
	BitmapData* data = ResourceManager::Instance()->Load(fileName, useTransparency, renderer);

	m_pbitmapTexture=data->tex;
	m_pbitmapSurface = data->surf;
	m_pRenderer = renderer;
	
};



Bitmap* Bitmap::Instance()
{
	return nullptr;
}




Bitmap::~Bitmap()
{
	if (m_pbitmapTexture)
		SDL_DestroyTexture(m_pbitmapTexture);

	if (m_pbitmapSurface)
		SDL_FreeSurface(m_pbitmapSurface);
}
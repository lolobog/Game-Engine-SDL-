#include "Resource_Manager.h"

ResourceManager* instance = NULL;



void ResourceManager::Release()
{
	delete instance;
	instance = NULL;
}

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
	for (auto value : mTexture)
	{
		delete value.second;
		value.second = nullptr;
	}
}

BitmapData* ResourceManager::Load(const std::string fileName, bool useTransparancy, SDL_Renderer* renderer)
{
	


		SDL_Renderer* m_pRenderer = renderer;

		//SDL_Surface* m_pbitmapSurface = SDL_LoadBMP(fileName.c_str());
		SDL_Surface* m_pbitmapSurface = IMG_Load(fileName.c_str());

		SDL_Texture* m_pbitmapTexture=nullptr;

		

		auto searchresult = mTexture.find(fileName);
		if (searchresult != mTexture.end())
		{
			return mTexture[fileName];
		}
		else
		{
			
			if (!m_pbitmapSurface)
			{
				printf("SURFACE for bitmap '%s' not loaded! \n ");
				printf("%s\n", SDL_GetError());
				return 0;
			}
			else
			{
				if (useTransparancy)
				{
					Uint32 colourKey = SDL_MapRGB(m_pbitmapSurface->format, 255, 0, 255);
					SDL_SetColorKey(m_pbitmapSurface, SDL_TRUE, colourKey);
				}

				m_pbitmapTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pbitmapSurface);
				if (!m_pbitmapTexture)
				{
					printf("Texture for bitmap '%s' not loaded \n", fileName.c_str());
					printf("%s\n", SDL_GetError());
				}

				BitmapData*  b= new BitmapData();
				b->tex = m_pbitmapTexture;
				b->surf = m_pbitmapSurface;
				mTexture[fileName] = b;
			}
		}
	





	return mTexture[fileName];
}




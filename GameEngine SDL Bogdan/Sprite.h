#pragma once
#include "bitmap.h"

class Sprite : Bitmap
{
public:
	Sprite(SDL_Renderer _renderer, std::string fileName);
	~Sprite();

private:
	Bitmap* bit;

};
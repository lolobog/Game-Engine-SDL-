#include "hero.h"
Hero::Hero(SDL_Renderer* renderer, Bitmap* bitmap, float _w, float _h, float _x, float _y, float _z)
{
	
	m_bitmap = bitmap;
	transform = new Transform(_w, _h, _x, _y, _z);

	
};

	


Hero::~Hero() {}
void Hero::OnEvent(Event& event)
{

}
void Hero::InputUpdate(Input input)
{

}
;




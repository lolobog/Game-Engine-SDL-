#include "hero.h"
Hero::Hero(SDL_Renderer* renderer, Bitmap* bitmap, ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z)
{
	io =& _io;
	m_bitmap = bitmap;
	transform = new Transform(_w, _h, _x, _y, _z);
	objectName = "Hero";
	
};

	


Hero::~Hero() {}
void Hero::OnEvent(Event& event)
{

}
void Hero::InputUpdate(Input input)
{

}
;




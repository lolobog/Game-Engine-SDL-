#include "creature.h"

Creature::Creature(SDL_Renderer* renderer, Bitmap* bitmap, ImGuiIO& _io, float _w, float _h, float _x, float _y, float _z)
{
	io = &_io;
	m_bitmap = bitmap;
	transform = new Transform(_w, _h, _x, _y, _z);
	objectName = "Creature";
}

Creature::~Creature()
{
}

void Creature::LogicUpdate()
{
	MoveBetweenPoints(target1,target2);
}

void Creature::MoveBetweenPoints(float y1, float y2)
{
	if ( pointReached==false)
	{
		if(transform->y > y1)
			transform->y = transform->y - 1;
		else
			if(transform->y < y1)
				transform->y = transform->y + 1;
			else
				if (transform->y == y1)
					pointReached = true;
	}
	else
	{
		if (transform->y > y2)
			transform->y = transform->y - 1;
		else
			if (transform->y < y2)
				transform->y = transform->y + 1;
			else
				if (transform->y == y2)
					pointReached = false;
	}
}



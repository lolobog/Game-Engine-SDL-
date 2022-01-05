#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer, Bitmap* bitmap, float _w, float _h, float _x, float _y, float _z )
{
	m_Renderer = renderer;
	m_bitmap = bitmap;

	transform = new Transform(_w, _h, _x, _y, _z);

}


GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::OnEvent(Event& event)
{
	switch (event.type)
	{
	case Event_Object_Collected:
		break;
	default:
		break;
	}
}

void GameObject::setPosition(Vector2D newPos)
{
	transform->position = newPos;
}

void GameObject::setY(float y)
{
	 transform->position.y = y; 
	 transform->y = y;
}

void GameObject::setX(float x)
{
	transform->position.x = x;
	transform->x = x;
}

void GameObject::Draw()
{
	
	
		if (m_bitmap->GetTexture())
		{
			SDL_Rect destRect = { transform->x,transform->y,m_bitmap->GetSurface()->w,m_bitmap->GetSurface()->h };
			SDL_RenderCopy(m_bitmap->GetRenderer(), m_bitmap->GetTexture(), NULL, &destRect);
		}
	
}



void GameObject::LogicUpdate()
{
}

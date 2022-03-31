#include "Physics.h"
#include "GameObject.h"

Physics::Physics(GameObject* owner)
{
    obj = owner;
}

Physics::~Physics()
{
}

bool Physics::CheckCollision(GameObject* obj2)
{
    float right1, right2;
    float left1, left2;
    float top1, top2;
    float bottom1, bottom2;

    int rectangle1_X = obj->transform->x ;
    int rectangle1_Y = obj->transform->y;

    int rectangle2_X = obj2->transform->x  ;
    int rectangle2_Y = obj2->transform->y  ;


    //First rectangle
    right1 = rectangle1_X + obj->transform->w;
    left1 = rectangle1_X;
    top1 = rectangle1_Y;
    bottom1 = rectangle1_Y + obj->transform->h;

    //Second rectangle
    right2 = rectangle2_X + obj2->transform->w;
    left2 = rectangle2_X;
    top2 = rectangle2_Y;
    bottom2 = rectangle2_Y + obj2->transform->h;

    if (bottom1 <= top2)
    {
        return false;
    }

    if (top1 >= bottom2)
    {
        return false;
    }

    if (right1 <= left2)
    {
        return false;
    }

    if (left1 >= right2)
    {
        return false;
    }

    return true;
}

bool Physics::CheckXCollision(GameObject* obj2)
{
 
    float top1, top2;
    float bottom1, bottom2;

    top1 = obj->transform->y;
    bottom1 = obj->transform->y + obj->transform->h;

    top2 = obj2->transform->y;
    bottom2 = obj2->transform->y + obj2->transform->h;


    if (bottom1 <= top2)
    {
        return false;
    }

    if (top1 >= bottom2)
    {
        return false;
    }

    return true;

}

bool Physics::CheckYCollision(GameObject* obj2)
{
    float right1, right2;
    float left1, left2;
  
    right1 = obj->transform->x + obj->transform->w;
    left1 = obj->transform->x;
   
    right2 = obj2->transform->x + obj2->transform->w;
    left2 = obj2->transform->x;


    if (right1 <= left2)
    {
        return false;
    }

    if (left1 >= right2)
    {
        return false;
    }
}

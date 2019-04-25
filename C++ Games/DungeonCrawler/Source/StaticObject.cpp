#include "StaticObject.h"



StaticObject::StaticObject():GameObject(), Collidable()
{
}

void StaticObject::render(float shift)
{
	GameObject::render(shift);
	if (image != NULL)
		al_draw_bitmap(image, x - shift, y, 0);
}

void StaticObject::collided(int objectID)
{
	//CollidableObject::collided(objectID);
}
float StaticObject::GetPosX()//z collidable
{
	return x;
}
float StaticObject::GetPosY()//z collidable
{
	return y;
}
float StaticObject::getBoundX()
{
	return boundX;
}
float StaticObject::getBoundY()
{
	return boundY;
}
int StaticObject::IDnum()//z collidable
{
	return getID();
}

void StaticObject::ProcessCollision(Collidable* otherObject)//z collidable
{


}

StaticObject::~StaticObject()
{
}

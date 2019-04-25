#pragma once
#include "GameObject.h"
#include "Collidable.h"
class StaticObject : public GameObject, public Collidable
{
public:
	StaticObject();
	void render(float shift);
	void collided(int objectID);
	float GetPosX();//z collidable
	float GetPosY();//z collidable
	float getBoundX();
	float getBoundY();
	int IDnum();//z collidable
	void kill() 
	{ 
		setID(Enums::IDS::NTH);
		image = NULL;
	}
	void ProcessCollision(Collidable* otherObject);//z collidable
	~StaticObject();
};


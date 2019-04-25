#pragma once
#include "MovingObject.h"
#include "Collidable.h"
#include "Physics.h"
#include "Enums.h"


class LivingObject : public MovingObject, public Collidable, public Physics
{
public:
	LivingObject();

	float getBoundX() { return boundX; }
	float getBoundY() { return boundY; }
	
	float GetPosX() { return x; }
	float GetPosY() { return y; }

	virtual void update();

	void kill() { setID(Enums::IDS::NTH); image = NULL; };
	//resetowanie czy jest na drabinie i grawitacji

	int getHP()
	{
		return HP;
	}
	void setHP(int hp)
	{
		HP = hp;
	}
	void gravity()
	{
		if (gravityOn)
			y += 10;
	}

	void init(float x, float y, float velX, float velY, std::string imageName, Enums::IDS id,int _maxFrame);
	void render(float shift);


	void resetXDir();
	void resetYDir();
	int getDirX()
	{
		return dirX;
	}
	int getDirY()
	{
		return dirY;
	}

	bool getFacing()
	{
		return facingRight;
	}
	
	int IDnum() { return getID(); }//z collidable
	
	virtual void ProcessCollision(Collidable* otherObject)= 0 ; // z collidable

	~LivingObject();
};


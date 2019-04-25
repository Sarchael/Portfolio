#pragma once
#include "LivingObject.h"
#include "ScoreCounter.h"
#include "ShowStats.h"

class PlayableObject : public LivingObject
{
private:
	float shift = 0;
	int additional_damage = 0;// do zwiekszania ataku poprzez powerupy
	int ad_cooldown = 0;
	ScoreCounter * SCounter;

public:
	PlayableObject();
	bool onLdr = false;
	bool ended = false;

	void jump();//trzeba dopracowaæ

	int getAdditionalDamage() { return additional_damage; }
	void setAdditionalDamage(int dmg) { additional_damage = dmg; }

	void resetStuff()
	{
		onLdr = false;
		gravityOn = true;
		touchedGround = false;
	}

	virtual void moveLeft();
	virtual void moveRight();
	virtual void moveDown();
	virtual void moveUp();

	void jumpReset();

	void update();

	float getShift() { return shift; }
	void setShift(float s) { shift = s; }
	int getHP()
	{
		return HP;
	}
	void gravity()
	{
		if (gravityOn)
			y += 10;
	}

	void jumpUpdate();

	ScoreCounter * getScoreCounter();

	void ProcessCollision(Collidable* otherObject); // z collidable
	int key[Enums::KEYS::COUNT];

	~PlayableObject();
};


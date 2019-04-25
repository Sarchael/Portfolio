#pragma once
#include "ScoreCounter.h"
#include "Delegate.h"
#include "LivingObject.h"

class EnemyObject;
class Delegate;
class ScoreCounter;
class EnemyObject : public LivingObject
{
protected:
	int cooldown = 0;
	Delegate * deleg;
public:
	EnemyObject();
	virtual void runToPlayer(float x, float y, float bnd_y) = 0;
	void initv2(ScoreCounter * scounter, float x, float y, float velX, float velY, std::string imageName, Enums::IDS id, int _maxFrame);
	void ProcessCollision(Collidable* otherObject);
	virtual void getDamage(int dmg)=0;
	virtual int attack() = 0;
	virtual void update();
	void jumpUpdate() {}
	void jumpReset() {}
	~EnemyObject();
};


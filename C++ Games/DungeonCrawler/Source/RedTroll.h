#pragma once
#include "EnemyObject.h"
#include "Delegate.h"
class Delegate;
class RedTroll :
	public EnemyObject
{
public:
	RedTroll();
	virtual void runToPlayer(float x, float y, float bnd_y);
	virtual void getDamage(int dmg);
	virtual int attack();
	void restore();
	~RedTroll();
};


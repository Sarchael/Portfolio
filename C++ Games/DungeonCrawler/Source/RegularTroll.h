#pragma once
#include "EnemyObject.h"
#include "Delegate.h"
class Delegate;
class RegularTroll :
	public EnemyObject
{
public:
	RegularTroll();
	bool reloaded = false;
	virtual void runToPlayer(float x, float y, float bnd_y);
	virtual void getDamage(int dmg);
	virtual int attack();
	void loadHP();
	~RegularTroll();
};


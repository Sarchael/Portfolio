#pragma once
#include "EnemyObject.h"
#include "PlayableObject.h"
#include "Delegate.h"
class Delegate;
class OrangeTroll :
	public EnemyObject
{
public:
	OrangeTroll();
	virtual void runToPlayer(float x, float y, float bnd_y);
	virtual void getDamage(int dmg);
	int telepatics_damage = 5;
	int attack();
	void telepatics(PlayableObject &p);
	~OrangeTroll();
};


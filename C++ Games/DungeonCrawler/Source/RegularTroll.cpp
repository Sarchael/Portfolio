#include "RegularTroll.h"
#include <iostream>


RegularTroll::RegularTroll()
{
}

void RegularTroll::getDamage(int dmg)
{
	HP -= dmg;
}

int RegularTroll::attack()
{
	if (cooldown == 0)
	{
		cooldown = 60;
		return 3;
	}
	else
		return 0;
}

void RegularTroll::runToPlayer(float x, float y, float bnd_y)
{
	float difference = this->x - x;
	int border = 10;

	this->dirX = 0;

	if ((y > this->y + border && y < this->y + this->boundY - border) || (y + bnd_y > this->y + border && y + bnd_y < this->y + this->boundY - border))
	{
		if (difference < 400 && difference > 10) //150//30
		{
			this->moveLeft();
		}
		else if (difference > -400 && difference < -10)
		{
			this->moveRight();
		}
	}
}

void RegularTroll::loadHP()
{
	if (HP < 100)
	{
		int chance = rand() % 100;
		if (chance == 0 && reloaded == false)
		{
			HP = 100;
			reloaded = true;
		}	
	}
}

RegularTroll::~RegularTroll()
{
}

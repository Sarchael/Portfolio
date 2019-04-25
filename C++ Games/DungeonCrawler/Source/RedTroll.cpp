#include "RedTroll.h"



RedTroll::RedTroll()
{
}

void RedTroll::getDamage(int dmg)
{
	HP -= dmg/2;
}

int RedTroll::attack()
{
	if (cooldown == 0)
	{
		cooldown = 60;
		return 2;
	}
	else
		return 0;
}

void RedTroll::runToPlayer(float x, float y, float bnd_y)
{
	float difference = this->x - x;
	int border = 10;

	this->dirX = 0;

	if ((y > this->y + border && y < this->y + this->boundY - border) || (y + bnd_y > this->y + border && y + bnd_y < this->y + this->boundY - border))
	{
		if (difference < 500 && difference > 10) //150//30
		{
			this->moveLeft();
		}
		else if (difference > -500 && difference < -10)
		{
			this->moveRight();
		}
	}
}

void RedTroll::restore()
{
	int chance = rand() % 10;
	if (chance == 0 && HP < 100)
		this->HP += 1;
}


RedTroll::~RedTroll()
{
}

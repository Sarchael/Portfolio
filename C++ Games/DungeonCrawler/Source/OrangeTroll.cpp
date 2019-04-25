#include "OrangeTroll.h"



OrangeTroll::OrangeTroll()
{
}

void OrangeTroll::getDamage(int dmg)
{
	HP -= dmg/4;
}

int OrangeTroll::attack()
{
	if (cooldown == 0)
	{
		cooldown = 60;
		return 1;
	}
	else
		return 0;
}

void OrangeTroll::runToPlayer(float x, float y, float bnd_y)
{
	float difference = this->x - x;
	int border = 10;

	this->dirX = 0;

	if ((y > this->y + border && y < this->y + this->boundY - border) || (y + bnd_y > this->y + border && y + bnd_y < this->y + this->boundY - border))
	{
		if (difference < 550 && difference > 10) //150//30
		{
			this->moveLeft();
		}
		else if (difference > -550 && difference < -10)
		{
			this->moveRight();
		}
	}
}

void OrangeTroll::telepatics(PlayableObject &p)
{
	float difference = this->x - p.getX();
	int chance = rand() % 100;

	if (((difference < 100 && difference > 10) || (difference > -100 && difference < -10)) && chance == 0)
	{
		p.setHP(p.getHP() - telepatics_damage);
	}
}


OrangeTroll::~OrangeTroll()
{
}

#include "Spell.h"
#include "EnemyObject.h"
#include <iostream>


Spell::Spell(int _x, int _y, int powerup, int dir, Enums::IDS id)
{
	setID(id);
	//active = true;
	switch (id)
	{
		case Enums::IDS::NORMAL_ATTACK:
		{
			velX = 10;
			damage = 50 + powerup;
			if (dir)
				dirX = 1;
			else
				dirX = -1;
			y = _y + 20;
			if (dirX == -1)
				x = _x + velX - 70;
			else
				x = _x - 3 * velX;
			range = 90;
			image = norm_att;
			break;
		}
		case Enums::IDS::ULTIMATE_SKILL:
		{
			velX =7;
			damage = 100 + powerup;
			dirX = 1;
			x = _x;
			y = _y;
			range = 150;
			image = ult_skill;
		}
	}
	boundY = al_get_bitmap_height(image);
	boundX = al_get_bitmap_width(image);

}
void Spell::ProcessCollision(Collidable* otherObject)
{
	float xplsr = GetPosX() + (getBoundX() / 2); // wspolrzedna x srodka playera
	float yplsr = GetPosY() + (getBoundY() / 2); // wspolrzedna y srodka playera
	float xoosr = otherObject->GetPosX() + (otherObject->getBoundX() / 2); //to samo otherObject
	float yoosr = otherObject->GetPosY() + (otherObject->getBoundY() / 2); //to samo otherObject
	float plb = getBoundX() / 2; //nowe bound playera
	float oob = otherObject->getBoundX() / 2; // nowe bound otherObject

	bool col = false;

	if (xplsr + plb > xoosr - oob &&
		xplsr - plb < xoosr + oob &&
		yplsr + plb > yoosr - oob &&
		yplsr - plb < yoosr + oob)
		col = true;
	if (col)
		if (otherObject->IDnum() == Enums::IDS::PLATFORM || otherObject->IDnum() == Enums::IDS::GHOST || otherObject->IDnum() == Enums::IDS::ENEMY)
		{
			if (IDnum() == Enums::IDS::NORMAL_ATTACK)
			{
				kill();
			}
			if (otherObject->IDnum() == Enums::IDS::ENEMY)
			{
				EnemyObject * e;
				if (e = dynamic_cast<EnemyObject*>(otherObject))
				{
					e->getDamage(damage);
					std::cout << "ZCASTOWANE!!!" << std::endl;
				}
					
			}
		}
}
void Spell::kill()
{
	setID(Enums::IDS::UNACTIVE_SPELL);
	image = NULL;
	//active = false;
}
void Spell::update()
{
	range--;
	if (range > 0)
		x += velX*dirX;
	else
		kill();
}
float Spell::GetPosX()
{
	return x;
}
float Spell::GetPosY()
{
	return y;
}
float Spell::getBoundX()
{
	return boundX;
}
float Spell::getBoundY()
{
	return boundY;
}
int Spell::IDnum()
{
	return getID();
}
void Spell::resetAnimation() {}
void Spell::updateAnimation() {}
void Spell::render(float shift)
{
	if (image != NULL)
	{
		if (IDnum() == Enums::IDS::NORMAL_ATTACK)
			al_draw_bitmap(image, x - shift, y, 0);
		else if (IDnum() == Enums::IDS::ULTIMATE_SKILL)
			al_draw_bitmap(image, x - shift, y, ALLEGRO_FLIP_HORIZONTAL);
	}
		

}
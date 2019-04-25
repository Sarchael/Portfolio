#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Includs.h"



bool Bomb::IsAlive()
{
	if (life)
		return true;
	else return false;
}

void Bomb::SetLife(int n)
{
	life = n;
}
void Bomb::SetBX(int n)
{
	x = n;
}
void Bomb::SetBY(int n)
{
	y = n;
}
int Bomb::GetBX()
{
	return x;
}
int Bomb::GetBY()
{
	return y;
}

Bomb::Bomb(Bitmaps & img)
{
	x = -1;
	y = -1;
	active = 0;
	life = 0;
	frameWidth = 70;
	frameHeight = 70;
	counter = 0;
	image = img.getABombImage();
}

bool Bomb::ActiveBomb(Player & player, Map & map) 
{
	if (life)
	{
		if (!active)
		{
			active = 1;
			x = map.WhereIAm(player.GetPX(), player.GetPY())->GetX() + 35;
			y = map.WhereIAm(player.GetPX(), player.GetPY())->GetY() + 35;
			return true;
		}
	}
	return false;
}

void Bomb::DrawBomb()
{
	if (active)
	{
		al_draw_bitmap(image, x - frameWidth / 2, y - frameHeight / 2, 0);
	}
}

void Bomb::UpdateBomb(Explosion * exp, Map & map, Bitmaps & img)
{
	if (active)
	{
		if (++counter >= 180)
		{
			counter = 0;
			image = img.getABombImage();
			map.WhereIAm(x, y)->SetExplosion(1);
			map.WhereIAm(x + 70, y)->SetExplosion(1);
			map.WhereIAm(x - 70, y)->SetExplosion(1);
			map.WhereIAm(x, y + 70)->SetExplosion(1);
			map.WhereIAm(x, y - 70)->SetExplosion(1);
			for (int i = 0; i < 3; i++)
			{
				if (!exp[i].IsAlive())
				{
					exp[i].StartExplosion(x, y);
					break;
				}
			}
		}
	}
}
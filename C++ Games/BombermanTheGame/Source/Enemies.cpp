#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Includs.h"


void Enemies::SetLife(int n)
{
	life = n;
}

int Enemies::GetLife()
{
	return life;
}
int Enemies::GetEX()
{
	return x;
}
int Enemies::GetEY()
{
	return y;
}
int Enemies::GetEbX()
{
	return boundx;
}
int Enemies::GetEbY()
{
	return boundy;
}

Enemies::Enemies(Bitmaps & img, int nr)
{
	if (nr == 1)
	{
		x = 945;
		y = 105;
		dir = DOWN;
	}
	else if (nr == 2)
	{
		x = 945;
		y = 945;
		dir = LEFT;
	}
	else if (nr == 3)
	{
		x = 105;
		y = 945;
		dir = RIGHT;
	}

	speed = 2;
	life = 1;
	boundx = 34;
	boundy = 34;

	frameWidth = 68;
	frameHeight = 68;

	image = img.getEnemyImage();
}
void Enemies::DrawEnemies()
{
	if (life == 1)
	{
		al_draw_bitmap(image, x - frameWidth / 2, y - frameWidth / 2, 0);
	}
}

void Enemies::MoveEnemies(Map & map)
{
	int a = 0;
	if (dir == UP)
	{
		x += 20;
		if (map.WhereIAm(x + boundx, y - boundy)->GetType() == GRASS && map.WhereIAm(x + boundx, y + boundy)->GetType() == GRASS)
		{
			if (rand() % 3 == 0)
			{
				x -= 18;
				dir = RIGHT;
				a = 1;
			}
			else
				x -= 20;
		}
		else
			x -= 20;
		if (!a)
		{
			x -= 20;
			if (map.WhereIAm(x - boundx, y - boundy)->GetType() == GRASS && map.WhereIAm(x - boundx, y + boundy)->GetType() == GRASS)
			{
				if (rand() % 3 == 0)
				{
					x += 18;
					dir = LEFT;
					a = 1;
				}
				else
					x += 20;
			}
			else
			{
				x += 20;
			}
		}
		if (!a)
		{
			y -= speed;
			if (map.WhereIAm(x + boundx, y - boundy)->GetType() != GRASS && map.WhereIAm(x - boundx, y - boundy)->GetType() != GRASS)
			{
				y += 2 * speed;
				dir = DOWN;
			}
		}
		a = 0;
	}
	else if (dir == DOWN)
	{
		x += 20;
		if (map.WhereIAm(x + boundx, y - boundy)->GetType() == GRASS && map.WhereIAm(x + boundx, y + boundy)->GetType() == GRASS)
		{
			if (rand() % 3 == 0)
			{
				x -= 18;
				dir = RIGHT;
				a = 1;
			}
			else
				x -= 20;
		}
		else
			x -= 20;
		if (!a)
		{
			x -= 20;
			if (map.WhereIAm(x - boundx, y - boundy)->GetType() == GRASS && map.WhereIAm(x - boundx, y + boundy)->GetType() == GRASS)
			{
				if (rand() % 3 == 0)
				{
					x += 18;
					dir = LEFT;
					a = 1;
				}
				else
					x += 20;
			}
			else
			{
				x += 20;
			}
		}
		if (!a)
		{
			y += speed;
			if (map.WhereIAm(x + boundx, y + boundy)->GetType() != GRASS && map.WhereIAm(x - boundx, y + boundy)->GetType() != GRASS)
			{
				y -= 2 * speed;
				dir = UP;
			}
		}
		a = 0;
	}
	else if (dir == RIGHT)
	{

		y -= 20;
		if (map.WhereIAm(x + boundx, y - boundy)->GetType() == GRASS && map.WhereIAm(x - boundx, y - boundy)->GetType() == GRASS)
		{
			if (rand() % 3 == 0)
			{
				y += 18;
				dir = UP;
				a = 1;
			}
			else
				y += 20;
		}
		else
			y += 20;
		if (!a)
		{
			y += 20;
			if (map.WhereIAm(x + boundx, y + boundy)->GetType() == GRASS && map.WhereIAm(x - boundx, y + boundy)->GetType() == GRASS)
			{
				if (rand() % 3 == 0)
				{
					y -= 18;
					dir = DOWN;
					a = 1;
				}
				else
					y -= 20;
			}
			else
				y -= 20;
		}
		if (!a)
		{
			x += speed;
			if (map.WhereIAm(x + boundx, y - boundy)->GetType() != GRASS && map.WhereIAm(x + boundx, y + boundy)->GetType() != GRASS)
			{
				x -= 2 * speed;
				dir = LEFT;
			}
		}
		a = 0;
	}
	else if (dir == LEFT)
	{
		y -= 20;
		if (map.WhereIAm(x + boundx, y - boundy)->GetType() == GRASS && map.WhereIAm(x - boundx, y - boundy)->GetType() == GRASS)
		{
			if (rand() % 3 == 0)
			{
				y += 18;
				dir = UP;
				a = 1;
			}
			else
				y += 20;
		}
		else
			y += 20;
		if (!a)
		{
			y += 20;
			if (map.WhereIAm(x + boundx, y + boundy)->GetType() == GRASS && map.WhereIAm(x - boundx, y + boundy)->GetType() == GRASS)
			{
				if (rand() % 3 == 0)
				{
					y -= 18;
					dir = DOWN;
					a = 1;
				}
				else
					y -= 20;
			}
			else
				y -= 20;
		}
		if (!a)
		{
			x -= speed;
			if (map.WhereIAm(x - boundx, y - boundy)->GetType() != GRASS && map.WhereIAm(x - boundx, y + boundy)->GetType() != GRASS)
			{
				x += 2 * speed;
				dir = RIGHT;
			}
		}
		a = 0;
	}
}
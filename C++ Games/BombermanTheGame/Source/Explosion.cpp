#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Includs.h"



bool Explosion::IsAlive()
{
	if (life)
		return true;
	else return false;
}

Explosion::Explosion(Bitmaps & img)
{
	life = 0;
	maxFrame = 18;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 2;
	frameWidth = 70;
	frameHeight = 70;
	animationColumns = 5;
	animationDirection = 1;

	image = img.getExplosionImage();
}

void Explosion::DrawExplosion(Map & map)
{
	if (life)
	{
		int fx = (curFrame % animationColumns) * frameWidth;
		int fy = (curFrame / animationColumns) * frameHeight;

		al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - frameWidth / 2, y - frameHeight / 2, 0);

		if (map.WhereIAm(x + 70, y)->GetType() != WALL)
			al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight,
			(x - frameWidth / 2) + 70, y - frameHeight / 2, 0);
		if (map.WhereIAm(x - 70, y)->GetType() != WALL)
			al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight,
			(x - frameWidth / 2) - 70, y - frameHeight / 2, 0);
		if (map.WhereIAm(x, y + 70)->GetType() != WALL)
			al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight,
				x - frameWidth / 2, (y - frameHeight / 2) + 70, 0);
		if (map.WhereIAm(x, y - 70)->GetType() != WALL)
			al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight,
				x - frameWidth / 2, (y - frameHeight / 2) - 70, 0);
	}
}

void Explosion::UpdateExplosion(Bomb * bomb, Map & map, Bitmaps & img)
{
	if (life)
	{
		if (++frameCount >= frameDelay)
		{
			curFrame += animationDirection;
			if (curFrame >= maxFrame)
			{
				curFrame = 0;
				life = 0;
				for (int j = 0; j < 3; j++)
				{
					if (x == bomb[j].GetBX() && y == bomb[j].GetBY())
					{
						map.WhereIAm(bomb[j].GetBX(), bomb[j].GetBY())->SetExplosion(0);
						map.WhereIAm(bomb[j].GetBX() + 70, bomb[j].GetBY())->SetExplosion(0);
						map.WhereIAm(bomb[j].GetBX() - 70, bomb[j].GetBY())->SetExplosion(0);
						map.WhereIAm(bomb[j].GetBX(), bomb[j].GetBY() + 70)->SetExplosion(0);
						map.WhereIAm(bomb[j].GetBX(), bomb[j].GetBY() - 70)->SetExplosion(0);
						if (map.WhereIAm(bomb[j].GetBX() + 70, bomb[j].GetBY())->GetType() == CHEST)
							map.WhereIAm(bomb[j].GetBX() + 70, bomb[j].GetBY())->SetType(GRASS);
						if (map.WhereIAm(bomb[j].GetBX() - 70, bomb[j].GetBY())->GetType() == CHEST)
							map.WhereIAm(bomb[j].GetBX() - 70, bomb[j].GetBY())->SetType(GRASS);
						if (map.WhereIAm(bomb[j].GetBX(), bomb[j].GetBY() + 70)->GetType() == CHEST)
							map.WhereIAm(bomb[j].GetBX(), bomb[j].GetBY() + 70)->SetType(GRASS);
						if (map.WhereIAm(bomb[j].GetBX(), bomb[j].GetBY() - 70)->GetType() == CHEST)
							map.WhereIAm(bomb[j].GetBX(), bomb[j].GetBY() - 70)->SetType(GRASS);
						bomb[j] = Bomb(img);
						bomb[j].SetLife(1);
						break;
					}
				}
			}

			frameCount = 0;
		}
	}
}

void Explosion::StartExplosion(int x_, int y_)
{
	if (!life)
	{
		life = 1;
		x = x_;
		y = y_;
	}
}
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Includs.h"


int Player::GetPX()
{
	return x;
}
int Player::GetPY()
{
	return y;
}
void Player::IncScr()
{
	score++;
}
int Player::GetPbX()
{
	return boundx;
}
int Player::GetPbY()
{
	return boundy;
}
int Player::GetScr()
{
	return score;
}

Player::Player(Bitmaps & img)
{
	x = 105;
	y = 105;
	speed = 3;
	score = 0;
	life = 1;
	bombs = 1;
	boundx = 30;
	boundy = 30;

	maxFrame = 3;
	curFrame = 0;
	frameCount = 0;
	frameDelay = 10;
	frameWidth = 60;
	frameHeight = 60;
	animationColumns = 3;
	animationDirection = 1;

	animationRow = 0;

	image = img.getPlayerImage();
}

void Player::DrawPlayer()
{
	int fx = (curFrame % animationColumns) * frameWidth;
	int fy = animationRow * frameHeight;

	al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - frameWidth / 2, y - frameHeight / 2, 0);
}

void Player::UpdatePlayer()
{
	if (++frameCount >= frameDelay)
	{
		curFrame += animationDirection;
		if (curFrame >= maxFrame)
		{
			curFrame = 0;
		}
		frameCount = 0;
	}
}

void Player::MovePlayerUp(Bomb * bomb, Map & map)
{
	animationRow = 3;
	y -= speed;
	if (map.WhereIAm(x + boundx, y - boundy)->GetType() != GRASS || map.WhereIAm(x - boundx, y - boundy)->GetType() != GRASS)
	{
		y += speed;
	}
	if (map.WhereIAm(x, y)->GetHandicap() == 1)
	{
		map.WhereIAm(x, y)->SetHandicap(0);
		bombs += 1;
		for (int i = 0; i < 3; i++)
		{
			if (!bomb[i].IsAlive())
			{
				bomb[i].SetLife(1);
				break;
			}
		}
	}
	if (y < 105)
		y = 105;
}

void Player::MovePlayerDown(Bomb * bomb, Map & map, int height)
{
	animationRow = 0;
	y += speed;
	if (map.WhereIAm(x + boundx, y + boundy)->GetType() != GRASS || map.WhereIAm(x - boundx, y + boundy)->GetType() != GRASS)
	{
		y -= speed;
	}
	if (map.WhereIAm(x, y)->GetHandicap() == 1)
	{
		map.WhereIAm(x, y)->SetHandicap(0);
		bombs += 1;
		for (int i = 0; i < 3; i++)
		{
			if (!bomb[i].IsAlive())
			{
				bomb[i].SetLife(1);
				break;
			}
		}
	}
	if (y > height - 100)
		y = height - 100;
}

void Player::MovePlayerLeft(Bomb * bomb, Map & map)
{
	animationRow = 1;
	x -= speed;
	if (map.WhereIAm(x - boundx, y - boundy)->GetType() != GRASS || map.WhereIAm(x - boundx, y + boundy)->GetType() != GRASS)
	{
		x += speed;
	}
	if (map.WhereIAm(x, y)->GetHandicap() == 1)
	{
		map.WhereIAm(x, y)->SetHandicap(0);
		bombs += 1;
		for (int i = 0; i < 3; i++)
		{
			if (!bomb[i].IsAlive())
			{
				bomb[i].SetLife(1);
				break;
			}
		}
	}
	if (x < 105)
		x = 105;
}

void Player::MovePlayerRight(Bomb * bomb, Map & map, int width)
{
	animationRow = 2;
	x += speed;
	if (map.WhereIAm(x + boundx, y - boundy)->GetType() != GRASS || map.WhereIAm(x + boundx, y + boundy)->GetType() != GRASS)
	{
		x -= speed;
	}
	if (map.WhereIAm(x, y)->GetHandicap() == 1)
	{
		map.WhereIAm(x, y)->SetHandicap(0);
		bombs += 1;
		for (int i = 0; i < 3; i++)
		{
			if (!bomb[i].IsAlive())
			{
				bomb[i].SetLife(1);
				break;
			}
		}
	}
	if (x > width - 105)
		x = width - 105;
}
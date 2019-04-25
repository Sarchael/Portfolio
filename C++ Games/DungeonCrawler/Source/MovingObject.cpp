#include "MovingObject.h"


MovingObject::MovingObject():GameObject()
{
	float velX = 0;
	float velY = 0;
	int dirX = 0;
	int dirY = 0;

	int maxFrame = 0;
	int curFrame = 0;
	int frameCount = 0;
	int frameDelay = 0;
	int frameWidth = 0;
	int frameHeight = 0;
	int animationColumns = 0;
	int animationDirection = 0;
}

void MovingObject::update()
{
	
}

void MovingObject::resetAnimation()
{
	this->frameCount = 0;
	this->curFrame = 0;
}

void MovingObject::updateAnimation()
{
	if (++frameCount >= frameDelay)
	{
		if (++curFrame >= maxFrame)
			curFrame = 0;

		frameCount = 0;
	}
}

void MovingObject::renderAnimated(float shift)
{
	if (getID() != Enums::IDS::NTH)
	{
		float xx = x - shift;
		float space = 10;
		//=====================================================================================================================================
		//al_draw_rectangle(x - shift, y, x - shift + boundX, y + boundY, al_map_rgb(255, 0, 255), 3.0);//rysuje zeby sprawdzic granice playera
		//=====================================================================================================================================

		if (dirX == 1)
		{
			al_draw_bitmap_region(image, curFrame*boundX, 0, boundX, boundY, xx, y, 0);
			facingRight = true;
		}
		else if (dirX == -1)
		{
			al_draw_bitmap_region(image, curFrame*boundX, 0, boundX, boundY, xx, y, ALLEGRO_FLIP_HORIZONTAL);
			facingRight = false;
		}
		else if (facingRight == true)al_draw_bitmap_region(image, curFrame*boundX, 0, boundX, boundY, xx, y, 0);
		else if (facingRight == false)al_draw_bitmap_region(image, curFrame*boundX, 0, boundX, boundY, xx, y, ALLEGRO_FLIP_HORIZONTAL);

		if (dirX == 0 && dirY == 0)
		{
			this->resetAnimation();
		}

		al_draw_line(xx, this->y - space, xx + this->boundX, this->y - space, al_map_rgb(255, 0, 0), space / 2);
		float hp_line = (this->HP / 100.0)*boundX;
		al_draw_line(xx, this->y - space, xx + hp_line, this->y - space, al_map_rgb(0, 255, 0), space / 2);
	}
}

void MovingObject::moveLeft()
{
	dirX = -1;
	int oldx = x;//mo¿na teleportowaæ gracza
	x += velX*dirX;
}

void MovingObject::moveRight()
{
	dirX = 1;
	int oldx = x;//mo¿na teleportowaæ gracza
	x += velX*dirX;
}

void MovingObject::moveDown()
{
	dirY = 1;
	y += velY*dirY;
}

void MovingObject::moveUp()
{
	dirY = -1;
	y += velY*dirY;
}

MovingObject::~MovingObject()
{
}

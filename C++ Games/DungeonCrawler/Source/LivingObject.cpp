#include "LivingObject.h"



LivingObject::LivingObject()
{
}

void LivingObject::update()
{
	if (HP <= 0)
		kill();
}

void LivingObject::init(float x, float y, float velX, float velY, std::string imageName, Enums::IDS id,int _maxFrame)
{
	this->x = x;
	this->y = y;
	this->velX = velX;
	this->velY = velY;
	this->image = al_load_bitmap(imageName.c_str());

	//Inicjalizacja zmiennych animacji
	this->frameCount = 0;
	this->frameDelay = 3;
	this->maxFrame = _maxFrame;
	this->curFrame = 0;

	//boundX/10 bo tyle jest zdjêæ
	boundX = al_get_bitmap_width(image) / maxFrame;
	boundY = al_get_bitmap_height(image);

	al_convert_mask_to_alpha(image, al_map_rgb(255, 255, 255));
	setID(id);

	HP = 100;
}

void LivingObject::render(float shift)
{
	al_draw_bitmap(image, x - shift, y, 0);
	//al_draw_rectangle(x - shift, y, x - shift + boundX, y + boundY, al_map_rgb(255, 0, 255), 3.0);//rysuje zeby sprawdzic granice playera
}

void LivingObject::resetXDir()
{
	dirX = 0;
}
void LivingObject::resetYDir()
{
	dirY = 0;
}


LivingObject::~LivingObject()
{
}

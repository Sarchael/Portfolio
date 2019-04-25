#include "GameObject.h"



GameObject::GameObject(): GameObject("kupa.png",0,0)
{
}

GameObject::GameObject(std::string imagename): GameObject(imagename,0,0)
{
}

GameObject::GameObject(std::string imagename,float x, float y)
{
	this->x = x;
	this->y = y;
	image = al_load_bitmap(imagename.c_str());
	//al_convert_mask_to_alpha(image, al_map_rgb(255, 255, 255));

	boundX = al_get_bitmap_width(image);
	boundY = al_get_bitmap_height(image);
}

void GameObject::init(float x, float y, int boundX, int boundY)
{
	GameObject::x = x;
	GameObject::y = y;


	GameObject::boundX = boundX;
	GameObject::boundY = boundY;
}



void GameObject::render(float shift)
{}



GameObject::~GameObject()
{
}

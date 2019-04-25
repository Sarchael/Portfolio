#pragma once
#include <allegro5\allegro.h>
#include<allegro5\allegro_image.h>
#include<string>
#include "Enums.h"

class GameObject
{
private:
	int ID;

protected:
	float x;
	float y;

	int boundX;
	int boundY;

	ALLEGRO_BITMAP *image = NULL;

public:
	GameObject();
	GameObject(std::string imagename);
	GameObject(std::string imagename,float x, float y);

	void init(float x, float y,  int boundX, int boundY);
	void virtual render(float shift);

	float getX() { return x; }
	float getY() { return y; }

	void setX(float x) { GameObject::x = x; }
	void setY(float y) { GameObject::y = y; }

	int getBoundX() { return boundX; }
	int getBoundY() { return boundY; }

	int getID() { return ID; }
	void setID(int ID) { GameObject::ID = ID; }

	~GameObject();
};


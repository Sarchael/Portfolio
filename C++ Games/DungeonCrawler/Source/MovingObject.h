#pragma once
#include "GameObject.h"
#include <allegro5\allegro_primitives.h>
class MovingObject : public GameObject
{
protected:
	float velX;
	float velY;
	int dirX;
	int dirY;
	int speed = 80;//dodajê do kolizji
	int HP;

	virtual void moveLeft();
	virtual void moveRight();
	virtual void moveDown();
	virtual void moveUp();

	//dla rysowania i animacji
	int maxFrame;
	int curFrame;
	bool facingRight = false;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;

	//na razie niepotrzebne
	int animationColumns;
	int animationDirection;

	
public:
	MovingObject();
	virtual void update();

	//resetuje zmienne animacji
	virtual void resetAnimation();
	//funkcja updatu kolejnych klatek animacji
	virtual void updateAnimation();

	void renderAnimated(float shift);
	~MovingObject();
};


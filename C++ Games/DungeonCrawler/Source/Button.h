#pragma once
#include "GameObject.h"
#include "Enums.h"
#include "GameState.h"
#include "allegro5\allegro_primitives.h"
class Button : public GameObject
{
	bool mouseInPosition(float mouse_x, float mouse_y);
public:
	Button(std::string imagename, float x, float y, Enums::FIXED_ID id);
	void draw(float mouse_x,float mouse_y);
	void buttonAction(int &gs, float mouse_x, float mouse_y);
	~Button();
};


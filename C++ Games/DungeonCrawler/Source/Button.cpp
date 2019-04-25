#include "Button.h"
#include "Enums.h"



Button::Button(std::string imagename, float x, float y,Enums::FIXED_ID id):GameObject(imagename,x,y)
{
	this->setID(id);
}

void Button::draw(float mouse_x, float mouse_y)
{
	al_draw_bitmap(image, x, y, NULL);

	if (this->mouseInPosition(mouse_x, mouse_y))
		al_draw_rectangle(x, y, x + boundX, y + boundY, al_map_rgb(255, 255, 255), 5);
}

bool Button::mouseInPosition(float mouse_x, float mouse_y)
{
	if (mouse_x >= x && mouse_x <= x + boundX)
		if (mouse_y >= y && mouse_y <= y + boundY)
			return true;
	return false;
}

void Button::buttonAction(int &gs, float mouse_x, float mouse_y)
{
	if (this->mouseInPosition(mouse_x, mouse_y))
	{
		switch (this->getID())
		{
		case Enums::FIXED_ID::EXIT:
			gs = GameState::END;
			break;
		case Enums::FIXED_ID::NEW_GAME:
			gs = GameState::LEVEL_1;
			break;
		case Enums::FIXED_ID::CONTROLS:
			gs = GameState::CTRLS;
			break;
		}
	}
}

Button::~Button()
{
}

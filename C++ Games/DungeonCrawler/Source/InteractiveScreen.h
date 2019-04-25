#pragma once
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "Enums.h"
#include "GameState.h"
struct interactiveText
{
	float x = 550;
	float y = 800;
	float bx = 200;
	float by = 70;
};

class InteractiveScreen
{
public:
	InteractiveScreen();
	ALLEGRO_BITMAP * IMAGE;
	ALLEGRO_FONT *FONT;
	interactiveText iT;
	void draw(int mx,int my);
	void interactiveTextAction(int &gs, int mx, int my);
	~InteractiveScreen();
};


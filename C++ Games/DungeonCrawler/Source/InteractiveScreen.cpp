#include "InteractiveScreen.h"



InteractiveScreen::InteractiveScreen()
{
	FONT = al_load_font("arial.ttf", 70, NULL);
}

void InteractiveScreen::interactiveTextAction(int &gs, int mx, int my)
{
	if (mx >= iT.x &&mx <= iT.x + iT.bx)
		if (my >= iT.y && my <= iT.y + iT.by)
			gs = GameState::TITLE;
}

void InteractiveScreen::draw(int mx, int my)
{
	al_draw_bitmap(IMAGE, 0, 0, NULL);
	if ((mx >= iT.x &&mx <= iT.x + iT.bx) && (my >= iT.y && my <= iT.y + iT.by))
		al_draw_text(FONT, al_map_rgb(255, 0, 0), iT.x, iT.y, NULL, "BACK");
	else
		al_draw_text(FONT, al_map_rgb(255, 255, 255), iT.x, iT.y, NULL, "BACK");
}


InteractiveScreen::~InteractiveScreen()
{
	al_destroy_bitmap(IMAGE);
	al_destroy_font(FONT);
}

#pragma once
#include "ScoreCounter.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "PlayableObject.h"
#include <string>
class ShowStats
{
private:
	ALLEGRO_BITMAP * stats;
	ALLEGRO_FONT * statsFont;
	int font_size = 50;
public:
	ShowStats();

	void renderStats(int posx, int score, int ult_cd, int norm_cd);

	~ShowStats();
};


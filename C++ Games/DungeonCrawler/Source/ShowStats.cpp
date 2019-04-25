#include "ShowStats.h"

using namespace std;

ShowStats::ShowStats()
{

	stats = al_load_bitmap("pasekdolny.png");
	if (!stats)
		throw string("brak obrazka paska dolnego!\n");
	statsFont = al_load_font("arial.ttf", font_size, 0);
	if (!statsFont)
		throw string("nie zaladowano czcionki do statystyk!\n");
}

void ShowStats::renderStats(int posx, int score, int ult_cd, int norm_cd)
{
	int y_of_stats = 800;
	int space = font_size + 20; //odleg³oœæ miêdzy tekstem
	int length_of_text = 300; //d³ugoœæ tekstu
	int line_correct = font_size / 2 + 5;//aby dopasowaæ do fonta


	/*Pole Statystyk*/
	al_draw_bitmap(stats, posx, y_of_stats, 0);

	/*SCORE*/
	al_draw_textf(statsFont, al_map_rgb(186, 0, 0), posx, y_of_stats, 0, "Your Score: %i", score);
	
	/*NORMAL CD*/
	al_draw_text(statsFont, al_map_rgb(186, 0, 0), posx, y_of_stats + space, 0, "Attack CD:  ");
	al_draw_line(posx + length_of_text, y_of_stats + space + line_correct, posx + length_of_text + norm_cd*5, y_of_stats + space + line_correct, al_map_rgb(255, 0, 144), font_size);
	
	/*ULTIMATE CD*/
	al_draw_text(statsFont, al_map_rgb(186, 0, 0), posx, y_of_stats + 2 * space, 0, "Ultimate CD:");
	al_draw_line(posx + length_of_text, y_of_stats + 2 * space + line_correct, posx + length_of_text + ult_cd/2, y_of_stats + 2 * space + line_correct, al_map_rgb(229, 173, 199), font_size);
	
}

ShowStats::~ShowStats()
{
	al_destroy_font(statsFont);
	al_destroy_bitmap(stats);
}

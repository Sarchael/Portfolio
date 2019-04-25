#pragma once
#include "Game.h"


int main()
{
	try
	{
		al_init();
	}
	catch (...)
	{
		std::cout << "Nie udalo sie zainicjowac allegro!" << std::endl;
	}

	al_init_image_addon(); // zeby dzialaly obrazki
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon(); // zeby dzialaly primitives
	al_install_keyboard(); // zeby dzialaly klawisze
	al_install_mouse();

	try
	{
		Game game;
		game.initAllegro();
		game.createGameObjects();
		game.gameLoop();
		game.allegroCleaner();
	}
	catch (const std::string& error)
	{
		std::cout << error << std::endl;
	}

	return 0;
}
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Includs.h"


Bitmaps::Bitmaps()
{
	background = al_load_bitmap("background.png"); // ladowanie obrazkow
	playerImage = al_load_bitmap("ghost.png");
	al_convert_mask_to_alpha(playerImage, al_map_rgb(0, 0, 0));
	wallImage = al_load_bitmap("stone2.jpg");
	chestImage = al_load_bitmap("chest.jpg");
	enemyImage = al_load_bitmap("mon2.png");
	aBombImage = al_load_bitmap("activebomb.png");
	al_convert_mask_to_alpha(aBombImage, al_map_rgb(255, 255, 255));
	explosionImage = al_load_bitmap("wybuch.png");
	nth = al_load_bitmap("nic.png");
	al_convert_mask_to_alpha(nth, al_map_rgb(255, 255, 255));
	inaBombImage = al_load_bitmap("inactivebomb.png");
	doorImage = al_load_bitmap("door.png");
	win = al_load_bitmap("WIN.png");
	start = al_load_bitmap("START.png");
	murd = al_load_bitmap("MURD.png");
	self = al_load_bitmap("SELF.png");
}
ALLEGRO_BITMAP * Bitmaps::getBackground()
{
	return background;
}
ALLEGRO_BITMAP * Bitmaps::getPlayerImage()
{
	return playerImage;
}
ALLEGRO_BITMAP * Bitmaps::getWallImage()
{
	return wallImage;
}
ALLEGRO_BITMAP * Bitmaps::getChestImage()
{
	return chestImage;
}
ALLEGRO_BITMAP * Bitmaps::getEnemyImage()
{
	return enemyImage;
}
ALLEGRO_BITMAP * Bitmaps::getABombImage()
{
	return aBombImage;
}
ALLEGRO_BITMAP * Bitmaps::getExplosionImage()
{
	return explosionImage;
}
ALLEGRO_BITMAP * Bitmaps::getNth()
{
	return nth;
}
ALLEGRO_BITMAP * Bitmaps::getInaBombImage()
{
	return inaBombImage;
}
ALLEGRO_BITMAP * Bitmaps::getDoorImage()
{
	return doorImage;
}
ALLEGRO_BITMAP * Bitmaps::getWin()
{
	return win;
}
ALLEGRO_BITMAP * Bitmaps::getStart()
{
	return start;
}
ALLEGRO_BITMAP * Bitmaps::getMurd()
{
	return murd;
}
ALLEGRO_BITMAP * Bitmaps::getSelf()
{
	return self;
}
Bitmaps::~Bitmaps()
{
	al_destroy_bitmap(background);
	al_destroy_bitmap(playerImage);
	al_destroy_bitmap(wallImage);
	al_destroy_bitmap(chestImage);
	al_destroy_bitmap(enemyImage);
	al_destroy_bitmap(aBombImage);
	al_destroy_bitmap(explosionImage);
	al_destroy_bitmap(nth);
	al_destroy_bitmap(inaBombImage);
	al_destroy_bitmap(doorImage);
	al_destroy_bitmap(win);
	al_destroy_bitmap(start);
	al_destroy_bitmap(murd);
	al_destroy_bitmap(self);
}
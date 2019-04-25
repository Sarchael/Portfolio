#pragma once

// Klasa opisuj¹ca bitmapy
class Bitmaps
{
private:

	//bitmapy odpowiadaj¹ce kazdemu elementowi gry
	ALLEGRO_BITMAP * background;
	ALLEGRO_BITMAP * playerImage;
	ALLEGRO_BITMAP * wallImage;
	ALLEGRO_BITMAP * chestImage;
	ALLEGRO_BITMAP * enemyImage;
	ALLEGRO_BITMAP * aBombImage;
	ALLEGRO_BITMAP * explosionImage;
	ALLEGRO_BITMAP * nth;
	ALLEGRO_BITMAP * inaBombImage;
	ALLEGRO_BITMAP * doorImage;
	ALLEGRO_BITMAP * win;
	ALLEGRO_BITMAP * start;
	ALLEGRO_BITMAP * murd;
	ALLEGRO_BITMAP * self;

public:

	Bitmaps();
	// konstruktor

	// gettery i settery
	ALLEGRO_BITMAP * getBackground();
	ALLEGRO_BITMAP * getPlayerImage();
	ALLEGRO_BITMAP * getWallImage();
	ALLEGRO_BITMAP * getChestImage();
	ALLEGRO_BITMAP * getEnemyImage();
	ALLEGRO_BITMAP * getABombImage();
	ALLEGRO_BITMAP * getExplosionImage();
	ALLEGRO_BITMAP * getNth();
	ALLEGRO_BITMAP * getInaBombImage();
	ALLEGRO_BITMAP * getDoorImage();
	ALLEGRO_BITMAP * getWin();
	ALLEGRO_BITMAP * getStart();
	ALLEGRO_BITMAP * getMurd();
	ALLEGRO_BITMAP * getSelf();

	~Bitmaps();
	// destruktor
};
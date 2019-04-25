#pragma once
#include "StaticObject.h"
class Tile : public StaticObject
{
public:
	Tile();
	Tile(float x, float y, int boundX, int boundY, int id, ALLEGRO_BITMAP * bmp);
	~Tile();
};


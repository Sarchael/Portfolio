#include "Tile.h"



Tile::Tile()
{
}

Tile::Tile(float x, float y, int boundX, int boundY, int id, ALLEGRO_BITMAP * bmp)
{
	GameObject::init(x, y, boundX, boundY);
	GameObject::setID(id);
	image = bmp;
}


Tile::~Tile()
{

}

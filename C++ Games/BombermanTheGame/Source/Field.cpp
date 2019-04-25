#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Includs.h"


int Field::GetType()
{
	return type;
}
void Field::SetType(int n)
{
	type = n;
}
int Field::GetHandicap()
{
	return handicap;
}
void Field::SetHandicap(int h)
{
	handicap = h;
}
int Field::GetX()
{
	return x;
}
int Field::GetY()
{
	return y;
}
void Field::SetExplosion(int n)
{
	explosion = n;
}
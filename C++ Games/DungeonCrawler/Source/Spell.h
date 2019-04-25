#pragma	once
#include "MovingObject.h"
#include "Collidable.h"
#include "Enums.h"

class Spell : public MovingObject, public Collidable
{
private:
	int damage;
	int range;

	ALLEGRO_BITMAP * norm_att = al_load_bitmap("Magic2.png");
	ALLEGRO_BITMAP * ult_skill = al_load_bitmap("Ultimate.png");
public:
	Spell(int x, int y, int powerup, int dir, Enums::IDS id);
	void ProcessCollision(Collidable* otherObject);
	void kill();
	void update();
	float GetPosX();
	float GetPosY();
	float getBoundX();
	float getBoundY();
	int IDnum();
	void resetAnimation();
	void updateAnimation();
	void render(float shift);
};
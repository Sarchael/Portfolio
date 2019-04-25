#pragma once
#include <vector>
#include <list>
#include "StaticObject.h"
#include "MovingObject.h"
#include "Tile.h"
#include "Button.h"
#include "CollisionSystem.h"
#include "Spell.h"
#include "EnemyObject.h"
#include "PlayableObject.h"
#include "RegularTroll.h"
#include "RedTroll.h"
#include "OrangeTroll.h"
#include "ScoreCounter.h"


class Factory
{
public:
	Factory();

	void createPlayableObject(PlayableObject &po);

	std::vector<std::vector<StaticObject*>> createMap();
	std::vector<Button*> createVectorOfButtons(float width, float height);
	std::vector<EnemyObject*> createVectorOfEnemyObjects(ScoreCounter * sc);
	Spell* createSpell(int x, int y, int powerup, int dir, Enums::IDS id);
	CollisionSystem createCollisions;//dodajemy kolizje, tzn. dziêki temu bêdziemy dodawaæ obiekty do vektora kolizji //MO¯E NIE POWINNO BYC PUBLIC?
	~Factory();
};


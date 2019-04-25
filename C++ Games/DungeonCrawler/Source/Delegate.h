#pragma once
#include "ScoreCounter.h"
#include "EnemyObject.h"
class EnemyObject;//te szity trzeba bylo pododawac, nie pytajcie czemu bo nie wiem ale znalazlem tak na forum jakims
class ScoreCounter;

class Delegate //klasa generalnie sluzy do przekazywania informacji o smierci potworka counterowi ktory mieszka w playerze
{
	bool dead = false; //to jest szit ktory zabezpiecza przed wielokrotnym dodawaniem punktow
	ScoreCounter * Scounter;
public:
	Delegate();
	Delegate(ScoreCounter * sc);
	void action(EnemyObject * enem);
	~Delegate();
};


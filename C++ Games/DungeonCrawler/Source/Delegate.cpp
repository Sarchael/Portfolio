#include "Delegate.h"



Delegate::Delegate()
{}
Delegate::Delegate(ScoreCounter * sc)
{
	Scounter = sc;
}

void Delegate::action(EnemyObject * enem) // w momencie smierci potworka wywolujemy to zeby przekazac ScoreCounterowi info o pokonaniu potworka
{
	if (!dead)
	{
		Scounter->defeatMonster(enem);
		dead = true; 
	}
	
}

Delegate::~Delegate()
{
}

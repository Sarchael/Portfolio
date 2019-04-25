#include "ScoreCounter.h"
#include "Enums.h"
#include <iostream>



ScoreCounter::ScoreCounter()
{
	score = 20;
	timer = 0;
}

void ScoreCounter::countScore()
{
	if (timer > 60)
	{
		if (score > 0)
			score -= 1;
		
		timer = 0;
	}
}

void ScoreCounter::defeatMonster(EnemyObject * enemy) // metoda wywolywana przez delegata. Po zabiciu potwora przyznaje nam punkty
{
	std::string a = typeid(*enemy).name(); //RTTI, sprawdzamy nazwe klasy potwora ktorego zabilismy i dajemy odpowiednio punkty
	if (a == "class RegularTroll")
		score += 30;
	else if (a == "class RedTroll")
		score += 50;
	else if (a == "class OrangeTroll")
		score += 60;
	
}

void ScoreCounter::openChest()
{
	score += 10;
}

void ScoreCounter::hitByMonster(EnemyObject * enemy) // Odejmuje nam punkty w momencie kiedy potworek nas hitnie. mechanizm ten sam
{
	std::string a = typeid(*enemy).name();
	//std::cout << "|" + a + "|" << std::endl;
	if (a == "class RegularTroll" && score > 2)
		score -= 3;
	else if (a == "class RedTroll" && score > 1)
		score -= 2;
	else if (a == "class OrangeTroll" && score > 0)
		score -= 1;
}

void ScoreCounter::resetScoreCounter()
{
	score = 20;
	timer = 0;
}

int ScoreCounter::getScore()
{
	countScore();
	return score;
}



ScoreCounter::~ScoreCounter()
{
}

#pragma once
#include "EnemyObject.h"
class EnemyObject;
class Delegate;

class ScoreCounter //system punktow
{
	int score; //wynik ogolny
	int timer; //licznik do odmierzania czasu. Co sekunde od sumy punktow odejmowane jest 1
	void countScore(); //a ta funkcja to robi ^
public:
	ScoreCounter();

	void incrementTimer() { timer++; }; //inkrementowanie timera w 60 fpsach (w metodzie update playera)
	void defeatMonster(EnemyObject * enemy); //w cpp
	void openChest(); //dodaje punkty po zebraniu skrzynki
	void hitByMonster(EnemyObject * enemy); // w cpp
	void resetScoreCounter();

	int getScore(); //zwraca wyliczony wynik

	~ScoreCounter();
};


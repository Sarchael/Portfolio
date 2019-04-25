#pragma once


enum KEYS { UP, DOWN, RIGHT, LEFT, SPACE }; // do ruchu
enum FIELDS { GRASS, CHEST, WALL, ACT_BOMB }; // to okreslenia typu pola
enum STATE { TITLE, PLAYING, SKILL, EKILL, WIN }; // do okreslenia stanu gry

// klasa opisuj�ca interakcje

class Interactions
{
public:

	void DestroyEnemy(Enemies * enemy, Map & map, Player & player);
	// Metoda sprawdza czy nie wysadzili�my wroga

	void SelfKill(Player & player, Map & map, Enemies * enemy, Bomb * bomb, Explosion * exp, int & state, Bitmaps & img);
	// Metoda sprawdza czy nie wysadzili�my siebie

	void EnemyKill(Player & player, Map & map, Enemies * enemy, Bomb * bomb, Explosion * exp, int & state, Bitmaps & img);
	// Metoda sprawdza czy potw�r nas nie zabi�

	void EndGame(Player & player, Map & map, Enemies * enemy, Bomb * bomb, Explosion * exp, int & state, Bitmaps & img);
	// Metoda sprawdza czy nie wygrali�my

	void ChangeState(Player & player, Map & map, Enemies * enemy, Bomb * bomb, Explosion * exp, int & state, int newState, Bitmaps & img);
	//Metoda zmienia stan gry
};
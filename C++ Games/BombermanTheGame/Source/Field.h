#pragma once

// Klasa opisuj�ca pole mapy
class Field
{
private:

	friend class Map;
	friend class Interactions;

	int x; // po�o�enie na osi x
	int y; // po�o�enie na osi y
	int handicap; // posiadanie handicapu
	int type; // typ pola
	int explosion; // czy w danej chwili na polu wyst�puje eksplozja

	ALLEGRO_BITMAP * image; // obrazek pola

public:

	//gettery i settery
	int GetType();
	void SetType(int n);
	int GetHandicap();
	void SetHandicap(int h);
	int GetX();
	int GetY();
	void SetExplosion(int n);
};
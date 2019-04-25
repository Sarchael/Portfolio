#pragma once

// Klasa opisuj¹ca potworki
class Enemies
{
	int x; // po³o¿enie na osi x
	int y; // po³o¿enie na osi y
	int speed; // prêdkoœæ
	int life; // czy potworek ¿yje
	int dir; // kierunek poruszania siê
	int boundx; // odlag³oœæ od x do krawêdzi bitmapy potworka
	int boundy; // odlag³oœæ od y do krawêdzi bitmapy potworka

	int frameWidth; // szerokoœæ klatki (w tym wypadku ca³ego obrazu)
	int frameHeight; // wysokoœæ klatki (w tym wypadku ca³ego obrazu)

	ALLEGRO_BITMAP * image; // obrazek potworka
public:
	Enemies(Bitmaps & img, int nr);
	// konstruktor

	void DrawEnemies();
	//Metoda renderuje potworki

	void MoveEnemies(Map & map);
	//Metoda odpowiedzialna za ruch potworów

	//Gettery i settery
	void SetLife(int n);
	int GetLife();
	int GetEX();
	int GetEY();
	int GetEbX();
	int GetEbY();
};
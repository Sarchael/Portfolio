#pragma once

// Klasa opisuj�ca potworki
class Enemies
{
	int x; // po�o�enie na osi x
	int y; // po�o�enie na osi y
	int speed; // pr�dko��
	int life; // czy potworek �yje
	int dir; // kierunek poruszania si�
	int boundx; // odlag�o�� od x do kraw�dzi bitmapy potworka
	int boundy; // odlag�o�� od y do kraw�dzi bitmapy potworka

	int frameWidth; // szeroko�� klatki (w tym wypadku ca�ego obrazu)
	int frameHeight; // wysoko�� klatki (w tym wypadku ca�ego obrazu)

	ALLEGRO_BITMAP * image; // obrazek potworka
public:
	Enemies(Bitmaps & img, int nr);
	// konstruktor

	void DrawEnemies();
	//Metoda renderuje potworki

	void MoveEnemies(Map & map);
	//Metoda odpowiedzialna za ruch potwor�w

	//Gettery i settery
	void SetLife(int n);
	int GetLife();
	int GetEX();
	int GetEY();
	int GetEbX();
	int GetEbY();
};
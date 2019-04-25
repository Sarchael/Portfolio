#pragma once

// Klasa opisuj�ca bomby
class Bomb
{
private:

	int x; // po�o�enie na osi x
	int y; // po�o�enie na osi y
	int life; // czy bomba jest zebrana
	int active; // czy bomba jest aktywna

	int frameWidth; // szeroko�� klatki (w tym wypadku ca�ego obrazu)
	int frameHeight; //wysoko�� klatki (w tym wypadku ca�ego obrazu)
	int counter; // licznik (do animacji wybuchu)

	ALLEGRO_BITMAP * image; // obrazek bomby

public:

	//gettery i settery
	void SetLife(int n);
	bool IsAlive();
	void SetBX(int n);
	void SetBY(int n);
	int GetBX();
	int GetBY();


	Bomb(Bitmaps & img);
	// Konstruktor inicjalizuje bomby okre�lonymi warto�ciami
	// image -> referencja do obiektu z bitmapami
	bool ActiveBomb(Player & player, Map & map);
	// Metoda aktywuje bomb�
	// player -> referencja do obiektu gracza
	// map -> tablica p�l mapy czyli mapa

	void DrawBomb();
	// Metoda rysuje na ekranie bomb�
	
	void UpdateBomb(Explosion * exp, Map & map, Bitmaps & img);
	// Metoda odlicza czas do startu eksplozji i j� rozpoczyna, ustawia na polach mapy status eksplozji
	// exp -> wska�nik na eksplozj�
	// map -> tablica p�l mapy czyli mapa
	// image -> referencja do obiektu z bitmapami
};
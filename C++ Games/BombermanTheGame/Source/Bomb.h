#pragma once

// Klasa opisuj¹ca bomby
class Bomb
{
private:

	int x; // po³o¿enie na osi x
	int y; // po³o¿enie na osi y
	int life; // czy bomba jest zebrana
	int active; // czy bomba jest aktywna

	int frameWidth; // szerokoœæ klatki (w tym wypadku ca³ego obrazu)
	int frameHeight; //wysokoœæ klatki (w tym wypadku ca³ego obrazu)
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
	// Konstruktor inicjalizuje bomby okreœlonymi wartoœciami
	// image -> referencja do obiektu z bitmapami
	bool ActiveBomb(Player & player, Map & map);
	// Metoda aktywuje bombê
	// player -> referencja do obiektu gracza
	// map -> tablica pól mapy czyli mapa

	void DrawBomb();
	// Metoda rysuje na ekranie bombê
	
	void UpdateBomb(Explosion * exp, Map & map, Bitmaps & img);
	// Metoda odlicza czas do startu eksplozji i j¹ rozpoczyna, ustawia na polach mapy status eksplozji
	// exp -> wskaŸnik na eksplozjê
	// map -> tablica pól mapy czyli mapa
	// image -> referencja do obiektu z bitmapami
};
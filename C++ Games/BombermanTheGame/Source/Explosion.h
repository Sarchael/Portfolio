#pragma once

// Klasa opisuj�ca eksplozje
class Explosion
{
private:
	int x; // po�o�enie na osi x
	int y; // po�o�enie na osi y
	int life; // czy wybuch jest aktywny

			  // zmienne potrzebne do animacji wybuchu
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	int animationDirection;

	ALLEGRO_BITMAP * image; // obrazek eksplozji
public:

	bool IsAlive();
	//Metoda zwracaj�ca 1 jak wybuch jest aktywny i 0 jak nie jest

	Explosion(Bitmaps & image);
	// Metoda inicjalizuje eksplozje

	void DrawExplosion(Map & map);
	// Metoda rysuje eksplozj� na mapie


	void UpdateExplosion(Bomb * bomb, Map & map, Bitmaps & img);
	// Funkcja posuwa animacj� dalej, po jej sko�czeniu wy��cza na polach mapy status eksplozji i przywraca bomb� graczowi
	// bomb -> wska�nik na bomb�

	void StartExplosion(int x_, int y_);
	// Metoda rozpoczyna eksplozj�
	// x -> wsp�rz�dna osi x eksplozji
	// y -> wsp�rz�dna osi y eksplozji
};
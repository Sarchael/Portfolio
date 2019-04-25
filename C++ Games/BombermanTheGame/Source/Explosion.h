#pragma once

// Klasa opisuj¹ca eksplozje
class Explosion
{
private:
	int x; // po³o¿enie na osi x
	int y; // po³o¿enie na osi y
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
	//Metoda zwracaj¹ca 1 jak wybuch jest aktywny i 0 jak nie jest

	Explosion(Bitmaps & image);
	// Metoda inicjalizuje eksplozje

	void DrawExplosion(Map & map);
	// Metoda rysuje eksplozjê na mapie


	void UpdateExplosion(Bomb * bomb, Map & map, Bitmaps & img);
	// Funkcja posuwa animacjê dalej, po jej skoñczeniu wy³¹cza na polach mapy status eksplozji i przywraca bombê graczowi
	// bomb -> wskaŸnik na bombê

	void StartExplosion(int x_, int y_);
	// Metoda rozpoczyna eksplozjê
	// x -> wspó³rzêdna osi x eksplozji
	// y -> wspó³rzêdna osi y eksplozji
};
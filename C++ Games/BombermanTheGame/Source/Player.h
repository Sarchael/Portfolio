#pragma once


class Player
{
private:

	int x; // po³o¿enie na osi x
	int y; // po³o¿enie na osi y
	int speed; // prêdkoœæ
	int score; // wynik
	int life; // czy gracz ¿yje
	int bombs; // iloœæ posiadanych bomb
	int boundx; // odlag³oœæ od x do krawêdzi bitmapy gracza
	int boundy; // odlag³oœæ od y do krawêdzi bitmapy gracza

				// zmienne potrzebne do animacji gracza
	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	int animationDirection;
	int animationRow;

	ALLEGRO_BITMAP * image; // obrazek gracza

public:

	//gettery i settery
	int GetPX();
	int GetPY();
	int GetPbX();
	int GetPbY();
	void IncScr();
	int GetScr();

	Player(Bitmaps & img);
	// Konstruktor

	void DrawPlayer();
	// Metoda rysuje gracza na mapie

	void UpdatePlayer();
	// Metoda odpowiadaj¹ca za animacjê gracza

	void MovePlayerUp(Bomb * bomb, Map & map);
	// Metoda odpowiada za ruch gracza w górê

	void MovePlayerDown(Bomb * bomb, Map & map, int height);
	// Metoda odpowiada za ruch gracza w dó³
	// height -> zmienna okreœlaj¹ca wysokoœæ okna

	void MovePlayerLeft(Bomb * bomb, Map & map);
	// Metoda odpowiada za ruch gracza w lewo


	void MovePlayerRight(Bomb * bomb, Map & map, int width);
	// Metoda odpowiada za ruch gracza w prawo
	// width -> szerokoœæ okna
};
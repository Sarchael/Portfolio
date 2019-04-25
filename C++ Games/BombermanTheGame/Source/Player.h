#pragma once


class Player
{
private:

	int x; // po�o�enie na osi x
	int y; // po�o�enie na osi y
	int speed; // pr�dko��
	int score; // wynik
	int life; // czy gracz �yje
	int bombs; // ilo�� posiadanych bomb
	int boundx; // odlag�o�� od x do kraw�dzi bitmapy gracza
	int boundy; // odlag�o�� od y do kraw�dzi bitmapy gracza

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
	// Metoda odpowiadaj�ca za animacj� gracza

	void MovePlayerUp(Bomb * bomb, Map & map);
	// Metoda odpowiada za ruch gracza w g�r�

	void MovePlayerDown(Bomb * bomb, Map & map, int height);
	// Metoda odpowiada za ruch gracza w d�
	// height -> zmienna okre�laj�ca wysoko�� okna

	void MovePlayerLeft(Bomb * bomb, Map & map);
	// Metoda odpowiada za ruch gracza w lewo


	void MovePlayerRight(Bomb * bomb, Map & map, int width);
	// Metoda odpowiada za ruch gracza w prawo
	// width -> szeroko�� okna
};
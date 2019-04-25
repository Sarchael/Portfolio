#pragma once

// Klasa opisuj�ca map�
class Map
{
private:

	Field ** map; // Dwuwymiarowa tablica p�l mapy

public:

	Field** retMap();
	// Metoda zwraca map�

	Map(Bitmaps & img);
	// Konstruktor

	void Background(Bitmaps & background);
	// Metoda rysuje t�o
	// background -> referencja do obiektu z bitmapami

	void DrawMap();
	// Metoda rysuje map�

	void DrawHandicaps(Bitmaps & images);
	// Metoda rysuje handicapy i drzwi
	// images -> referencja do obiektu z bitmapami

	Field * WhereIAm(int x, int y);
	// Metoda zwracaj�ca wska�nik na pole o zadanym x i y
};
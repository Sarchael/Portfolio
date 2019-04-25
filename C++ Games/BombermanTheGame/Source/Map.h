#pragma once

// Klasa opisujπca mapÍ
class Map
{
private:

	Field ** map; // Dwuwymiarowa tablica pÛl mapy

public:

	Field** retMap();
	// Metoda zwraca mapÍ

	Map(Bitmaps & img);
	// Konstruktor

	void Background(Bitmaps & background);
	// Metoda rysuje t≥o
	// background -> referencja do obiektu z bitmapami

	void DrawMap();
	// Metoda rysuje mapÍ

	void DrawHandicaps(Bitmaps & images);
	// Metoda rysuje handicapy i drzwi
	// images -> referencja do obiektu z bitmapami

	Field * WhereIAm(int x, int y);
	// Metoda zwracajπca wskaünik na pole o zadanym x i y
};
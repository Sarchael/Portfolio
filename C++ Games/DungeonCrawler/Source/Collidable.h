#pragma once
#include "GameObject.h"

class Collidable//KLASA KT�R� Z KT�REJ DZIEDZICZ� WSZYSTKIE OBIEKTY, KT�RE B�D� MIA�Y KOLIZJE --- DODATKOWE DZIEDZICZENIE
{
public:
	virtual float GetPosX() = 0;//dodane w klasach, kt�re maj� mie� kolizje  
	virtual float GetPosY() = 0;//dodane w klasach, kt�re maj� mie� kolizje 
	virtual float getBoundX() = 0;
	virtual float getBoundY() = 0;
	virtual int IDnum() = 0;//dodane w klasach, kt�re maj� mie� kolizje 
	//virtual float GetSize() = 0;//mo�e si� przyda, a mo�e nie
	virtual void ProcessCollision(Collidable* otherObject) = 0;//dodane w klasach, kt�re maj� mie� kolizje <--- tutaj wchodzimy w momencie, kiedy chcemy sprawdzi�, czy wyst�pi�a jaka� kolizja
	virtual void kill() = 0;
	virtual ~Collidable() {}//wirtualny destruktor, bo s� funkcje virtual
};

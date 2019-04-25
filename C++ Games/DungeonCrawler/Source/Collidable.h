#pragma once
#include "GameObject.h"

class Collidable//KLASA KTÓR¥ Z KTÓREJ DZIEDZICZ¥ WSZYSTKIE OBIEKTY, KTÓRE BÊDÊ MIA£Y KOLIZJE --- DODATKOWE DZIEDZICZENIE
{
public:
	virtual float GetPosX() = 0;//dodane w klasach, które maj¹ mieæ kolizje  
	virtual float GetPosY() = 0;//dodane w klasach, które maj¹ mieæ kolizje 
	virtual float getBoundX() = 0;
	virtual float getBoundY() = 0;
	virtual int IDnum() = 0;//dodane w klasach, które maj¹ mieæ kolizje 
	//virtual float GetSize() = 0;//mo¿e siê przyda, a mo¿e nie
	virtual void ProcessCollision(Collidable* otherObject) = 0;//dodane w klasach, które maj¹ mieæ kolizje <--- tutaj wchodzimy w momencie, kiedy chcemy sprawdziæ, czy wyst¹pi³a jakaœ kolizja
	virtual void kill() = 0;
	virtual ~Collidable() {}//wirtualny destruktor, bo s¹ funkcje virtual
};

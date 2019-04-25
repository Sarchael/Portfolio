#include "CollisionSystem.h"
#include "Factory.h"
#include <iostream> // do testow


void CollisionSystem::AddToCollisinList(Collidable* object)
{
	objectList.push_back(object);
}
void CollisionSystem::RemoveFromCollisionList(Collidable* object)
{
	std::vector<Collidable*>::iterator iter;
	for (iter = objectList.begin(); iter != objectList.end(); ++iter)//szukamy obiektu do usuniêcia
	{
		if (*iter == object)
		{
			objectList.erase(iter);
			break;
		}
	}
}
void CollisionSystem::ProcessCollisionList()//wywo³ujemy to w momencie ruchu, wtedy sprawdzamy vector obiektów, które mog¹ mieæ kolizje
{
	std::vector<Collidable*>::iterator iter1;
	std::vector<Collidable*>::iterator killing_iter;
	int oX1=0;//nie wiem czy float czy int
	int oY1=0;
	int sizeofmap1 = sizeofmap();//chyba jednak siê nie przyda

	for (iter1 = objectList.begin(); iter1 != objectList.end(); ++iter1)//jakoœ trzeba przejœæ tê tablicê
	{
		
		if ((*iter1)->IDnum() == Enums::IDS::PLAYER || (*iter1)->IDnum() == Enums::IDS::NORMAL_ATTACK || (*iter1)->IDnum() == Enums::IDS::ULTIMATE_SKILL || (*iter1)->IDnum()== Enums::IDS::ENEMY)
		{
			oX1 = (*iter1)->GetPosX() / 80;//mo¿e inaczej, ale w sumie siê zgadza(pewnie dla ci¹g³ego trochê inaczej)
			oY1 = (*iter1)->GetPosY() / 80;
			//std::cout << oX1 << std::endl;

			for (int i = -1; i < 2; i++) // sprawdzanie kolizji w kwadacie 5x5 wiedz¹c, ze w srodku w kwadracie 3x3 znajduje sie gracz (bedzie dzialalo tak samo w kwadracie 3x3
			{							// wiec jak beda lagi to sie zmniejszy
				for (int j = -1; j < 2; j++)
				{
					if (oY1 + i >= 0 && oX1 + j >= 0 && oY1 + i < 10 && oX1 + j < sizeofmap1) //sprawdzam czy nie wychodze poza wektor
						if (map1[oY1 + i][oX1 + j]->IDnum() != Enums::IDS::NTH) //sprawdzamy czy jest w tym promiuniu cokolwiek co nie jest powierzem
						{
							(*iter1)->ProcessCollision((map1[oY1 + i][oX1 + j])); //wywolujemy proces obslugi kolizji w playerze (na razie tylko w nim)
							if ((map1[oY1 + i][oX1 + j])->IDnum() == Enums::IDS::NTH)
							{
								RemoveFromCollisionList((map1[oY1 + i][oX1 + j]));
							}
						}

				}
			}
			for (killing_iter = objectList.begin(); killing_iter != objectList.end(); ++killing_iter)
			{
				(*iter1)->ProcessCollision(*killing_iter);
			}
		}
	}
}
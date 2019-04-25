#pragma once
#include <vector>
#include "Collidable.h"
#include "Enums.h"
#include "StaticObject.h"
#include <fstream>


class CollisionSystem
{
private:
	std::vector<Collidable*> objectList;//lista obiektów, które mog¹ mieæ kolizje
	
public:
	void AddToCollisinList(Collidable* object);//dodanie do listy obiektów
	void RemoveFromCollisionList(Collidable* object);//wywalenie z listy obiektów
	void ProcessCollisionList();//wywo³ujemy to w momencie ruchu, wtedy sprawdzamy vector obiektów, które mog¹ mieæ kolizje
	int sizeofmap()//raczej siê nie przyda
	{
		std::ifstream file;
		file.open("maptest.txt");
		int size;
		char ch;
		file >> size;
		file.close();
		return size;
	}
	std::vector<std::vector<StaticObject*>> map1;//aby ³atwo przejrzeæ mapê
	void clearVectors()
	{
		objectList.clear();
		map1.clear();
	}
	

};
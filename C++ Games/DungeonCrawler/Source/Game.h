#pragma once
#include "Enums.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include "GameObject.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "Factory.h"
#include "Button.h"
#include "Spell.h"
#include "Collidable.h"
#include "CollisionSystem.h"
#include "PlayableObject.h"
#include "EnemyObject.h"
#include <iostream>
#include <thread>
#include "InteractiveScreen.h"
#include "GameState.h"
#include "ShowStats.h"
class Game
{
private:
	int WIDTH;
	int HEIGHT;
	//bool done = false; juz niepotrzebne
	//int game_state;  // okresla stan gry
	GameState gamestate;
	float mouse_x;
	float mouse_y;
	int normal_attack_cooldown;
	int ultimate_skill_cooldown;
	bool ult_on_cd = 0;
	bool unlockUPDOWN;//do drabiny/latania

	int start_of_rendering;
	int finish_of_rendering;

	int finalscore;

	InteractiveScreen ctrlsScrn;
	InteractiveScreen deadScrn;
	InteractiveScreen endScrn;

	ALLEGRO_FONT * endFont;

	int key[5]; // zmienne okreslajace czy dany klawisz jest wcisniety
	bool redraw; // zapewnia renderowanie w 60 FPSach
	int FPS; // ustawia ilosc FPS
						//int state = -1; // okresla stan gry
	ALLEGRO_DISPLAY * display;
	ALLEGRO_EVENT_QUEUE * event_queue; // tworzenie kolejki
	ALLEGRO_TIMER * timer;

	Factory factory;

	ShowStats showstats;

	PlayableObject player;
	//EnemyObject enemy;
	//Enums enums;
	std::vector<std::vector<StaticObject*>> map;
	//std::list<MovingObject*> list_of_collidable_objects;
	std::vector<EnemyObject*> vector_of_enemyObjects;
	std::vector<Spell*> list_of_spells;
	std::vector<Spell*>::iterator spells_iterator;
	std::vector<Button*> buttons;
public:
	Game();
	void initAllegro();
	void createGameObjects();
	void gameLoop();
	void timerEvents(ALLEGRO_EVENT * event);
	void keyDownEvents(ALLEGRO_EVENT * event);
	void keyUpEvents(ALLEGRO_EVENT * event);
	void displayButtonsEvents(ALLEGRO_EVENT * event);
	void mouseEvents(ALLEGRO_EVENT * event);
	void renderAndLogic();
	void renderMap();
	void levelOne();
	void menu();
	void collidableRenderAndLogic();
	void allegroCleaner();
	void controls();
	void killed();
	void end();
	void resetGameVectors();

	//Obsluga przeciwnikow (updaty i rysowanie)
	void processEnemyActions();
	void renderEnemies();
	~Game();
};


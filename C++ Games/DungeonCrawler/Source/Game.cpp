#include "Game.h"
#include <iostream>


Game::Game()
{
	WIDTH = 1840;
	HEIGHT = 1020;
	//game_state = TITLE;  // okresla stan gry
	gamestate.state = gamestate.TITLE;
	mouse_x = 0;
	mouse_y = 0;
	normal_attack_cooldown = 0;
	ultimate_skill_cooldown = 0;
	unlockUPDOWN = false;//do drabiny/latania
	endFont = al_load_font("arial.ttf", 66, 0);

	finalscore = 0;

	ctrlsScrn.IMAGE = al_load_bitmap("kontrolsy.png"); //jednak musi tu by, przepraszam Szymon ;c
	deadScrn.IMAGE = al_load_bitmap("killed.png");
	endScrn.IMAGE = al_load_bitmap("end.png");

	for (int i = 0; i < 5; i++)
	{
		key[i] = false;// zmienne okreslajace czy dany klawisz jest wcisniety
	}
	redraw = true; // zapewnia renderowanie w 60 FPSach
	FPS = 60; // ustawia ilosc FPS
						//int state = -1; // okresla stan gry
	
	display = al_create_display(WIDTH, HEIGHT);
	event_queue = al_create_event_queue(); // tworzenie kolejki
	timer = al_create_timer(1.0 / FPS);
	srand(time(NULL));
}

void Game::initAllegro()
{
	al_init_image_addon(); // zeby dzialaly obrazki
	al_init_primitives_addon(); // zeby dzialaly primitives
	al_install_keyboard(); // zeby dzialaly klawisze
	
	al_install_mouse();
	al_set_window_title(display, "Platformowka");
	al_register_event_source(event_queue, al_get_keyboard_event_source()); //okreslenie jakie zdarzenia maj¹ byæ brane do kolejki zdarzen
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_start_timer(timer);
}

void Game::createGameObjects()
{
	
	factory.createPlayableObject(player);
	map = factory.createMap();
	vector_of_enemyObjects = factory.createVectorOfEnemyObjects(player.getScoreCounter());
	buttons = factory.createVectorOfButtons(WIDTH, HEIGHT);
}

void Game::resetGameVectors()
{
	map.clear();
	vector_of_enemyObjects.clear();
	buttons.clear();
	player.setShift(0);
	createGameObjects();
	normal_attack_cooldown = 0;
	ultimate_skill_cooldown = 0;
	player.getScoreCounter()->resetScoreCounter();
}

void Game::timerEvents(ALLEGRO_EVENT * event)
{
	if (event->type == ALLEGRO_EVENT_TIMER) // funkcje odpowiedzialne za mechanike gry dzialajace w 60FPSach
	{
		redraw = true;
		if (player.getHP() < 1)
		{
			finalscore = player.getScoreCounter()->getScore();
			gamestate.state = gamestate.KILLED;
			factory.createCollisions.clearVectors(); //.clear dla map1 i collision vector
			resetGameVectors(); //.clear a potem ponowne ustawianie player, map, enemy, buttons
		}

		else if (player.ended)
		{
			finalscore = player.getScoreCounter()->getScore();
			gamestate.state = gamestate.WON;
			factory.createCollisions.clearVectors(); //.clear dla map1 i collision vector
			resetGameVectors(); //.clear a potem ponowne ustawianie player, map, enemy, buttons
			player.ended = false;
		}
			
		if (gamestate.state == gamestate.LEVEL_1)
		{
			if (player.key[Enums::KEYS::LEFT])
				player.moveLeft();
			else if (player.key[Enums::KEYS::RIGHT])
				player.moveRight();
			else
				player.resetXDir();

			if (player.key[Enums::KEYS::SPACE] && player.onLdr == false)
			{
				player.isJumping = true;
				key[Enums::KEYS::SPACE] = false;
				player.key[Enums::KEYS::SPACE] = false;
			}
			else
				player.resetYDir();

			if (player.key[Enums::KEYS::UP] == true && player.onLdr == true)
			{
				player.moveUp();
				player.gravityOn = false;
			}
			else if (player.key[Enums::KEYS::DOWN] == true && player.onLdr == true)
			{
				player.moveDown();
				player.gravityOn = false;
			}
			else player.resetYDir();

			if (player.key[Enums::KEYS::LCTRL] && !normal_attack_cooldown)
			{
				list_of_spells.push_back(factory.createSpell(player.GetPosX() + player.getBoundX(), player.GetPosY(), player.getAdditionalDamage(), player.getFacing(), Enums::IDS::NORMAL_ATTACK));
				normal_attack_cooldown = 25;
				player.key[Enums::KEYS::LCTRL] = false;
			}
			if (player.key[Enums::KEYS::X] && !ultimate_skill_cooldown)
			{
				list_of_spells.push_back(factory.createSpell(player.GetPosX() + player.getBoundX(), player.GetPosY(), player.getAdditionalDamage(), player.getFacing(), Enums::IDS::ULTIMATE_SKILL));
				ultimate_skill_cooldown = 1800;
				ult_on_cd = 1;
				player.key[Enums::KEYS::X] = false;
			}

			player.gravity(); 
			player.update();
			player.updateAnimation();

			processEnemyActions();

			if (player.isJumping == true && player.onLdr == false)//jesli skacze updatujemy jego lot
			{
				player.jumpUpdate();
				player.jump();
			}
			else if (player.onLdr) //jesli na drabiinie to juz nie skacze wec trzeba zresetowac zmienne skoku
			{
				player.jumpReset();
			}

		}

	}
}

void Game::keyDownEvents(ALLEGRO_EVENT * event)
{
	if (event->type == ALLEGRO_EVENT_KEY_DOWN) //obsluga klawiszy
	{
		switch (event->keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			key[Enums::KEYS::UP] = true;
			player.key[Enums::KEYS::UP] = true;

			break;
		case ALLEGRO_KEY_DOWN:
			key[Enums::KEYS::DOWN] = true;
			player.key[Enums::KEYS::DOWN] = true;
			break;
		case ALLEGRO_KEY_LEFT:
			key[Enums::KEYS::LEFT] = true;
			player.key[Enums::KEYS::LEFT] = true;
			break;
		case ALLEGRO_KEY_RIGHT:
			key[Enums::KEYS::RIGHT] = true;
			player.key[Enums::KEYS::RIGHT] = true;
			break;
		case ALLEGRO_KEY_SPACE:
			if (!player.isJumping && player.touchedGround == true) //wyeliminowanie mozliwosci zrobienia multi jumpu, sprawdzamy czy juz skaczemy albo 													   //czy po poprzednim skoku dotknelismy ziemii
			{
				key[Enums::KEYS::SPACE] = true;
				player.key[Enums::KEYS::SPACE] = true;
				player.touchedGround = false;
			}
			break;

		case ALLEGRO_KEY_ESCAPE:
			gamestate.state = gamestate.END;
			break;
		case ALLEGRO_KEY_LCTRL:
			player.key[Enums::KEYS::LCTRL] = true;
			break;
		case ALLEGRO_KEY_X:
			if(!ult_on_cd)
				player.key[Enums::KEYS::X] = true;
			break;
		}
	}
}

void Game::keyUpEvents(ALLEGRO_EVENT * event)
{
	if (event->type == ALLEGRO_EVENT_KEY_UP) //obsluga klawiszy
	{
		switch (event->keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			key[Enums::KEYS::UP] = false;
			player.key[Enums::KEYS::UP] = false;
			break;
		case ALLEGRO_KEY_DOWN:
			key[Enums::KEYS::DOWN] = false;
			player.key[Enums::KEYS::DOWN] = false;
			break;
		case ALLEGRO_KEY_LEFT:
			player.key[Enums::KEYS::LEFT] = false;
			key[Enums::KEYS::LEFT] = false;
			break;
		case ALLEGRO_KEY_RIGHT:
			player.key[Enums::KEYS::RIGHT] = false;
			key[Enums::KEYS::RIGHT] = false;
			break;
		case ALLEGRO_KEY_SPACE: //na razie niepotrzebne
			key[Enums::KEYS::SPACE] = false;
			player.key[Enums::KEYS::SPACE] = false;
			break;
		}
	}
}

void Game::displayButtonsEvents(ALLEGRO_EVENT * event)
{
	if (event->type == ALLEGRO_EVENT_DISPLAY_CLOSE) // Wylaczanie gry
		gamestate.state = gamestate.END;
}

void Game::mouseEvents(ALLEGRO_EVENT * event)
{
	if (event->type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		mouse_x = event->mouse.x;
		mouse_y = event->mouse.y;
	}
	else if (event->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		switch (gamestate.state)
		{
		case GameState::TITLE:
			if (event->mouse.button == 1)
				for (int i = 0; i < buttons.size(); i++)
					buttons[i]->buttonAction(gamestate.state, mouse_x, mouse_y);
			break;
		case GameState::CTRLS:
			ctrlsScrn.interactiveTextAction(gamestate.state, mouse_x, mouse_y);
			break;
		case GameState::KILLED:
			deadScrn.interactiveTextAction(gamestate.state, mouse_x, mouse_y);
			break;
		case GameState::WON:
			endScrn.interactiveTextAction(gamestate.state, mouse_x, mouse_y);
			break;
		default:
			gamestate.state = gamestate.TITLE;
			break;
		}
			
	}
}

void Game::renderMap()
{
	start_of_rendering = player.GetPosX() / 80 - 12;
	finish_of_rendering = player.GetPosX() / 80 + 13;

	if (start_of_rendering < 0)
		start_of_rendering = 0;
	if (finish_of_rendering>map[0].size())
		finish_of_rendering = map[0].size();

	for (start_of_rendering; start_of_rendering < finish_of_rendering; start_of_rendering++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[j][start_of_rendering]->render(player.getShift());
		}
	}
}

void Game::collidableRenderAndLogic()
{
	if (list_of_spells.size() != 0)
	{
		for (spells_iterator = list_of_spells.begin(); spells_iterator != list_of_spells.end(); ++spells_iterator)
		{
			if ((*spells_iterator)->IDnum() == Enums::IDS::UNACTIVE_SPELL)
			{
				factory.createCollisions.RemoveFromCollisionList(*spells_iterator);
				delete(*spells_iterator);
				list_of_spells.erase(spells_iterator);
				break;
			}
			else
			{
				(*spells_iterator)->update();
				(*spells_iterator)->render(player.getShift());
			}
		}
	}
	//player.render(player.getShift());
	player.renderAnimated(player.getShift());

	renderEnemies();
	
}

void Game::levelOne()
{
	player.resetStuff(); //resetowanie grawitacji i drabiny przed nastepnymi kolizjami
						 //-------------------
	factory.createCollisions.ProcessCollisionList();
	renderMap();
	showstats.renderStats(player.GetPosX() - player.getShift() - 880, player.getScoreCounter()->getScore(), ultimate_skill_cooldown, normal_attack_cooldown);
	collidableRenderAndLogic();

	if (normal_attack_cooldown > 0)
		normal_attack_cooldown--;
	if (ultimate_skill_cooldown > 0)
		ultimate_skill_cooldown--;
	else
		ult_on_cd = 0;
}

void Game::menu()
{
	for (int i = 0; i < buttons.size(); i++)
		buttons[i]->draw(mouse_x, mouse_y);
}

void Game::controls()
{
	ctrlsScrn.draw(mouse_x,mouse_y);
}

void Game::killed()
{
	deadScrn.draw(mouse_x, mouse_y);
	al_draw_textf(endFont, al_map_rgb(186, 0, 0), 100, 100, 0, "Udalo Ci sie zebrac %i punktow...", finalscore);
	al_draw_text(endFont, al_map_rgb(186, 0, 0), WIDTH / 2, HEIGHT - 100, 0, "ALE ZGINALES I MASZ 0!!!!");
}

void Game::end()
{
	endScrn.draw(mouse_x, mouse_y);
	al_draw_textf(endFont, al_map_rgb(255,255, 0), 100, 100, 0, "Udalo Ci sie zebrac %i punktow...", finalscore);
}

void Game::renderAndLogic()
{
	if (redraw && al_is_event_queue_empty(event_queue)) // Czesc odpowiedzialna za renderowanie obrazu
	{
		redraw = false;
		if (gamestate.state == gamestate.LEVEL_1)
			levelOne();
		else if (gamestate.state == gamestate.TITLE)
			menu();
		else if (gamestate.state == gamestate.KILLED)
			killed();
		else if (gamestate.state == gamestate.CTRLS)
			controls();
		else if (gamestate.state == gamestate.WON)
			end();

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 50, 255));
	}
}

void Game::allegroCleaner()
{
	al_stop_timer(timer);
	al_unregister_event_source(event_queue, al_get_display_event_source(display));
	al_unregister_event_source(event_queue, al_get_timer_event_source(timer));
	al_unregister_event_source(event_queue, al_get_keyboard_event_source());
	al_unregister_event_source(event_queue, al_get_mouse_event_source());
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_uninstall_keyboard();
	al_destroy_display(display);
}

void Game::gameLoop()
{
	while (gamestate.state != gamestate.END)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
		renderAndLogic();

		std::thread t([&]() {
			factory.createCollisions.ProcessCollisionList();//KOLIZJE
		});

		std::thread t2([&]() {
			keyDownEvents(&ev);
			keyUpEvents(&ev);
		}); 
		std::thread t3([&]() {
			displayButtonsEvents(&ev);
		}); 
		std::thread t4([&]() {
			mouseEvents(&ev);
		});
		
		t.join();
		t2.join();
		t3.join();
		t4.join();
		timerEvents(&ev);
	}
}

void Game::processEnemyActions()
{
	if (vector_of_enemyObjects.size() != 0)
	{
		int w = vector_of_enemyObjects.size();
		std::vector<EnemyObject*>::iterator it = vector_of_enemyObjects.begin();
		for (it; it != vector_of_enemyObjects.end(); it++)
		{
			RegularTroll * rt;
			OrangeTroll * ot;
			RedTroll * ret;
			if (rt = dynamic_cast<RegularTroll*>(*it))
				rt->loadHP();
			if (ot = dynamic_cast<OrangeTroll*>(*it))
				ot->telepatics(player);
			if (ret = dynamic_cast<RedTroll*>(*it))
				ret->restore();
			(*it)->runToPlayer(player.GetPosX(), player.GetPosY(), player.getBoundY());
			(*it)->gravity();
			(*it)->update();
			(*it)->updateAnimation();
		}
	}
}

void Game::renderEnemies()
{
	if (vector_of_enemyObjects.size() != 0)
	{
		std::vector<EnemyObject*>::iterator it = vector_of_enemyObjects.begin();
		for (it; it != vector_of_enemyObjects.end(); it++)
		{
			(*it)->renderAnimated(player.getShift());
		}
	}
}

Game::~Game()
{
}

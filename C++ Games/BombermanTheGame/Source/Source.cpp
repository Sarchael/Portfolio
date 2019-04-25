#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Includs.h"


int main()
{

	
	int WIDTH = 1050; // szerokosc okna
	int HEIGHT = 1050; // wysokosc okna
	bool done = false; // zmienna odpowiadajaca za powtarzanie sie petli gry
	int key[5] = { false,false,false,false,false }; // zmienne okreslajace czy dany klawisz jest wcisniety

	bool redraw = true; // zapewnia renderowanie w 60 FPSach
	const int FPS = 60; // ustawia ilosc FPS
	int state = -1; // okresla stan gry

	if (!al_init())
	{
		return -1;
	}

	ALLEGRO_DISPLAY * display = al_create_display(WIDTH, HEIGHT); // tworzenie okna
	al_set_window_title(display, "Bomberman");

	if (!display)
	{
		return -1;
	}

	al_init_image_addon(); // zeby dzialaly obrazki
	al_install_keyboard(); // zeby dzialaly klawisze

	Bitmaps bitmaps = Bitmaps();
	Player player = Player(bitmaps);
	Map map = Map(bitmaps);
	Enemies enemy[3] = { Enemies(bitmaps, 1), Enemies(bitmaps, 1), Enemies(bitmaps, 1) };
	Bomb bomb[3] = { Bomb(bitmaps), Bomb(bitmaps), Bomb(bitmaps) };
	Explosion exp[3] = { Explosion(bitmaps), Explosion(bitmaps), Explosion(bitmaps) };
	Interactions guardian;

	ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue(); // tworzenie kolejki
	ALLEGRO_TIMER * timer = al_create_timer(1.0 / FPS); // tworzeie timera
	srand(time(NULL)); // generowanie liczb pseudolosowych

	guardian.ChangeState(player, map, enemy, bomb, exp, state, TITLE, bitmaps);

	al_register_event_source(event_queue, al_get_keyboard_event_source()); //okreslenie jakie zdarzenia maj¹ byæ brane do kolejki zdarzen
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_start_timer(timer);

	while (!done) // petla gry
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) // funkcje odpowiedzialne za mechanike gry dzialajace w 60FPSach
		{
			redraw = true;

			if (key[UP])
				player.MovePlayerUp(bomb, map);
			if (key[DOWN])
				player.MovePlayerDown(bomb, map, HEIGHT);
			if (key[LEFT])
				player.MovePlayerLeft(bomb, map);
			if (key[RIGHT])
				player.MovePlayerRight(bomb, map, WIDTH);

			if (state == PLAYING)
			{
				player.UpdatePlayer();
				
					bomb[0].UpdateBomb(exp, map, bitmaps);
					bomb[1].UpdateBomb(exp, map, bitmaps);
					bomb[2].UpdateBomb(exp, map, bitmaps);
					enemy[0].MoveEnemies(map);
					enemy[1].MoveEnemies(map);
					enemy[2].MoveEnemies(map);
					exp[0].UpdateExplosion(bomb, map, bitmaps);
					exp[1].UpdateExplosion(bomb, map, bitmaps);
					exp[2].UpdateExplosion(bomb, map, bitmaps);

				guardian.DestroyEnemy(enemy, map, player);
				guardian.SelfKill(player, map, enemy, bomb, exp, state, bitmaps);
				guardian.EnemyKill(player, map, enemy, bomb, exp, state, bitmaps);
				guardian.EndGame(player, map, enemy, bomb, exp, state, bitmaps);
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) //obsluga klawiszy
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				key[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[RIGHT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				key[SPACE] = true;

				for (int i = 0; i < 3; i++)
				{
					if (bomb[i].ActiveBomb(player, map))
						break;
				}

			case ALLEGRO_KEY_ENTER:
				if (state == TITLE)
					guardian.ChangeState(player, map, enemy, bomb, exp, state, PLAYING, bitmaps);
				else if (state == SKILL)
					guardian.ChangeState(player, map, enemy, bomb, exp, state, PLAYING, bitmaps);
				else if (state == EKILL)
					guardian.ChangeState(player, map, enemy, bomb, exp, state, PLAYING, bitmaps);
				else if (state == WIN)
					guardian.ChangeState(player, map, enemy, bomb, exp, state, PLAYING, bitmaps);
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) //obsluga klawiszy
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				key[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				key[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[RIGHT] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				key[SPACE] = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) // Wylaczanie gry
		{
			done = true;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) // Czesc odpowiedzialna za renderowanie obrazu
		{
			redraw = false;

			if (state == TITLE)
			{
				al_draw_bitmap(bitmaps.getStart(), 0, 0, 0);
			}
			else if (state == PLAYING)
			{
				map.DrawHandicaps(bitmaps);
				map.DrawMap();
				bomb[0].DrawBomb();
				bomb[1].DrawBomb();
				bomb[2].DrawBomb();
				player.DrawPlayer();
				enemy[0].DrawEnemies();
				enemy[1].DrawEnemies();
				enemy[2].DrawEnemies();
				exp[0].DrawExplosion(map);
				exp[1].DrawExplosion(map);
				exp[2].DrawExplosion(map);
			}
			else if (state == SKILL)
			{
				al_draw_bitmap(bitmaps.getSelf(), 0, 0, 0);
			}
			else if (state == EKILL)
			{
				al_draw_bitmap(bitmaps.getMurd(), 0, 0, 0);
			}
			else if (state == WIN)
			{
				al_draw_bitmap(bitmaps.getWin(), 0, 0, 0);
			}

			al_flip_display();
			map.Background(bitmaps);
		}
	}

	
	al_stop_timer(timer);
	al_unregister_event_source(event_queue, al_get_display_event_source(display));
	al_unregister_event_source(event_queue, al_get_timer_event_source(timer));
	al_unregister_event_source(event_queue, al_get_keyboard_event_source());
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_uninstall_keyboard();
	al_destroy_display(display);



	return 0;
}
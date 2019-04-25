#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Includs.h"


void Interactions::DestroyEnemy(Enemies * enemy, Map & map, Player & player)
{
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i].GetLife())
		{
			for (int j = 1; j < 14; j++)
			{
				for (int k = 1; k < 14; k++)
				{
					if (map.retMap()[j][k].explosion == 1)
					{
						if (map.WhereIAm(enemy[i].GetEX(), enemy[i].GetEY()) == &map.retMap()[j][k])
						{
							enemy[i].SetLife(0);
							player.IncScr();
						}
					}
				}
			}
		}
	}
}
void Interactions::SelfKill(Player & player, Map & map, Enemies * enemy, Bomb * bomb, Explosion * exp, int & state, Bitmaps & img)
{
	for (int j = 1; j < 14; j++)
	{
		for (int k = 1; k < 14; k++)
		{
			if (map.retMap()[j][k].explosion == 1)
			{
				if (map.WhereIAm(player.GetPX(), player.GetPY()) == &map.retMap()[j][k])
				{
					//player->life = 0;
					ChangeState(player, map, enemy, bomb, exp, state, SKILL, img);
				}
			}
		}
	}
}
void Interactions::EnemyKill(Player & player, Map & map, Enemies * enemy, Bomb * bomb, Explosion * exp, int & state, Bitmaps & img)
{
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i].GetLife())
		{
			if (enemy[i].GetEX() - enemy[i].GetEbX() < player.GetPX() + player.GetPbX() && enemy[i].GetEX() + enemy[i].GetEbX() >player.GetPX() - player.GetPbX()
				&& enemy[i].GetEY() - enemy[i].GetEbY() < player.GetPY() + player.GetPbY() && enemy[i].GetEY() + enemy[i].GetEbY() >player.GetPY() - player.GetPbY())
			{
				//player->life = 0;
				ChangeState(player, map, enemy, bomb, exp, state, EKILL, img);
			}
		}
	}
}
void Interactions::EndGame(Player & player, Map & map, Enemies * enemy, Bomb * bomb, Explosion * exp, int & state, Bitmaps & img)
{
	if (player.GetScr() == 3 && map.WhereIAm(player.GetPX(), player.GetPY())->handicap == 2)
		ChangeState(player, map, enemy, bomb, exp, state, WIN, img);
}
void Interactions::ChangeState(Player & player, Map & map, Enemies * enemy, Bomb * bomb, Explosion * exp, int & state, int newState, Bitmaps & img)
{
	state = newState;
	if (state == PLAYING)
	{
		map = Map(img);
		player = Player(img);
		for (int i = 0; i < 3; i++)
		{
			enemy[i] = Enemies(img, i + 1);
			bomb[i] = Bomb(img);
			exp[i] = Explosion(img);
		}
		bomb[0].SetLife(1);
	}
}
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Includs.h"


Field** Map::retMap()
{
	return map;
}


void Map::Background(Bitmaps & background)
{
	al_draw_bitmap(background.getBackground(), 0, 0, 0);
}
Map::Map(Bitmaps & img)
{

	map = new Field* [16];
	for (int i = 0; i < 16; i++)
	{
		map[i] = new Field[16];
	}

	map[1][5].type = CHEST;
	map[1][7].type = CHEST;
	map[1][8].type = CHEST;
	map[1][11].type = CHEST;
	map[2][3].type = CHEST;
	map[2][7].type = CHEST;
	map[2][11].type = CHEST;
	map[3][1].type = CHEST;
	map[3][7].type = CHEST;
	map[3][8].type = CHEST;
	map[3][4].type = CHEST;
	map[4][5].type = CHEST;
	map[4][3].type = CHEST;
	map[4][9].type = CHEST;
	map[4][13].type = CHEST;
	map[5][7].type = CHEST;
	map[5][8].type = CHEST;
	map[5][10].type = CHEST;
	map[5][1].type = CHEST;
	map[5][2].type = CHEST;
	map[5][3].type = CHEST;
	map[5][4].type = CHEST;
	map[5][6].type = CHEST;
	map[6][1].type = CHEST;
	map[6][11].type = CHEST;
	map[6][5].type = CHEST;
	map[6][3].type = CHEST;
	map[6][13].type = CHEST;
	map[7][8].type = CHEST;
	map[7][11].type = CHEST;
	map[7][4].type = CHEST;
	map[7][7].type = CHEST;
	map[7][1].type = CHEST;
	map[7][9].type = CHEST;
	map[7][12].type = CHEST;
	map[7][13].type = CHEST;
	map[8][3].type = CHEST;
	map[8][11].type = CHEST;
	map[8][9].type = CHEST;
	map[8][7].type = CHEST;
	map[8][13].type = CHEST;
	map[9][2].type = CHEST;
	map[9][5].type = CHEST;
	map[9][7].type = CHEST;
	map[9][8].type = CHEST;
	map[9][3].type = CHEST;
	map[9][6].type = CHEST;
	map[10][7].type = CHEST;
	map[10][3].type = CHEST;
	map[10][11].type = CHEST;
	map[10][5].type = CHEST;
	map[11][6].type = CHEST;
	map[11][8].type = CHEST;
	map[11][11].type = CHEST;
	map[11][10].type = CHEST;
	map[11][12].type = CHEST;
	map[12][7].type = CHEST;
	map[12][11].type = CHEST;
	map[13][6].type = CHEST;
	map[13][7].type = CHEST;
	map[13][8].type = CHEST;

	int handis = 2;
	int door = 1;

	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			map[i][j].x = i * 70;
			map[i][j].y = j * 70;
			map[i][j].handicap = 0;
			map[i][j].explosion = 0;

			if ((i % 2 == 0) && (j % 2 == 0))
			{
				map[i][j].type = WALL;
				map[i][j].image = img.getWallImage();
			}
			else if (map[i][j].type == CHEST)
			{
				map[i][j].image = img.getChestImage();
			}
			else
			{
				map[i][j].type = GRASS;
				map[i][j].image = img.getNth();
			}

			if (rand() % 20 == 0 && handis > 0 && map[i][j].type == CHEST)
			{
				map[i][j].handicap = 1;
				handis--;
			}
		}
	}

	while (door)
	{
		for (int m = 1; m < 14; m++)
		{
			for (int n = 1; n < 14; n++)
			{
				if (rand() % 30 == 0 && door > 0 && map[m][n].type == CHEST && map[m][n].handicap == 0)
				{
					map[m][n].handicap = 2;
					door--;
				}
			}
		}
	}

	for (int k = 0; k < 15; k++)
	{
		map[0][k].x = 0;
		map[0][k].y = k * 70;
		map[0][k].handicap = 0;
		map[0][k].image = img.getNth();
		map[0][k].explosion = 0;
		map[0][k].type = WALL;
		map[14][k].x = 980;
		map[14][k].y = k * 70;
		map[14][k].handicap = 0;
		map[14][k].explosion = 0;
		map[14][k].image = img.getNth();
		map[14][k].type = WALL;
	}
	for (int l = 1; l < 14; l++)
	{
		map[l][0].x = l * 70;
		map[l][0].y = 0;
		map[l][0].handicap = 0;
		map[l][0].explosion = 0;
		map[l][0].image = img.getNth();
		map[l][0].type = WALL;
		map[l][14].x = l * 70;
		map[l][14].y = 980;
		map[l][14].handicap = 0;
		map[l][14].explosion = 0;
		map[l][14].image = img.getNth();
		map[l][14].type = WALL;
	}
}
Field * Map::WhereIAm(int x, int y)
{
	return &map[x / 70][y / 70];
}

void Map::DrawMap()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (map[i][j].type == WALL || map[i][j].type == CHEST)
				al_draw_bitmap(map[i][j].image, map[i][j].x, map[i][j].y, 0);
		}
	}
}

void Map::DrawHandicaps(Bitmaps & images)
{
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			if (map[i][j].handicap == 1)
			{
				al_draw_bitmap(images.getInaBombImage(), map[i][j].x, map[i][j].y, 0);
			}
			else if (map[i][j].handicap == 2)
			{
				al_draw_bitmap(images.getDoorImage() , map[i][j].x, map[i][j].y, 0);
			}
		}
	}
}
#pragma once
class GameState
{
public:
	int state;
	static enum GAME_STATE { LEVEL_1, TITLE, KILLED, END, CTRLS, WON };
	GameState();
	~GameState();
};


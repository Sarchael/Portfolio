#pragma once
class Enums
{
public:
	static enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE, LCTRL, X, COUNT }; //COUNT MUSI BYC NA KONCU!!!!
	static enum IDS { PLAYER, ENEMY, PLATFORM, LADDER, SPIKES, GHOST, TRAP, CHEST, DOOR, NORMAL_ATTACK, ULTIMATE_SKILL, UNACTIVE_SPELL, NTH };//do uzupelnienia
	//static enum GAME_STATE { LEVEL_1, TITLE, KILLED, END, CTRLS };
	static enum FIXED_ID { EXIT, NEW_GAME, CONTROLS, LOAD };
	Enums();
	~Enums();
};


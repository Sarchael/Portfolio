#pragma once
class Physics
{
public:
	Physics();
	//zmienne dla fizyki
	bool gravityOn = true;
	int jumpCount = 0;
	int jumpDelay = 3;//4
	int maxJump = 4;//8
	int curJump = 0;
	bool touchedGround = true;
	bool isJumping = false;

	//funkcje
	virtual void gravity()=0;
	virtual void jumpUpdate()=0;
	virtual void jumpReset() = 0;
	~Physics();
};


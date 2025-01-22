#pragma once
#include "Object.h"
#include <Novice.h>
#include "Bullet.h"

class Player : protected Object
{
public:
	Bullet* bullet;
public:
	Player();
	~Player();
	void Update(char *keys, char *preKeys);
	void Draw();
};


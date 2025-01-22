#pragma once
#include "Object.h"
#include <Novice.h>

class Enemy : protected Object
{
public:
	virtual ~Enemy() {};
	virtual void Update(Vector2  bulletPos, float bulletRadius);
	virtual void Draw() {};
	virtual void Reset(char* keys, char* preKeys);
protected:
	static int isAlive;
};


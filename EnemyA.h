#pragma once
#include "Enemy.h"

class EnemyA : public Enemy
{
public:
	EnemyA();
	void Update(Vector2  bulletPos, float bulletRadius) override;
	void Draw() override;
	void Reset(char *keys, char *preKeys) override;
};


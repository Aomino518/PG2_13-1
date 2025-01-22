#pragma once
#include "Enemy.h"

class EnemyB : public Enemy
{
public:
	EnemyB();
	void Update(Vector2  bulletPos, float bulletRadius) override;
	void Draw() override;
	void Reset(char *keys, char *preKeys) override;
};

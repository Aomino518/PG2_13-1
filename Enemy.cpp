#include "Enemy.h"
#include <Novice.h>

void Enemy::Reset(char* keys, char* preKeys) {
	if (!isAlive) {
		if (keys[DIK_R] && !preKeys[DIK_R]) {
			isAlive = true;
		}
	}
}
void Enemy::Update(Vector2 bulletPos, float bulletRadius)
{
	bulletPos;
	bulletRadius;
}
#include "EnemyA.h"
#include <Novice.h>
#include "Bullet.h"
#include "Hit.h"

EnemyA::EnemyA() {
	pos = { 300.0f, 400.0f };
	speed = 8.0f;
	radius = 15.0f;
	isAlive = true;
}


void EnemyA::Update(Vector2 bulletPos, float bulletRadius) {
	if (isAlive) {
		pos.x += speed;

		if (pos.x <= 15.0f || pos.x >= 1265.0f) {
			speed *= -1;
		}

		if (Hit(pos, radius, bulletPos, bulletRadius)) {
			isAlive = false;
		}
	}
}

void EnemyA::Draw() {
	if (isAlive) {
		Novice::DrawEllipse(
			static_cast<int>(pos.x),
			static_cast<int>(pos.y),
			static_cast<int>(radius),
			static_cast<int>(radius),
			0.0f,
			RED,
			kFillModeSolid
		);
	}
}

void EnemyA::Reset(char *keys, char *preKeys) {
	if (!isAlive) {
		if (keys[DIK_R] && !preKeys[DIK_R]) {
			isAlive = true;
		}
	}
}

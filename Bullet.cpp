#include "Bullet.h"
#include <Novice.h>
#include <math.h>

Bullet::Bullet() {
	pos = { 0.0f, 0.0f };
	radius_ = 15.0f;
	speed = 8.0f;
	isShot = false;
}

void Bullet::Update() {
	if (isShot) {
		pos.y -= speed;

		if (pos.y <= 0.0f) {
			isShot = false;
		}
	}
}

void Bullet::Draw() {
	if (isShot) {
		Novice::DrawEllipse(
			static_cast<int>(pos.x),
			static_cast<int>(pos.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f,
			WHITE,
			kFillModeSolid
		);
	}
}

void Bullet::SetPos(float x, float y) {
	pos.x = x;
	pos.y = y;
}

void Bullet::SetIsShot(int judge) {
	isShot = judge;
}
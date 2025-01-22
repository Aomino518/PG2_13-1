#include "Player.h"

Player::Player() {
	pos = { 640.0f, 650.0f };
	speed = 5.0f;
	radius = 20.0f;
	isActive = true;
	bullet = new Bullet();
}

Player::~Player() {
	delete bullet;
}

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		pos.y -= speed;
	}

	if (keys[DIK_S]) {
		pos.y += speed;
	}

	if (keys[DIK_A]) {
		pos.x -= speed;
	}

	if (keys[DIK_D]) {
		pos.x += speed;
	}

	if (!bullet->GetIsShot()) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			bullet->SetPos(pos.x, pos.y);
			bullet->SetIsShot(true);
		}
	}

	bullet->Update();
}

void Player::Draw() {
	bullet->Draw();
	Novice::DrawEllipse(
		static_cast<int>(pos.x),
		static_cast<int>(pos.y),
		static_cast<int>(radius),
		static_cast<int>(radius),
		0.0f,
		GREEN,
		kFillModeSolid
	);
}

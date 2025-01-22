#pragma once
#include "Object.h"

class Bullet
{
private:
	Vector2 pos;
	float speed;
	float radius_;
	int isShot;

public:
	Bullet();
	void Update();
	void Draw();
	Vector2 GetPos() { return pos; }
	float GetRadius() { return radius_; }
	int GetIsShot() { return isShot; }
	void SetPos(float x, float y);
	void SetIsShot(int judge);
};


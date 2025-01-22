#pragma once

struct Vector2 {
	float x, y;
};

class Object {
protected:
	Vector2 pos;
	float speed;
	float radius;
	int isActive;
};

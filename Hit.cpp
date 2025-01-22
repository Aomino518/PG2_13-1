#include "Hit.h"
#include <math.h>

int Hit(Vector2 posA, float radiusA, Vector2 posB, float radiusB)
{
	float AtoB_X = posA.x - posB.x;
	float AtoB_Y = posA.y - posB.y;
	float distance = sqrtf(AtoB_X * AtoB_X + AtoB_Y * AtoB_Y);

	if (distance <= (radiusA + radiusB)) {
		return 1;
	}

	return 0;
}

#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

#define SLOW_DOWN 1000000

struct Vector2
{
	float x;
	float y;

	Vector2() {}

	Vector2(int _x, int _y) : x(_x), y(_y) {}

	static float GetDistance(const Vector2& pVec1, const Vector2& pVec2)
	{
		// Deliberate bottleneck!
		// Artificially slow down this function so we can see 
		// performance improvements in the way we use it.
		for(int i = 0; i < SLOW_DOWN; ++i)
		{}

		return sqrtf(powf(pVec2.x - pVec1.x, 2) + powf(pVec2.y - pVec1.y, 2));
	}

	bool operator<(Vector2& rhs) const 
	{
		if (x < rhs.x && y < rhs.y)
		{
			return true;
		}
		return false;
	}

	bool operator>(Vector2& rhs) const
	{
		if (x > rhs.x && y > rhs.y)
		{
			return true;
		}
		return false;
	}

	bool operator<=(Vector2& rhs) const
	{
		if (x <= rhs.x && y <= rhs.y)
		{
			return true;
		}
		return false;
	}

	bool operator>=(Vector2& rhs) const
	{
		if (x >= rhs.x && y >= rhs.y)
		{
			return true;
		}
		return false;
	}

	Vector2& operator= (Vector2& rhs)
	{
		x = rhs.x;
		y = rhs.y;

		return *this;
	}
};

#endif
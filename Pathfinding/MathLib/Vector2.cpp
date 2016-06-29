#include "Vector2.h"
#include <math.h>



Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}


Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(Vector2 & rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}


Vector2 Vector2::operator-(Vector2 & rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(float rhs) const
{
	return Vector2(x*rhs, y*rhs);
}

Vector2 Vector2::lerp(Vector2 vec1, Vector2 vec2, float t)
{
	return (1 - t)*vec1 + t*vec2;
}

bool Vector2::operator==(Vector2 & rhs)
{
	if (x == rhs.x && y == rhs.y)
		return true;
	return false;
}

Vector2::operator float*()
{
	return (float*)this;
}

float Vector2::dot(Vector2 vec)
{
	return x * vec.x + y * vec.y;
}

float Vector2::magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector2::distance(Vector2 & rhs)
{
	return sqrt(pow(x - rhs.x, 2) + pow(y - rhs.y, 2));
}

Vector2 Vector2::normalise()
{
	float mag = magnitude();

	x /= mag;
	y /= mag;

	return *this;
}

Vector2 operator*(float lhs, Vector2 & rhs)
{
	return Vector2(rhs.x * lhs, rhs.y * lhs);
}

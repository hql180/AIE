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

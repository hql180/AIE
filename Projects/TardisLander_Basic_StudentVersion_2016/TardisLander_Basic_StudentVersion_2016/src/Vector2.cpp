#include "Vector2.h"
#include <math.h>



Vector2::Vector2()
{
}

Vector2::Vector2(float x, float y)
{
	m_x = x;
	m_y = y;
}


Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(Vector2 & rhs) const
{
	return Vector2(m_x + rhs.m_x, m_y + rhs.m_y);
}


Vector2 Vector2::operator-(Vector2 & rhs) const
{
	return Vector2(m_x - rhs.m_x, m_y - rhs.m_y);
}

Vector2 Vector2::operator*(float & rhs) const
{
	return Vector2(m_x*rhs, m_y*rhs);
}

Vector2 & Vector2::operator+=(Vector2 & rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector2 & Vector2::operator-=(Vector2 & rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector2 & Vector2::operator*=(float rhs)
{
	*this = *this * rhs;
	return *this;
}

Vector2::operator float*()
{
	float arr[2] = { m_x, m_y };

	return arr;
}

float Vector2::dot(Vector2 vec)
{
	return m_x * vec.m_x + m_y * vec.m_y;
}

float Vector2::magnitude()
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

Vector2 Vector2::normalise()
{
	float mag = magnitude();

	m_x /= mag;
	m_y /= mag;

	return *this;
}

Vector2 operator*(float & lhs, Vector2 & rhs)
{
	return Vector2(rhs.m_x * lhs, rhs.m_y*lhs);
}

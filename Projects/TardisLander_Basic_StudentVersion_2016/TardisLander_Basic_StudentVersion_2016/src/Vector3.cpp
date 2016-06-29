#include "Vector3.h"
#include <math.h>


Vector3::Vector3()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}


Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(Vector3 & rhs) const
{
	return Vector3(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z);
}

Vector3 Vector3::operator-(Vector3 & rhs) const
{
	return Vector3(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z);
}

Vector3 Vector3::operator*(float & rhs) const
{
	return Vector3(m_x*rhs, m_y*rhs, m_z * rhs);
}

Vector3 & Vector3::operator+=(Vector3 & rhs)
{
	*this = *this + rhs;

	return *this;
}

Vector3 & Vector3::operator-=(Vector3 & rhs)
{
	*this = *this - rhs;

	return *this;
}

Vector3 & Vector3::operator*=(float rhs)
{
	*this = *this * rhs;

	return *this;
}


Vector3::operator float*()
{
	float arr[3] = { m_x, m_y, m_z };

	return arr;
}

float Vector3::dot(Vector3 vec)
{
	return m_x * vec.m_x + m_y * vec.m_y + m_z * vec.m_z;
}

Vector3 Vector3::cross(Vector3 vec)
{
	return Vector3(m_y*vec.m_z - m_z*vec.m_y, m_z*vec.m_x - m_x*vec.m_z, m_x*vec.m_y - m_y*vec.m_x);
}

float Vector3::magnitude()
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
}

Vector3 Vector3::normalise()
{
	float mag = magnitude();

	m_x /= mag;
	m_y /= mag;
	m_z /= mag;

	return *this;
}

Vector3 operator*(float & lhs, Vector3 & rhs)
{
	return Vector3(rhs.m_x * lhs, rhs.m_y*lhs, rhs.m_z*lhs);
}

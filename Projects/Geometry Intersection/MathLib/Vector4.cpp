#include "Vector4.h"
#include <math.h>



Vector4::Vector4()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_w = 0;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_w = w;
}


Vector4::~Vector4()
{
}

Vector4 Vector4::operator+(Vector4 & rhs) const
{
	return Vector4(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z, m_w + rhs.m_w);
}

Vector4 Vector4::operator-(Vector4 & rhs) const
{
	return Vector4(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z, m_w - rhs.m_w);
}

Vector4 Vector4::operator*(float rhs) const
{
	return Vector4(m_x * rhs, m_y * rhs, m_z * rhs, m_w * rhs);
}

Vector4::operator float*()
{
	return (float*)this;
}

float Vector4::dot(Vector4 vec)
{
	return m_x * vec.m_x + m_y * vec.m_y + m_z * vec.m_z + m_w*vec.m_w;
}

Vector4 Vector4::cross(Vector4 vec)
{
	return Vector4(m_y*vec.m_z - m_z*vec.m_y,
					m_z*vec.m_x - m_x*vec.m_z,
					m_x*vec.m_y - m_y*vec.m_x, 
					0);
}

float Vector4::magnitude()
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2) + pow(m_w, 2));
}

Vector4 Vector4::normalise()
{
	float mag = magnitude();

	m_x /= mag;
	m_y /= mag;
	m_z /= mag;
	m_w /= mag;

	return *this;
}

Vector4 operator*(float lhs, Vector4 & rhs)
{
	return Vector4(rhs.m_x * lhs, rhs.m_y*lhs, rhs.m_z*lhs, rhs.m_w * lhs);
}

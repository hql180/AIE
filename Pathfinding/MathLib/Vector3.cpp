#include "Vector3.h"
#include <math.h>


Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}


Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(Vector3 & rhs) const
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 Vector3::operator-(Vector3 & rhs) const
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::operator*(float rhs) const
{
	return Vector3(x*rhs, y*rhs, z * rhs);
}

Vector3::operator float*()
{
	return (float*)this;
}

float Vector3::dot(Vector3 vec)
{
	return x * vec.x + y * vec.y + z * vec.z;
}

Vector3 Vector3::cross(Vector3 vec)
{
	return Vector3(y*vec.z - z*vec.y,
					z*vec.x - x*vec.z, 
					x*vec.y - y*vec.x);
}

float Vector3::magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3 Vector3::normalise()
{
	float mag = magnitude();

	x /= mag;
	y /= mag;
	z /= mag;

	return *this;
}

Vector3 Vector3::normalise(Vector3 vec)
{
	return Vector3();
}

Vector3 operator*(float lhs, Vector3 & rhs)
{
	return Vector3(rhs.x * lhs, rhs.y*lhs, rhs.z*lhs);
}

#include "Vector3.h"
#include <math.h>
#include <algorithm>


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

Vector3::Vector3(Vector3 &rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
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

float Vector3::magnitude(Vector3 vec)
{
	Vector3 temp = vec;
	return temp.magnitude();
}

Vector3 Vector3::normalise()
{
	
	float mag = magnitude();

	if (mag != 0)
	{
		x /= mag;
		y /= mag;
		z /= mag;

		return *this;
	}
}

Vector3 Vector3::normalise(Vector3 vec)
{
	return vec.normalise();
}

Vector3 Vector3::clamp(Vector3 &vec, Vector3 lower, Vector3 upper)
{
	Vector3 minX;
	Vector3 maxX;
	Vector3 minY;
	Vector3 maxY;

	if (lower.x < upper.x)
	{
		minX = lower;
		maxX = upper;
	}
	else
	{
		minX = upper;
		maxX = lower;
	}
	if (lower.y < upper.y)
	{
		minY = lower;
		maxY = upper;
	}
	else
	{
		minY = upper;
		maxY = lower;
	}
	

	if (vec.x > maxX.x)
		return vec = maxX;

	else if (vec.x < minX.x)
		return vec = minX;
	else if (vec.y > maxY.y)
		return vec = maxY;
	else if (vec.y < minY.y)
		return vec = minY;

	return vec;
}

int Vector3::clamp(float value, float min, float max)
{
	if (value < min)
		return min;
	else if (value > max)
		return max;
	return value;
}



Vector3 operator*(float lhs, Vector3 & rhs)
{
	return Vector3(rhs.x * lhs, rhs.y*lhs, rhs.z*lhs);
}

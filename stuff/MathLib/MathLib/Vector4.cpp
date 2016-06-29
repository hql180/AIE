#include "Vector4.h"
#include <math.h>



Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(float a_x, float a_y, float a_z, float a_w)
{
	x = a_x;
	y = a_y;
	z = a_z;
	w = a_w;
}


Vector4::~Vector4()
{
}

Vector4 Vector4::operator+(Vector4 & rhs) const
{
	return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

Vector4 Vector4::operator-(Vector4 & rhs) const
{
	return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Vector4 Vector4::operator*(float rhs) const
{
	return Vector4(x * rhs, y * rhs, z * rhs, w * rhs);
}

Vector4::operator float*()
{
	return (float*)this;
}

float Vector4::dot(Vector4 vec)
{
	return x * vec.x + y * vec.y + z * vec.z + w*vec.w;
}

Vector4 Vector4::cross(Vector4 vec)
{
	return Vector4(y*vec.z - z*vec.y,
					z*vec.x - x*vec.z,
					x*vec.y - y*vec.x, 
					0);
}

float Vector4::magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}

Vector4 Vector4::normalise()
{
	float mag = magnitude();

	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;

	return *this;
}

Vector4 operator*(float lhs, Vector4 & rhs)
{
	return Vector4(rhs.x * lhs, rhs.y*lhs, rhs.z*lhs, rhs.w * lhs);
}

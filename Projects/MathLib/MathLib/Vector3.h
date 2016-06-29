#pragma once
class Vector3
{
public:
	Vector3(); // Sets all values to zero by default
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3 operator + (Vector3& rhs) const; // Returns addition result

	Vector3 operator - (Vector3& rhs) const; // Returns subtraction result

	Vector3 operator * (float rhs) const; // Returns multiplication result

	friend Vector3 operator*(float lhs, Vector3& rhs); // Overloads multiplaction operator to work with float first

	operator float*(); // Casts to float pointer

	float dot(Vector3 vec); // Returns dot product

	Vector3 cross(Vector3 vec); // Returns cross product

	float magnitude(); // Returns length/magnitude

	Vector3 normalise(); // normlises vector

	float m_x, m_y, m_z;
};


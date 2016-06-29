#pragma once
class Vector4
{
public:
	Vector4(); // Sets all values to zero by default
	Vector4(float x, float y, float z, float w);
	~Vector4();

	Vector4 operator + (Vector4& rhs) const; // Returns addition result

	Vector4 operator - (Vector4& rhs) const; // Returns subtraction result

	Vector4 operator * (float rhs) const; // Returns multiplication result

	friend Vector4 operator*(float lhs, Vector4& rhs); // Overloads multiplaction operator to work with float first

	operator float*(); // Casts to float pointer

	float dot(Vector4 vec); // Returns dot product

	Vector4 cross(Vector4 vec); // Returns cross product

	float magnitude(); // Returns length/magnitude

	Vector4 normalise(); // normlises vector	

	float m_x, m_y, m_z, m_w;
};


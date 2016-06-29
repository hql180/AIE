#pragma once
class Vector2
{
public:

	Vector2(); // Sets all values to zero by default

	Vector2(float x, float y);

	~Vector2();

	Vector2 operator + (Vector2& rhs) const; // Returns copy of addition result

	Vector2 operator - (Vector2& rhs) const; // Returns copy of subtraction result

	Vector2 operator * (float rhs) const; // Returns copy of multiplication result

	friend Vector2 operator*(float lhs, Vector2& rhs); // Overload * to work with float first

	operator float*(); // Casts to float pointer

	float dot(Vector2 vec); // Returns dot product

	float magnitude(); // Returns length/magnitude

	Vector2 normalise(); // Normalise self
	
	float m_x, m_y;
};




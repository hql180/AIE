#pragma once
class Vector3
{
public:
	Vector3(); // Sets all values to zero by default
	Vector3(float a_x, float a_y, float a_z);
	Vector3(Vector3 &rhs);
	~Vector3();

	Vector3 operator + (Vector3& rhs) const; // Returns addition result

	Vector3 operator - (Vector3& rhs) const; // Returns subtraction result

	Vector3 operator * (float rhs) const; // Returns multiplication result

	friend Vector3 operator*(float lhs, Vector3& rhs); // Overloads multiplaction operator to work with float first

	operator float*(); // Casts to float pointer

	float dot(Vector3 vec); // Returns dot product

	Vector3 cross(Vector3 vec); // Returns cross product

	float magnitude(); // Returns length/magnitude

	static float magnitude(Vector3 vec);

	Vector3 normalise(); // normlises vector

	static Vector3 normalise(Vector3 vec);

	static Vector3 normalise(Vector3 vec1, Vector3 vec2);

	Vector3 clamp(Vector3 &vec, Vector3 lower, Vector3 upper);

	int clamp(float value, float min, float max);

	float x, y, z;
};


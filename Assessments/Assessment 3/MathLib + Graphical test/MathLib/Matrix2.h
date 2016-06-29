#pragma once

#include "Vector2.h"

class Matrix2
{
public:
	Matrix2(); // Sets all values to zero by default
	Matrix2(float a, float b, float c, float d); // Input as row major then transposes to column
	Matrix2(Matrix2 &original);
	~Matrix2();

	static Matrix2 CreateIdentity(); // Creates New Idenity Matrix

	Matrix2& Transpose(); // Transposes current matrix

	Matrix2 GetTranspose(); // Returns a transposed copy of current matrix

	Matrix2 operator + (Matrix2& RHS); // Returns copy of add result

	Matrix2 operator - (Matrix2& rhs); // Returns copy of subtract result

	Matrix2 operator * (Matrix2& rhs); // Returns copy of multication result

	Vector2 operator*(Vector2& rhs); // Transform into Vector2

	operator float*(); // Casts to float pointer

	Matrix2 setRotateZ(float rad); // Sets Rotation


	float m[2][2];
};


#pragma once

#include "Vector4.h"

class Matrix4
{
public:
	Matrix4(); // Sets all values to zero by default
	Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p); // Input as row major then transposes to column
	Matrix4(Matrix4 &original);
	~Matrix4();

	static Matrix4 CreateIdentity(); // Creates New Idenity Matrix

	Matrix4& Transpose(); // Transposes current matrix

	Matrix4 GetTranspose(); // Returns a transposed copy of current matrix

	Matrix4 operator + (Matrix4& RHS); // Returns copy of add result

	Matrix4 operator - (Matrix4& rhs); // Returns copy of subtract result

	Matrix4 operator * (Matrix4& rhs); // Returns copy of multication result

	Vector4 operator*(Vector4& rhs);  // Transforms to Vector

	operator float*(); // Float pointer cast

	Matrix4 setRotateX(float rad);

	Matrix4 setRotateY(float rad);

	Matrix4 setRotateZ(float rad);
	
	float m[4][4];
};


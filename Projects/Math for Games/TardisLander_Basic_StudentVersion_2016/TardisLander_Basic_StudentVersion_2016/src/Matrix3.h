#pragma once

#include "Vector3.h"

class Matrix3 // Row Major just transpose for column major
{
public:
	Matrix3();

	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);

	Matrix3(Matrix3 &original);
	~Matrix3();

	static Matrix3 CreateIdentity(); // Creates New Idenity Matrix

	static Matrix3 CreateRotation(float radians);

	static Matrix3 CreateScale(Vector3& scale);

	static Matrix3 CreateTranslation(Vector3& transation);

	static Matrix3 CreateTranslation(float x, float y, float z = 1.0f);

	Matrix3& Transpose(); // Transposes current matrix

	Matrix3 GetTranspose(); // Returns a transposed copy of current matrix

	Matrix3 operator + (Matrix3& RHS); // Returns copy of add result

	Matrix3 operator - (Matrix3& rhs); // Returns copy of subtract result

	Matrix3 operator * (Matrix3& rhs); // Returns copy of multication result

	Vector3 operator*(Vector3& rhs);

	Matrix3& operator += (Matrix3& rhs);

	Matrix3& operator -=(Matrix3& rhs);

	Matrix3& operator *=(Matrix3& rhs);

	operator float*();
	
	float m[3][3];
};


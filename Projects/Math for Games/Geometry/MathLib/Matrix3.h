#pragma once

class Vector3;

class Matrix3 // Row Major just transpose for column major
{
public:
	Matrix3(); // Sets all values to zero by default
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i); // Input as row major then transposes to column
	Matrix3(Matrix3 &original);
	~Matrix3();

	static Matrix3 CreateIdentity(); // Creates New Idenity Matrix

	Matrix3& Transpose(); // Transposes current matrix

	Matrix3 GetTranspose(); // Returns a transposed copy of current matrix

	Matrix3 operator + (Matrix3& RHS); // Returns copy of add result

	Matrix3 operator - (Matrix3& rhs); // Returns copy of subtract result

	Matrix3 operator * (Matrix3& rhs); // Returns copy of multication result

	Vector3 operator*(Vector3& rhs); // Transforms to Vector3

	Matrix3& operator += (Matrix3& rhs);

	Matrix3& operator -=(Matrix3& rhs);

	Matrix3& operator *=(Matrix3& rhs);

	operator float*(); // Casts to float

	Matrix3 setRotateX(float rad); // Rotates x axis

	Matrix3 setRotateY(float rad); // Rotates y axis

	Matrix3 setRotateZ(float rad); // Rotates z axis

	// Code required to get graphical exercise working

	static Matrix3 CreateRotation(float radians);

	static Matrix3 CreateScale(Vector3& scale);

	static Matrix3 CreateTranslation(Vector3& transation);

	static Matrix3 CreateTranslation(float x, float y, float z = 1.0f);

	float m[3][3];
};


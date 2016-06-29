#include "Matrix2.h"

#include <algorithm>


Matrix2::Matrix2()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			m[i][j] = 0;
		}
	}
}

Matrix2::Matrix2(float a, float b, float c, float d)
{
	m[0][0] = a;
	m[0][1] = b;
	m[1][0] = c;
	m[1][1] = d;

	Transpose(); // Inputed as row major transpose to covert to column major
}

Matrix2::Matrix2(Matrix2 & original)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			m[i][j] = original.m[i][j];
		}
	}
}


Matrix2::~Matrix2()
{
}

Matrix2 Matrix2::CreateIdentity()
{
	Matrix2 identity;
	for (int i = 0; i < 2; ++i)
	{
		identity.m[i][i] = 1;
	}
	return identity;
}

Matrix2 & Matrix2::Transpose()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = i; j < 2; ++j)
		{
			float temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
	}
	return *this;
}

Matrix2 Matrix2::GetTranspose()
{
	Matrix2 transpose(*this);

	return transpose.Transpose();
}

Matrix2 Matrix2::operator+(Matrix2 & RHS)
{
	Matrix2 temp;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			temp.m[i][j] = m[i][j] + RHS.m[i][j];
		}
	}
	return  temp;
}

Matrix2 Matrix2::operator-(Matrix2 & rhs)
{
	Matrix2 temp;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			temp.m[i][j] = m[i][j] - rhs.m[i][j];
		}
	}

	return temp;
}

Matrix2 Matrix2::operator*(Matrix2 & rhs)
{
	Matrix2 temp;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			float result = 0;
			int counter = 0;
			while (counter < 2)
			{
				result += (m[i][counter] * rhs.m[counter][j]);
				counter++;
			}
			temp.m[i][j] = result;
		}
	}

	return temp;
}

Vector2 Matrix2::operator*(Vector2 & rhs)
{
	Vector2 temp;

	float * arr = (float*)rhs;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			switch (i)
			{
			case 0:
				temp.x += m[i][j] * arr[j];
				break;
			case 1:
				temp.y += m[i][j] * arr[j];
				break;
			}
		}
	}

	return temp;
}

Matrix2::operator float*()
{
	return *m;
}

Matrix2 Matrix2::setRotateZ(float rad)
{
	*this = CreateIdentity();

	m[0][0] = cosf(rad);
	m[0][1] = -sinf(rad);
	m[1][0] = sinf(rad);
	m[1][1] = cosf(rad);

	return *this;
}



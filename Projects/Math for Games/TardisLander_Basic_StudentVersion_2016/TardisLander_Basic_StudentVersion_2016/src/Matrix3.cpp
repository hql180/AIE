#include "Matrix3.h"
#include <algorithm>

Matrix3::Matrix3()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m[i][j] = 0;
		}
	}
}

Matrix3::Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
	m[0][0] = a;
	m[0][1] = b;
	m[0][2] = c;
	m[1][0] = d;
	m[1][1] = e;
	m[1][2] = f;
	m[2][0] = g;
	m[2][1] = h;
	m[2][2] = i;
}

Matrix3::Matrix3(Matrix3 & original)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m[i][j] = original.m[i][j];
		}
	}
}


Matrix3::~Matrix3()
{
}

Matrix3 Matrix3::CreateIdentity()
{
	Matrix3 identity;
	for (int i = 0; i < 3; ++i)
	{
		identity.m[i][i] = 1;
	}
	return identity;
}

Matrix3 Matrix3::CreateRotation(float radians)
{
	Matrix3 temp;

	temp.m[0][0] = std::cosf(radians);
	temp.m[0][1] = -std::sinf(radians);
	temp.m[1][0] = std::sinf(radians);
	temp.m[1][1] = std::cosf(radians);
	temp.m[2][2] = 1;
	
	return temp.Transpose();
}

Matrix3 Matrix3::CreateScale(Vector3 & scale)
{
	Matrix3 temp;
	temp.m[0][0] = scale.m_x;
	temp.m[1][1] = scale.m_y;
	//temp.m[2][2] = scale.m_z;
	return temp;
}

Matrix3 Matrix3::CreateTranslation(Vector3 & transation)
{
	Matrix3 trans;

	trans = CreateIdentity();

	trans.m[2][0] = transation.m_x;

	trans.m[2][1] = transation.m_y;

	//trans.m[2][2] = transation.m_z;

	return trans;
}

Matrix3 Matrix3::CreateTranslation(float x, float y, float z)
{
	return CreateTranslation(Vector3(x, y, z));
}

Matrix3 & Matrix3::Transpose()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			float temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
	}
	return *this;
}

Matrix3 Matrix3::GetTranspose()
{
	Matrix3 transpose(*this);
	
	return transpose.Transpose();
}

Matrix3 Matrix3::operator+(Matrix3 & RHS)
{
	Matrix3 temp;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			temp.m[i][j] = m[i][j] + RHS.m[i][j];
		}
	}
	return  temp;
}

Matrix3 Matrix3::operator-(Matrix3 & rhs)
{
	Matrix3 temp;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			temp.m[i][j] = m[i][j] - rhs.m[i][j];
		}
	}

	return temp;
}

Matrix3 Matrix3::operator*(Matrix3 & rhs)
{
	Matrix3 temp;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			float result = 0;
			int counter = 0;
			while (counter < 3)
			{
				result += (m[i][counter] * rhs.m[counter][j]);
				counter++;
			}			
			temp.m[i][j] = result;
		}
	}

	return temp;
}

Vector3 Matrix3::operator*(Vector3 & rhs)
{
	Vector3 temp;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			switch (i)
			{
			case 0:
				temp.m_x += rhs.m_x * m[i][j];
				break;
			case 1:
				temp.m_y += rhs.m_y * m[i][j];
				break;
			case 2:
				temp.m_z += rhs.m_z * m[i][j];
				break;
			}
		}
	}

	return Vector3();
}

Matrix3 & Matrix3::operator+=(Matrix3 & rhs)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m[i][j] += rhs.m[i][j];
		}
	}

	return *this;
}

Matrix3 & Matrix3::operator-=(Matrix3 & rhs)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m[i][j] -= rhs.m[i][j];
		}
	}

	return *this;
}

Matrix3 & Matrix3::operator*=(Matrix3 & rhs)
{
	*this = *this * rhs;

	return *this;
}

Matrix3::operator float*()
{
	/*float arr[9];

	int counter = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			arr[counter++] = m[i][j];
		}
	}

	return arr;*/

	return (float*)this;
}


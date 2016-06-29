#include "Matrix4.h"



Matrix4::Matrix4()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = 0;
		}
	}
}

Matrix4::Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m1, float n, float o, float p)
{
	m[0][0] = a;
	m[0][1] = b;
	m[0][2] = c;
	m[0][3] = d;
	m[1][0] = e;
	m[1][1] = f;
	m[1][2] = g;
	m[1][3] = h;
	m[2][0] = i;
	m[2][1] = j;
	m[2][2] = k;
	m[2][3] = l;
	m[3][0] = m1;
	m[3][1] = n;
	m[3][2] = o;
	m[3][3] = p;
}

Matrix4::Matrix4(Matrix4 & original)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = original.m[i][j];
		}
	}
}


Matrix4::~Matrix4()
{
}

Matrix4 Matrix4::CreateIdentity()
{
	Matrix4 identity;
	for (int i = 0; i < 4; ++i)
	{
		identity.m[i][i] = 1;
	}
	return identity;
}

Matrix4 & Matrix4::Transpose()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = i; j < 4; ++j)
		{
			float temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
	}
	return *this;
}

Matrix4 Matrix4::GetTranspose()
{
	Matrix4 transpose(*this);

	return transpose.Transpose();
}

Matrix4 Matrix4::operator+(Matrix4 & RHS)
{
	Matrix4 temp;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			temp.m[i][j] = m[i][j] + RHS.m[i][j];
		}
	}
	return  temp;
}

Matrix4 Matrix4::operator-(Matrix4 & rhs)
{
	Matrix4 temp;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			temp.m[i][j] = m[i][j] - rhs.m[i][j];
		}
	}

	return temp;
}

Matrix4 Matrix4::operator*(Matrix4 & rhs)
{
	Matrix4 temp;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			float result = 0;
			int counter = 0;
			while (counter < 4)
			{
				result += (m[i][counter] * rhs.m[counter][j]);
				counter++;
			}
			temp.m[i][j] = result;
		}
	}

	return temp;
}

Vector4 Matrix4::operator*(Vector4 & rhs)
{
	Vector4 temp;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
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
			case 3:
				temp.m_w += rhs.m_w * m[i][j];
				break;
			}
		}
	}

	return temp;
}

Matrix4::operator float*()
{
	return *m;
}

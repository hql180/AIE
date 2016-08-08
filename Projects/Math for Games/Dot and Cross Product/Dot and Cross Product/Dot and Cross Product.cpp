#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

void q1()
{
	// Radians = (Degrees/180) * PI	

	// 30 = 0.524

	// 45 = 0.785

	// 72 = 1.257
}

void q2()
{
	// Degrees = Radian/Pi * 180

	// 1.5 = 85.94

	// 3PI / 2 = 270

	// 2 = 114.59
}

void q3()
{
	// A * B = AxBx + AyBy + AzBz

	// (3,4) (-5, 3) = -15 + 12 = -3 ~ obtuse angle ~ both pointing the same direction

	// (0,8) (8,0) = 0 + 0 = 0 ~ 90 degree angle

	// (0,-3) (0,-6) = 0 + 18 = 18 ~ acute angle

	// (-1,-1) (-5,-6) = 5 + 6 = 11 ~ acute angle

	// (3,3) (3,-3) = 9 + - 9 = 0 ~ right angle
}

void q4()
{
	// (3,4) (-5, 3) = 5 5.83 = .6,.8 -.86,.51 =  -.52 + .41 = -.11 ~ 96.32
	
	// (0,8) (8,0) = 90

	// (0,-3) (0,-6) = 3 6 = 0,-1 0,-1 = 0, 1 = 1 ~ 0

	// (-1,-1) (-5,-6) = 1.41 7.81 = (-.71,-.71) (-.64,-.77) = .45 + .54 = .99 ~ 8.11

	// (3,3) (3,-3) = 90
}

void q5()
{
	// a x b = (a2b3 - a3b2 , a3b1 - a1b3 , a1b2 - a2b1)

	// ( -8, 0, -3 ) x (2, 2, 4) = 0 * 4 - -3 * 2 , -3 * 2 - -8 * 4 , -8 * 2 - 0 * 2

	// 0 - - 6 , -6 - - 32 , -16 - 0 = (6, 26, -16)

	// (14, 5, -5) x (-2, 1, 43) = 5 * 43 - -5 * 1 , -5 * -2 - 14 * 43 , 14 * 1 - 5 * -2

	// 215 - 5 , 10 - 602, 14 - - 10 = (210, - 592 , 24)	
}

struct Vector
{
	Vector() {};
	Vector(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {};

	float Dot(Vector a, Vector b)
	{
		return a.m_x * b.m_x + a.m_y * b.m_y + a.m_z * b.m_z;
	}

	Vector Cross(Vector a, Vector b)
	{
		return Vector(a.m_y * b.m_z - a.m_z * b.m_y,
						a.m_z * b.m_x - a.m_x * b.m_y, 
						a.m_x* b.m_y - a.m_y * b.m_x);
	}

	float Angle(Vector a, Vector b)
	{
		Vector aUV = Normalise(a);
		Vector bUV = Normalise(b);

		return acos(aUV.m_x*bUV.m_x + aUV.m_y*bUV.m_y + aUV.m_z*bUV.m_z) / M_PI * 180;
	}

	Vector Normalise(Vector a)
	{
		float mag = sqrt(pow(a.m_x, 2) + pow(a.m_y, 2) + pow(a.m_z, 2));
		return Vector(a.m_x / mag, a.m_y / mag, a.m_z / mag);
	}

	float m_x, m_y, m_z;
};

int main()
{


	system("pause");
    return 0;
}


#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

void q1()
{
	// 1 radian = 57.2958
}

void q2()
{
	// radian = 60 * pi/180
	// radian = pi/3;
	// = 1.0471975512
}

double radToDeg(double rad)
{
	return rad * 180 / M_PI;
}

double degToRad(double deg)
{
	return deg * M_PI / 180;
}

void q4()
{
	// They spaced the knots out in accordance to the lengths from pythagoras' theorem.
}

void q5()
{
	// asin(3/5) = 36.87
	// acos(3/5) = 53.13
}

void q6()
{
	//angle
	//	a = 37
	//	b = 79


	//	side
	//	A = 13

	//	13 / sin 37 = B / sin 79

	//	b = 13 / sin 37 x sin 79
}

void q7()
{
	//cos(c) = a^2 + b^2 - c^2 / (2ab)

	//6^2 + 9^2 - 8^2 / 2x6x9

	//36 + 81 - 64 / 108

	//acos (.4907) = 60.6172
}

double itsSolvingTime(double a, double b, double c)
{
	return acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a*b)) * 180 / M_PI;
}

void angles(double a, double b, double c, double& refA, double& refB, double& refC)
{
	refA = itsSolvingTime(b, c, a);
	refB = itsSolvingTime(a, c, b);
	refC = itsSolvingTime(b, a, c);
}

int main()
{
	double a, b, c;
	double A, B, C;

	a = 6;
	b = 8;
	c = 9;

	angles(a, b, c, A, B, C);
	

	cout << A << " " << B << " " << C << "\n";

	system("pause");
    return 0;
}


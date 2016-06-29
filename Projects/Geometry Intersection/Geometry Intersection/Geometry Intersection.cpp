#include <iostream>
#include <math.h>

#include "MathLib.h"

struct Circle
{
	Circle(float x, float y, float r) : center(x, y), radius(r) {};

	Vector2 center;
	float radius;
};

float dist(Vector2 a, Vector2 b)
{
	return sqrtf(pow(b.m_x - a.m_x, 2) + pow(b.m_y - a.m_y, 2));
}

bool CircleCircle(Vector2 a_center, float a_radius, Vector2 b_center, float b_radius)
{
	if ((a_radius + b_radius) > dist(a_center, b_center))
		return true;
	else
		return false;
}

bool AABBAABB(Vector2 a_min, Vector2 a_max, Vector2 b_min, Vector2 b_max)
{
	if (a_max.m_x < b_min.m_x || b_max.m_x < a_min.m_x ||
		a_max.m_y < b_min.m_y || b_max.m_y < a_min.m_y)
		return false;
	else
		return true;
}

bool LineLine(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, Vector2& crossPoint)
{
	float denom = (p4.m_y - p3.m_y)*(p2.m_x - p1.m_x) - (p4.m_x - p3.m_x)*(p2.m_y - p1.m_y);

	float tA = ((p4.m_x = p3.m_x)*(p1.m_y - p3.m_y) - 
				(p4.m_y - p3.m_y)*(p1.m_x - p3.m_x)) / denom;

	float tB = ((p2.m_x - p1.m_x)*(p1.m_y - p3.m_y) - 
				(p2.m_y - p1.m_y)*(p1.m_x - p3.m_x)) / denom;

	crossPoint.m_x = tA;

	crossPoint.m_y = tB;

	if (tA > 0 && tA < 1 && 
		tB > 0 && tB < 1)
		return true;
	else
		return false;	
}

int main()
{


	system("pause");
    return 0;
}


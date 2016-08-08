#include <iostream>
#include <math.h>

using namespace std;

float fx(float x)
{
	return x*x + 2 * x - 7;
}

bool fabc(float a, float b, float c, float& r1, float& r2)
{
	float result = b*b - 4 * a*c;
	if (result < 0)
		return false;
	result = sqrt(result);
	r1 = (-b - result) / (2 * a);
	r2 = (-b + result) / (2 * a);
	return true;
}

float Lset(float s, float e, float t)
{
	return s + t*(e - s);
}

float distance(float x1, float y1, float x2, float y2)
{
	float x = x2 - x1;
	float y = y2 - y1;
	x *= x;
	y *= y;

	return sqrt(x + y);
}

//void innerPQ(float px, float py, float pz, 
//				float qx, float qy, float qz,
//				float& rx, float& ry, float& rz)
//{
//	
//}

float innerPQ(float px, float py, float pz,
				float qx, float qy, float qz)
{
	return px*qx + py*qy + pz*qz;
}

float distance(float px, float py, float pz, float pd,
				float xx, float xy, float xz)
{
	float result = px + py + pz + pd;
	result /= (sqrt(xx*xx + xy*xy + xz*xz));

	return result;
}

float Bt(float t, float p0, float p1, float p2, float p3)
{
	return (pow(1 - t, 3)*p0) + (3 * pow(1 - t, 2)*t*p1) + (3 * (1 - t)*pow(t, 2)*p2) + (pow(t, 3)*p3);
}

int main()
{
	float r1, r2;
	if (fabc(1, 10, 10, r1, r2))
	{
		cout << r1 << " " << r2 << "\n";
	}

	system("pause");
    return 0;
}


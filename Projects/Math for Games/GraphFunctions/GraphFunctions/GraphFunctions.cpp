#include <iostream>
#include <math.h>

using namespace std;

float square(float x)
{
	return x*x;
}

float root(float x)
{
	if (x > 0)
		return sqrt(x);
}

float sin3(float x)
{
	return sin(x*3);
}

float Cos(float x)
{
	return fabsf(cos(x)) * (1 - x);
}



int main()
{

	cout << sin3(.5) << " " << sin3(1) << endl;

	system("pause");
    return 0;
}


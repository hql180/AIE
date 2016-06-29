#include <iostream>
#include <cstdio>

using namespace std;

struct Numbers
{
	int a, b;
};

void change(int& a, int& b)
{
	a += b;

	b += a;
}

void change(Numbers& num)
{
	num.a += num.b;

	num.b += num.a;
}

void q1()
{
	// b

	int a = 10;

	// c

	cout << a << endl;

	// d

	int& b = a;

	// e

	cout << b << endl;

	// f

	b = 20;

	// g

	int& c = b;

	// h

	cout << "a " << a << " b " << b << " c " << c << endl;

	//int& d;
	// doesn't compile must initialise

	float d = 2.323;

	//c = d;
	// can't change after initilisation

	//int& e = d;
	// doesn't work
	// works but doesn't maintain target data type

	cout << " working " << d << endl;
}

void q2()
{
	int a = 10, b = 5;

	cout << "a = " << a << " b = " << b << endl;

	change(a, b);

	cout << "a = " << a << " b = " << b << endl;
}

void q3()
{
	q2();

	Numbers test = { 10, 5 };

	cout << "Should match Above" << endl;

	cout << "a = " << test.a << " b = " << test.b << endl;

	change(test);

	cout << "a = " << test.a << " b = " << test.b << endl;
}

void q5()
{
	// a)
	// don't have to use memory to make a copy of structure
	// when passing into funtion usually to change contents of structure
	// ref makes that easier

	// b)
	
}

int main()
{
	//q1();

	//q2();

	//q3();



	system("pause");
    return 0;
}


#include <iostream>
#include "Position.h"

using namespace std;

int main()
{
	float a = 1.5;
	float b = 2;

	Position test(a, b);
	Position test1(b, a);

	cout << a << " " << b << endl;
	cout << test.GetX() << " " << test.GetY() << endl;

	a = 12.3;
	b = 34.2;
	cout << a << " " << b << endl;
	test.Print();
	test1.Print();

	Position test2 = test + test1;

	test2.Print();

	Position test3 = test2 - test;

	test3.Print();

	Position test4 = test3 * test2;

	test4.Print();

	Position test5 = test4 / test2;

	test5.Print();

	test5 *= test2;

	test5.Print();

	
	
	
	system("pause");
    return 0;
}


#include <iostream>

using namespace std;

int main()
{	
	float a = 2 / 3.0f + 3 / 5.0f;
	float b = 2 % 3 + 3 % 5;
	float c = 23 % 15 % -2;
	float d = 25 * 1 / 2;
	float e = 25 * 1.0 / 2;
	float f = 25 * (1 / 2.0f);
	float g = 235 / 8 + 7;
	float h = 235 / 8.0 + 7;
	float i = ((20 + 1) / 2 - 2.0) / (23 + 3)*0.2;
	float ib = ((20 + 1) / 2.0 - 2.0) / (23 + 3)*0.2;


	cout << "a) " << a << endl;
	cout << "b) " << b << endl;
	cout << "c) " << c << endl;
	cout << "d) " << d << endl;
	cout << "e) " << e << endl;
	cout << "f) " << f << endl;
	cout << "g) " << g << endl;
	cout << "h) " << h << endl;
	cout << "i) " << i << endl;
	cout << "ib) " << ib << endl;

	// 2 a) averageHeightClass
	// b) taxRateHigh
	// c) taxRateLow
	// d) costSteamLib

	int a3 = 121;
	float b3 = 9.4f;
	char c3 = 114;
	int d3 = 100000;
	bool e3 = true;


	cout << "3 a) " << a3 << " int" << endl;
	cout << "3 b) " << b3 << " float" << endl;
	cout << "3 c) " << "char 114 " << c3 << endl;
	cout << "3 d) " << "int " << d3 << endl;
	cout << "3 e) " << "bool " << e3 << endl;

	//float a4 = 0.0f;
	//float b4 = 0.0f;
	//float c4 = 0.0f;

	int num1, num2;

	cin >> num1 >> num2;

	int num3 = num1;
	num1 = num2;
	num2 = num3;

	cout << "a = " num1 << " b = " << num2 << endl;
	cin.get();

	return 0;
}
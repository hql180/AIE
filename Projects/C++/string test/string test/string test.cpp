#include <iostream>
#include <cstdio>
#include <string>
#include <istream>

using namespace std;


int main()
{
	string a_name = "green apple";

	string b_name = "red apple";

	bool test;
	/*
	getline(cin, a_name);

	getline(cin, b_name);
*/
	cout << a_name.compare(6,5,"apple");


	system("pause");
    return 0;
}

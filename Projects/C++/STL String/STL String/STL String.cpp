#include <iostream>
#include <string>

using namespace std;

int main()
{
	string myString1 = "Hello World"; //demonstrate creating a string
	string myString2 = myString1; // demonstrate copying a string
	if (myString1 == myString2) // demonstrate equality test
	{
		cout << "strings are the same" << endl;
	}
	myString1 = "Goodbye!"; //changes contents of string 1
	cout << "myString2 = " << myString2 << endl; //demonstrates that strings are now different
	cout << "myString1=" << myString1 << endl;//we didn't just copy the pointer as with the old char[]
	if (myString1 != myString2) //demonstrate inequality test
	{
		cout << "strings are not the same" << endl;
	}
	myString2 += "... " + myString1; //demonstrate
	cout << "myString2 = " << myString2 << endl;

	system("pause");
    return 0;
}


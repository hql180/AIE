#include <iostream>
#include <cstdio>

using namespace std;

void q1()
{
	char c = 'T', d = 'S';
	char *p1 = &c;
	char *p2 = &d;
	char *p3;

	p3 = &d;
	cout << "*p3 = " << *p3 << endl; // (1)
	// Prints S
	p3 = p1;
	cout << "*p3 = " << *p3; // (2)
	// Prints T
	cout << ", p3 = " << p3 << endl; // (3)
	// Prints location of c
	*p1 = *p2;
	cout << "*p1 = " << *p1; // (4)
	// Should print S
	cout << ", p1 = " << p1 << endl; // (5)
	// Prints out memory location of c
}

void q2()
{
	int *p;
	int i;
	int k;

	i = 42;
	// Sets i to 42
	k = i;
	// Copies i into k
	p = &i;
	// p now points to the content of i
	cout << *p;
}

void q3()
{
	int *p;
	int i;
	int k;

	i = 42;
	k = i;
	p = &i;
	
	k = 75;
	// Sets k to 75
	//*k = 75;
	// Not a pointer doesn't compile
	//p = 75;
	// p hasn't been intialised only *p has
	*p = 75;
	// changes memory location of *p to 75 i is now 75

	cout << i << " " << *p;
}

void q4()
{
	/*char c = 'A';
	double *p = &c;*/
	// Different data types
}

void q5()
{
	char blocks[3] = { 'A','C','E' }; // &blocks[0] = 4434
	char *ptr = &blocks[0]; // ptr = 4434
	char temp; // temp = ??

	temp = blocks[0]; // temp = 'A'
	temp = *(blocks + 2); // temp = 'C'
	temp = *(ptr + 1); // temp = 'B'
	temp = *ptr; // temp = 'A'

	ptr = blocks + 1; // ptr 4435
	temp = *ptr; // temp = 'B'
	temp = *(ptr + 1); // temp = 'C'

	ptr = blocks; // ptr = 4434
	temp = *++ptr; // temp = 'B'
	temp = ++*ptr; // temp = 'B' + 1 = 'C'
	temp = *ptr++; // temp = 'B' , *ptr = 'C'
	temp = *ptr;
}

void revString(char* array)
{
	int length = strlen(array);

	char temp;

	for (int i = 0; i < length / 2; i++)
	{
		temp = *(array + i);

		*(array + i) = *(array + length - 1 - i);

		*(array + length - 1 - i) = temp;
	}
}

int countEven(int* array, int arrayLen)
{
	int isEven = 0;
	for (int i = 0; i < arrayLen; i++)
	{
		int index = *(array + i);

		if (!(index % 2))
		{
			++isEven;
		}
	}
	return isEven;
}

double* maximum(double* array, int arraySize)
{
	if (arraySize == 0)
	{
		return nullptr;
	}

	int counter = 0;

	double* temp = array;

	temp = &(*(array + counter));

	while (counter < arraySize)
	{
		if (*temp < *(array + counter))
		{
			temp = array + counter;
		}
		counter++;
	}

	return temp;
}

bool contains(char* array, char searchValue)
{
	int length = strlen(array);

	for (int i = 0; i < length; i++)
	{
		if (*(array + i) == searchValue)
		{
			return *(array + i);
		}
	}

	return false;
}

void q6()
{
	char temp [20];

	cin >> temp;

	revString(temp);

	cout << "working? " << temp << endl;
}

void q6b()
{
	int array[] = { 3, 5, 6 ,8 ,10 ,12, 12, 10, 2, 3 };

	int length = 10;

	int evenNumbers = countEven(array, length);

	cout << evenNumbers << " working.";
}

void q6c()
{
	double array[] = {123.56, 2056.31, 1336, 321, 1, 20 };

	int length = 5;

	double* max = maximum(array, length);

	//*max = 2;

	cout << *(array+1) << " " << *max << " working." << endl;
}

void q6d() 
{
	char array[] = "testing this out";
	char search = 'a';

	bool found = contains(array, search);

	cout << found << " working.";
}

void q7()
{
	int * ptr_a, *ptr_b, **ptr_c;

	ptr_a = new int;
	*ptr_a = 3;
	ptr_b = ptr_a;
	cout << *ptr_a << " " << *ptr_b << "\n";
	// a = new int = 3, b = a = new int = 3
	ptr_b = new int;
	*ptr_b = 9;
	cout << *ptr_a << " " << *ptr_b << "\n";

	*ptr_b = *ptr_a;
	cout << *ptr_a << " " << *ptr_b << "\n";

	delete ptr_a;
	ptr_a = ptr_b;
	cout << *ptr_a << " " << *&*&*&*&*ptr_b << "\n";

	ptr_c = &ptr_a;
	cout << *ptr_c << " " << **ptr_c << "\n";

	delete ptr_a;
	ptr_a = NULL;

}

int main()
{
	//q1();
	
	//q2();
	
	//q3();

	//q4();

	//q5();

	//q6();

	//q6b();

	//q6c();

	//q6d();

	q7();

	system("PAUSE");
    return 0;
}


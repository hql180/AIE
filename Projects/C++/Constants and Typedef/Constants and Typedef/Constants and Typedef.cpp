// Constants and Typedef.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>

using namespace std;

char choice;
int flag;
long date, time;
double factor;
extern char bondType;
const double gallonsToLitres = 3.78533;

double watts()
{
	return 0;
}
double thrust()
{
	return 0;
}

int timesCalled()
{
	static int called = 0;
	++called;
	return called;
}

double convertGallonToLitre(double gallon)
{
	return gallon * gallonsToLitres;
}

void q1()
{
	//static local variable only exists in the file it is declared in
	//global variable can be used in all files in the same project if called upon correctly
}

void q2()
{
	int called;
	for (int i = 0; i < 10; i++)
	{
		called = timesCalled();
	}
	cout << "I have been called " << called << " times." << endl;
}

void q4()
{
	// callbyvalue has a variable value
	// callbyconstreference has a const var that can't be changed
}

void q5()
{
	double gallons;

	cout << "Input gallons to convert to litres: ";
	
	cin >> gallons;

	double litres = convertGallonToLitre(gallons);

	cout << "There are " << litres << " litres in " << gallons << "  US gallons" << endl;
}

void q6()
{

}

int main()
{
	//q2();

	q5();

	system("pause");
	return 0;
}


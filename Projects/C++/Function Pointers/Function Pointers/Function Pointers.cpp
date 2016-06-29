#include <iostream>

typedef double(*MyFunction)(float lhs, float rhs);

double add(float lhs, float rhs)
{
	return lhs + rhs;
}

double sub(float lhs, float rhs)
{
	return lhs - rhs;
}

double mult(float lhs, float rhs)
{
	return lhs * rhs;
}

double div(float lhs, float rhs)
{
	return lhs / rhs;
}

MyFunction getFunction(char operation)
{
	switch (operation)
	{
	case '+':
		return &add;
	case '-':
		return &sub;
	case '*':
		return &mult;
	case '/':
		return &div;
	default:
		std::cout << "something broke \n";
	}
}

int main()
{

	std::cout << getFunction('*')(5, 5) << '\n';

	system("pause");
    return 0;
}


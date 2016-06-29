#include <iostream>
#include <conio.h>

void fibonacci(int a, int b)
{
	std::cout << a << ", ";

	int c = a + b;

	if (b > 1000000)
	{
		return;
	}

	fibonacci(b, c);
}

int power(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else
	{
		return a * power(a, b - 1);
	}
}

int towerMoves(int n)
{

	return towerMoves(n - 1) * 2 + 1;
}

int main()
{
	// 1)

	//fibonacci(0, 1);

	// 2)

	/*int a, b;
	
	std::cout << "First number: ";

	std::cin >> a;

	std::cout << "Second number: ";

	std::cin >> b;

	int c = power(a, b);

	std::cout << a << " to the power of " << b << " is ";

	std::cout << c;*/

	
	int c;

	std::cin >> c;

	std::cout << towerMoves(8);



	getch();
	return 0;
}


#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <sstream>

int choice;

const int kInvalid = -1;
const int kRock = 0;const int kPaper = 1;const int kScissors = 2;


void PrintInteger(int variable)
{
	std::cout << variable << std::endl;
}

float smallerNumber(float a, float b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

float smallerNumber(float a, float b, float c)
{
	return smallerNumber((a, b), c);
}

float smallestNumber(float a, float b, float c)
{
	if (a < b && a < c)
	{
		return a;
	}
	else if (b < c)
	{
		return b;
	}
	else
	{
		return c;
	}
}

float half(float number)
{
	float result = number / 2;
	return result;
}

void coinToss(int a)
{		
	int number = rand() % 32768;

	number = rand() % 32768;

	number = rand() % 32768;

	std::cout << "Random number (0 - 32767): " << number << std::endl;

	int flips = 0;
	
	while (flips < a)
	{
		int flip = rand() % 2;

		flips += 1;

		std::cout << flips << ") ";

		if (flip == 1)
		{
			std::cout << "Heads" << std::endl;
		}
		else
		{
			std::cout << "Tails" << std::endl;
		}
	}
	return;
}

int sumTo(int n)
{
	int result = 0;

	for (int i = 0; i <= n; i++)
	{
		result += i;
	}

	return result;
}

int randNum(int n)
{
	return rand() % n;
}

int convertString(std::string str)
{
	if (str == "rock")
	{
		return 0;
	}
	else if (str == "paper")
	{
		return 1;
	}
	else if (str == "scissors")
	{
		return 2;
	}
	return -1;
}

std::string convertChoice(int choice)
{
	switch (choice)
	{
	case kRock:
		return "rock";
	case kPaper:
		return "paper";
	case kScissors:
		return "Scissors";
	default:
		return "draw";
	}
}

std::string chooseWinner(int player, int comp)
{
	if ((player == 0 && comp == 2) ||
		(player == 1 && comp == 0) ||
		(player == 2 && comp == 1))
	{
		return "Player Wins!";
	}
	else if ((comp == 0 && player == 2) ||
			 (comp == 1 && player == 0) ||
			 (comp == 2 && player == 1))
	{
		return "Computer Wins!";
	}
	else
	{
		return "draw";
	}
	
}

void rockPaperScissors()
{
	std::cout << "Enter your choice (rock, paper, scissors): ";

	std::string str;

	std::cin >> str;

	int playerChoice = convertString(str);

	int compChoice = randNum(3);

	std::cout << "Player chose " << convertChoice(playerChoice)
		<< " Computer chose " << convertChoice(compChoice)
		<< " " << chooseWinner(playerChoice, compChoice) << std::endl;
	return;
}


//int sumArray()
//{
//
//}

int main()
{
	srand(time(NULL));

	rockPaperScissors();

	// 1)

	//1
	//1
	//2
	//2
	//3
	//2
	//1
	//
	//int the_variable = 1;
	//PrintInteger(the_variable);
	//{
	//	PrintInteger(the_variable);
	//	int the_variable = 2;
	//	PrintInteger(the_variable);
	//	{
	//		PrintInteger(the_variable);
	//		int the_variable = 3;
	//		PrintInteger(the_variable);
	//	}
	//	PrintInteger(the_variable);
	//}
	//PrintInteger(the_variable);
	// 2)

	//float a, b;
	// 
	//std::cout << "Enter value 1: ";
	// 
	//std::cin >> a;
	// 
	//std::cout << "Enter value 2: ";
	// 
	//std::cin >> b;
	// 
	//float c = smallerNumber(a, b);
	// 
	//std::cout << "The smaller number is: " << c << std::endl;

	// 3)

	//float a, b, c;
	// 
	//std::cout << "Enter value 1: ";
	// 
	//std::cin >> a;
	// 
	//std::cout << "Enter value 2: ";
	// 
	//std::cin >> b;
	//
	//std::cout << "Enter value 3: ";
	//
	//std::cin >> c;
	// 
	//float d = smallestNumber(a, b, c);
	// 
	//std::cout << "The smallest number is: " << d << std::endl;

	// 4)

	/*float number;

	std::cout << "Input number: ";

	std::cin >> number;

	float result = half(number);

	std::cout << "Half of " << number << " is " << result;*/

	// 5)

	/*int a;

	std::cout << "How many times would you like to flip the coin?: ";

	std::cin >> a;

	coinToss(a);*/

	// 6)

	//int sum(int x, int y)
	//{
	//	int result; 
	//	result = x + y;
	// Not returning any values
	// add return results;
	//}
	//int sum (int n)
	//{
	//	if (0 == n)
	//		return 0;
	//	else
	//		n = n + n;
	//	// not returning n
	//}

	//int main()
	//{
	//	double x = 13.6;
	//	std::cout << "square of 13.6 = " << square(x) << std::endl;
	//}
	//// call for function before it is initialised
	//}
	//int square(int x) // need to be double
	//{
	//	return x * x;
	//}

	// 7)

	//int result = sumTo(3); //result = 1 + 2 + 3 = 6
	// 
	//std::cout << result << std::endl;
	//	 
	//result = sumTo(15); //result should now be 120
	//	 
	//std::cout << result << std::endl;	// 8)		//int integer_array[5] = { 7, 3, 2, 4, 9 };
	//int result = sumArray(integer_array, 5); //result = 25
	//std::cout << result << std::endl;	// 17)				getch();

	system("pause");

	return 0;
}

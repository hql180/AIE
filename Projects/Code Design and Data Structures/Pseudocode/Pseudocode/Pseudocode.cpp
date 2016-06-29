#include <iostream>

using namespace std;

void Q1A()
{
	// Print "Enter the first number" to console
	cout << "Enter the first number\n";

	// Take in user into and store into num1
	int num1;
	cin >> num1;

	// Print "Enter the second number" to console
	cout << "Enter the second number\n";

	// Take and store user input in num2
	int num2;
	cin >> num2;

	// Initialise num3 to be the value of sum of num1 and num2
	int num3 = num1 + num2;

	// Initialise num4 with half the value of num 3
	int num4 = num3 / 2;

	// Print out num4
	cout << num4 << "\n";

	// Function takes in 2 user input numbers adds them together and divides the result by two before printing out result

}

void Q1B()
{
	// Set value of counter1 to 1
	int counter1 = 1;
	// Set value of num to 1
	int num = 1;
	// While counter1 is less than or equal to 5
	while (counter1 <= 5)
	{
		// While num is less than counter1
		while (num < counter1)
		{
			// Print out num
			cout << num << " ";
			// Increase num by 1
			num++;
			// Exit num loop
		}
		// Increase counter1 by 1
		counter1++;
		// Exit counter1 loop
	}

	// Counts from 1 to 5 and prints 1 to 4

}

void Q1C()
{
	// Read value of current
	int current[7] = { 1, 2, 4, 8, 16, 32, 64 };
	// Sets value of sum to value of current
	int sum = 0;
	// Set superIncreaseing to be true
	bool superIncreasing = true;
	// While there are more numbers to read
	int counter = 0;
	while (counter < 7)
	{
		// Read value of current
		// Checks to see if current has a lower or equal value to sum
		if (current[counter] <= sum)
		{
			// If current has a lower or equal value to sum Set superIncreasing to be false
			superIncreasing = false;
		}
		// Otherwise set sum to be the value of sum plus current
		else
		{
			sum = sum + current[counter];
		}
		// Exit loop when no more numbers to read
		counter++;
	}
	// Check if superIncreasing is true
	if (superIncreasing)
	{
		// If true print "Input forms a super increasing sequence."
		cout << "Input forms a super increasing sequence.\n";
	}
	// Otherwise print "Input is not super increasing."
	else
	{
		cout << "Input is not super increasing.\n";
	}

	// Will output not superincreasing because 15 + 16 is 31 and next number in sequence is 22
}

int main()
{
	Q1C();


	system("pause");
    return 0;
}


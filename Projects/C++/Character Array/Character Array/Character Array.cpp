#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int pseudoStrlen(char a[])
{
	int i = 0;

	while (true)
	{
		int length = 0;

		char test;

		test = a[i];

		++length;

		++i;

		if (test == '\0')
		{
			return length;
		}
	}
	
}

int main()
{
	// 1)

	//char firstName[10];
	//char lastName[10];
	//char space[3] = " ";
	//char reverseName[20];

	//std::cin >> firstName >> lastName;

	//char fullName[20];

	//strcpy(fullName, firstName);
	//strcat(fullName, space);
	//strcat(fullName, lastName);
	//
	//std::cout << fullName << std::endl;

	//// 2)

	//for (int a = strlen(fullName) - 1; a >= 0; --a)
	//{
	//	std::cout << fullName[a];
	//}
	
	// 3)

	/*char firstName[5][10];
	char lastName[5][10];
	char space[3] = " ";
	char fullName[5][20];
	char reverseName[5][20];
	
	for (int a = 0; a < 5; ++a)
	{
		std::cout << "Please enter name " << a + 1 << std::endl;

		std::cin >> firstName[a] >> lastName[a];

		strcpy(fullName[a], firstName[a]);
		strcat(fullName[a], space);
		strcat(fullName[a], lastName[a]);

		std::cout << "Name " << a + 1 << " recorded" << std::endl;
	}

	for (int b = 0; b < 5; ++b)
	{
		for (int a = strlen(fullName[b]) - 1; a >= 0; --a)
		{
			std::cout << fullName[b][a];
		}
		std::cout << std::endl;
	}*/

	// 4)

	//Beep(523, 500);
	//std::cout << "\a";

	// 5)

	//char password[19];

	//std::cin >> password;

	//while (strlen(password) >= 8)
	//{
	//	for (int a = 0; a < 19; a++)
	//	{
	//		if (password[a] >= 65 &&
	//			password[a] <= 90)
	//		{
	//			break;
	//		}
	//		else
	//		{
	//			std::cout << "broken?" << std::endl;
	//			std::cout << "broken?" << std::endl;
	//			std::cin >> password;
	//			a = 0;
	//		}
	//	}
	//}
	////std::cout << "Password needs to be at least 8 characters long" << std::endl;
	////std::cout << "and contain at least 1 capital letter." << std::endl;
	////std::cout << "Please enter a new password" << std::endl;
	////std::cin >> password;

	////std::cout << "working";

	////for (int a = 0; a < 19; a++)
	////{
	////	while (strlen(password) >= 8 &&
	////				password[a] < 65 &&
	////				password[a] > 90)
	////	{
	////		std::cout << "Password needs to be at least 8 characters long" << std::endl;
	////		std::cout << "and contain at least 1 capital letter." << std::endl;
	////		std::cout << "Please enter a new password" << std::endl;
	////		std::cin >> password;
	////	}
	////	/*if (password[a] < 65 &&
	////		password[a] > 90)
	////		{
	////			std::cout << "Letter " << a + 1 << " is not a capital" << std::endl;
	////			continue;
	////		}
	////		else
	////		{
	////		std::cout << "broken?" << std::endl;
	////		std::cout << "broken?" << std::endl;
	////		std::cin >> password;
	////		a = 0;
	////		}*/
	////}
	////std::cout << "seems to be working";

	//char username[256];
	//char password[256];

	//std::cout << "Please enter your username and password: " << std::endl;

	//if (strlen(password) >= 8)
	//{

	//}
	//else
	//{
	//	std::cout << "Password is too short." << std::endl;
	//}

	// 6)

	// 7)

	// a) 
	
	//char name[4] = "John";
	//trying to store john but too short needs to be 5

	// b)
	//char name[32];
	//cout << name;
	//reading without initilising data values

	// c)
	
	//char name[7] = "Donald";
	//char surname[7] = "Knuth";
	//strcat(name, surname);
	//array not large enough to store both
	//

	//char errorMsg[5] = "Stop";
	//errorMsg[strlen(errorMsg)] = "!";
	//std::cout << errorMsg;
	//array not long enough incorrect ""

	// 8)
	
	

	// 9)

	/*char string[256];
	std::cin >> string;

	int length = strlen(string);

	std::cout << "Input was " << length << " characters long";*/

	// 10)

	/*char string1[256];
	char string2[256];
	
	std::cin >> string1;

	int length = strlen(string1);

	for (int i = length -1; i >= 0; i--)
	{
		
		string2[length - i - 1] = string1[i];
	}

	string2[length] = '\0';

	if (strcmp(string1, string2) == 0)
	{
		std::cout << string1 << " is a palindrome!";
	}
	else
	{
		std::cout << string1 << " is not a palindrome";
	}*/
	
	// 11)
	char test[256];

	std::cin >> test;

	int length = pseudoStrlen(test);

	std::cout << length;


	
	getch();
    return 0;
}


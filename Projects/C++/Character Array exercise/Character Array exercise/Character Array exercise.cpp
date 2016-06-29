#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int pseudoStrlen(char a[])
{
	int length = 0;

	while (true)
	{
		char test;

		test = a[length];

		++length;

		if (test == '\0')
		{
			return length - 1;
		}
	}

}



bool pseudoStrcmp(char str1[], char str2[])
{
	int index = 0;

	while (true)
	{
		if (str1[index] == '\0' && str2[index] == '\0')
		{
			return true;
		}
		if (str1[index] == str2[index])
		{
			++index;
		}
		else
		{
			return false;
		}
	}
}

void pseudoStrcat(char str1[], char str2[])
{
	int str1Length = pseudoStrlen(str1);
	for (int a = 0; a <= pseudoStrlen(str2); ++a)
	{
		str1[str1Length + a] = str2[a];
	}
	//str1[str1Length + pseudoStrlen(str2)] = '\0';
	return;
}

void pseudoStrcpy(char str1[], char str2[])
{
	for (int a = 0; a <= pseudoStrlen(str2); ++a)
	{
		str1[a] = str2[a];
	}
	//str1[pseudoStrlen(str2)] = '\0';
}

void myStrcpy(char dest[], char src[])
{
	int index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
}

char toLower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 'a';
	}
	return c;
}

char toUpper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c - 'a' + 'A';
	}
	return c;
}

bool isVowel(char c)
{
	c = toLower(c);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void convertMonth(char month[])
{
	
	if (month[0] == '0')
	{
		switch (month[1])
		{
		case '1':
			strcpy(month, "January");
			return;
		case '2':
			strcpy(month, "February");
			return;
		case '3':
			strcpy(month, "March");
			return;
		case '4':
			strcpy(month, "April");
			return;
		case '5':
			strcpy(month, "May");
			return;
		case '6':
			strcpy(month, "June");
			return;
		case '7':
			strcpy(month, "July");
			return;
		case '8':
			strcpy(month, "August");
			return;
		case '9':
			strcpy(month, "September");
			return;
		default:
			strcpy(month, "SumTingWong");
			return;
		}
	}
	else
	{
		switch (month[1])
		{
		case '0':
			strcpy(month, "October");
			return;
		case '1':
			strcpy(month, "November");
			return;
		case '2':
			strcpy(month, "December");
			return;
		default:
			strcpy(month, "SumTingWong");
			return;
		}
	}
}

void question9()
{
	char line[256];
	std::cin.getline(line, 256);

	int wordCount = 0;
	int letterCount = 0;
	for (int i = 0; i < 256; i++)
	{
		char c = line[i];
		if (c == ' ')
		{
			wordCount++;
		}
		else
		{
			letterCount++;
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

	//char word[256];
	//char piglatin[256];

	//std::cin >> word;

	//if (isVowel(word[0]))
	//{
	//	strcpy(piglatin, word);
	//	strcat(piglatin, "yay");
	//}
	//else
	//{
	//	//word + 1 == "anana"
	//	int offset = 0;
	//	for (int i = 0; i < strlen(word); i++)
	//	{
	//		if (isVowel(word[i]))
	//		{
	//			offset = i;
	//			break;
	//		}
	//	}

	//	strcpy(piglatin, word + offset);
	//	int length = strlen(piglatin);

	//	for (int i = 0; i < offset; i++)
	//	{
	//		piglatin[length + i] = toLower(word[i]);
	//	}
	//	piglatin[length + offset] = '\0';

	//	strcat(piglatin, "ay");
	//}

	//piglatin[0] = toUpper(piglatin[0]);

	//std::cout << "Original: " << word << std::endl;
	//std::cout << "Piglatin: " << piglatin << std::endl;

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
	/*char test[256];

	std::cin >> test;

	int length = pseudoStrlen(test);

	int check = strlen(test);

	std::cout << length << " " << check;*/

	/*char test[256];
	char test2[256];

	std::cin >> test >> test2;

	int result = pseudoStrcmp(test, test2);

	std::cout << result;*/

	/*char test1[256];
	char test2[256];

	std::cin >> test1 >> test2;

	pseudoStrcat(test1, test2);

	std::cout << test1;*/

	/*char cpy1[256];
	char cpy2[256];


	std::cin >> cpy1;

	pseudoStrcpy(cpy2, cpy1);

	std::cout << cpy2;*/

	// 12)

	char line[256];
	std::cin.getline(line, 256);

	int index = 0;
	int count = 0;

	while (line)
	{

	}

	std::cout << line;

	// 13)

	/*char date[10];

	std::cin >> date;

	char day[3] = { date[0], date[1], '\0' };

	char month[15] = { date[3], date[4], '\0' };

	char year[5] = { date[6], date[7], date[8], date[9], '\0' };

	convertMonth(month);

	std::cout << "Date is " << month << " " << day << ", " << year;*/

	// 14)
	
	// 15)



	getch();
	return 0;
}


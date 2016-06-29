#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	// 1)

	// should work
	//int numbers[10] = { 0, 0, 1, 0, 0, 1, 0, 0, 1, 1 };

	// too many entries?
	//int matrix[5] = { 1, 2, 3, 4, 5, 6, 7 };

	//unmatch/incorrect bracket
	//double radii[10] = (3.2, 4.7};

	//can't have blank values
	//int table[7] = { 2, , , 27, , 45, 39 };

	//seems fine to me
	//char codes[] = { 'A', 'X', '1', '2', 's' };

	//looks like it should work but doesn't
	//int blanks[];

	//negative number?
	//int collection[-20];

	//no brackets
	//int hours[3] = 8, 12, 16;

	// 2)
	//int values[] = { 2, 6, 10, 14 };

	// a)

	//cout << values[2]<< std::endl;
	// should be 10

	// b)

	//cout << ++values[0];
	// display 2 then add 1 = 3

	// c)

	//cout << values[1]++;
	// displays 6 not too sure why

	// d)

	//x = 2;

	//cout << values[++x];
	//// missing value type for x declaration if int will display index 3 which is 14

	// e)

	//cout << values[4];
	// calling a value outside scope of array will return something unexpected

	// 3)

	//int data[10];

	//for (int i = 10; i > 0; i--)
	//{
	//	data[10 - i] = i;
	//}

	//for (int i : data)
	//{
	//	cout << i << endl;
	//}

	// 4)

	//int a, b, c, d, e;

	//cin >> a >> b >> c >> d >> e;

	//int numbers[5] = { a, b, c, d, e };

	//for (int i = 5; i > 0; --i)
	//{
	//	cout << numbers[i-1] << endl;
	//}
	//

	// 5)

	/*int a, b, c, d, e, f, g, h, i, j;

	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;

	int sort[10] = { a, b, c, d, e, f, g, h, i, j };

	int largestNumber = sort[0];

	int smallestNumber = sort[0];

	for (int x = 0; x < 10; x++)
	{
		if (largestNumber < sort[x])
		{
			largestNumber = sort[x];
		}
		if (smallestNumber > sort[x])
		{
			smallestNumber = sort[x];
		}
	}

	cout << "Numbers: ";

	for (int x : sort)
	{
		cout << x << " ";
	}

	cout << endl;

	cout << "Largest number is " << largestNumber << endl;

	cout << "Smallest number is " << smallestNumber << endl;
	*/

	// 6)

	/*int array[3][3];

	int counter = 1;

	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			array[a][b] = counter++;
			cout << array[a][b] << " ";
		}
		cout << endl;
	}*/

	// 7)


	/*int days[29][5];

	int sumDays1 = 0;

	int sumMonths1 = 0;

	for (int d = 0; d < 29; d++)
	{
		for (int m = 0; m < 5; m++)
		{
			days[d][m] = 1;
		}
	}

	int a, b;

	cout << "Sum of which day? (1-29)" << endl;

	cin >> a;

	cout << "Sum of which month? (1-5)" << endl;

	cin >> b;

	for (int d = 0; d < 29; d++)
	{
		for (int m = 0; m < 5; m++)
		{
			if (d == (a - 1))
			{
				sumMonths1 += days[d][m];
			}
			if (m == (b - 1))
			{
				sumDays1 += days[d][m];
			}
		}
	}

	cout << "Total of days " << sumDays1 << endl;
	cout << "Total of Months " << sumMonths1;*/

	// 8)

	int heroHealth[5] = { 100, 100, 100, 100, 100 };

	int attackChoice;

	int damage = 30;

	int wtf = 0;

	for (int a = 0; a < 5; a++)
	{
		cout << "Which hero would you like to attack? (1-5)" << endl;

		cin >> attackChoice;

		damage = 30;

		damage = damage + rand() % 25;

		damage = 30;

		damage = damage + rand() % 25;

		damage = 30;

		damage = damage + rand() % 25;

	
		if (heroHealth[attackChoice - 1] > 0)
		{
			heroHealth[attackChoice - 1] -= damage;
		}
		else if (wtf > 2)
		{
			cout << "I TOLD YOU HE'S ALREADY DEAD YOU DUMB CUNT" << endl; 
			cout << "YOU KNOW WHAT? THEY KILLED YOU WHILE YOU WERE ATTACKING A CORPSE" << endl;
			cout << "YOU DIED" << endl;
			break;
		}
		else
		{
			cout << "That hero is already dead pick another" << endl;
			--a;
			++wtf;
			continue;
		}

		cout << "You hit hero " << attackChoice << " for " << damage << endl;
	}

	cout << "The heroes have fled " << endl;

	for (int i = 0; i < 5; i++)
	{

		cout << "Hero " <<  i +1 << " has " << heroHealth[i] << " health left." << endl;
	}

	getch();
	system("pause");

	return 0;
}


#include <iostream>
#include <cstdio>

using namespace std;

struct Player
{
	char name[20];
	int health;
	int score;
	float position[1][1];
	float velocity;
};

struct Point2D
{
	int x;
	int y;
};

struct Item
{
	char itemName[20];
	int cost = 100;
	int stockRemaining = 3;
};

struct Shop
{

	int gold = 1000;
	Item items[10] = { {"Sword", 100, 3}, {"Bow", 125, 6}, {"Staff"} };
};

void q6()
{
	const int ksword = 0;
	const int kbow = 1;


	Shop shop;
	cout << shop.gold << " " << shop.items[ksword].cost;
}

struct rect
{
	Point2D a;
	Point2D e;
	Point2D c;
	Point2D d;
	float r;
	float g;
	float b;
};

void q2()
{
	Player player1 = {};
	cout << "Please input player name: ";
	cin >> player1.name;
	cout << "Please input score: ";
	cin >> player1.score;
	cout << "Character created." << endl;
	cout << "Character name: " << player1.name << endl;
	cout << "Character score: " << player1.score << endl;
}

Player q3()
{
	Player player1 = {};
	cout << "Please input player name: ";
	cin >> player1.name;
	cout << "Please input score: ";

	cin >> player1.score;
	//cout << "Character created." << endl;
	//cout << "Character name: " << player1.name << endl;
	//cout << "Character score: " << player1.score << endl;
	return player1;
}

void q4()
{
	Player partyMembers[5] = {};

	for (int i = 0; i < 5; i++)
	{
		partyMembers[i] = q3();
	}

	for (int i = 0; i < 5; i++)
	{
		cout << partyMembers[i].name << endl;
		cout << partyMembers[i].score << endl;
	}
}

void q5()
{
	Player partyMembers[5] = {};

	for (int i = 0; i < 5; i++)
	{
		partyMembers[i] = q3();
	}

	for (int i = 0; i < 5; i++)
	{
		cout << partyMembers[i].name << endl;
		cout << partyMembers[i].score << endl;
	}

	char find[256];

	cout << "Enter player to find: ";

	cin >> find;

	int found = 0;

	for (int i = 0; i < 5; i++)
	{
		if (strcmp(find, partyMembers[i].name) == 0)
		{
			cout << partyMembers[i].score << endl;
			found++;
		}
	}
	if (found == 0)
	{
		cout << "no matches found" << endl;
	}

}



int main()
{
	//q2();

	//q3
	//Player newPlayer = q3();

	//cout << newPlayer.name << endl;

	//q4();
	
	//q5();

	q6();

	system("PAUSE");
    return 0;
}


#include <iostream>
#include <cstdio>
#include "Zombie.h"
#include <time.h>
#include <string>

using namespace std;

void q1()
{
	Zombie test;

	test.setHealth(100);
	test.setAttack(10);
	test.setOccupation("Accountant");
	
	test.printStats();
}

void q2()
{
	srand(time(NULL));

	Zombie zombies[3];

	int zombieCount = 3;
	int zombiesRemaining = zombieCount;

	for (int i = 0; i < zombiesRemaining; i++)
	{
		zombies[i].quickSet();
	}

	while (zombiesRemaining > 1)
	{
		for (int i = 0; i < zombieCount; i++)
		{
			int attackee = rand() % zombieCount;
			attackee = rand() % zombieCount;
			attackee = rand() % zombieCount;

			if (i == attackee && zombies[i].getIsAlive() == true)
			{
				cout << "Zombie" << i + 1 << " misses" << endl;
				_sleep(300);
			}
			if (i != attackee && zombies[attackee].getIsAlive() == true && zombies[i].getIsAlive() == true)
			{
				cout << "Zombie" << i + 1 << " attacks zombie" << attackee + 1 << " for ";
				zombies[i].attackTarget(zombies[attackee]);
				cout << " damage (" << zombies[attackee].getHealth() << ")" << endl;
				_sleep(300);

				if (zombies[attackee].getHealth() < 1)
				{
					zombies[attackee].killed();
					zombiesRemaining--;
					cout << "Zombie" << attackee + 1 << " has died" << endl;
				}
			}
		}
	}

	for (int i = 0; i < zombieCount; i++)
	{
		cout << "Zombie " << i + 1 << " remaing Health: " << zombies[i].getHealth() << endl;
	}

}

int main()
{
	//q1();

	q2();

	system("pause");
    return 0;
}


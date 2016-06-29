#pragma once

class Zombie
{
	int health;
	int attack;

	char occupation[50];

	bool isAlive = true;

public:
	Zombie();

	void setHealth(int health);

	void setAttack(int atk);

	void setOccupation(char job[]);

	void printStats();

	void quickSet();

	void attackTarget(Zombie& target);

	int getHealth();

	void killed();

	bool getIsAlive();

	
};
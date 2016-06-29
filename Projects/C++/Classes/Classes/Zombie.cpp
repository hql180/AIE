#include "Zombie.h"
#include <iostream>
#include <string>

using namespace std;

Zombie::Zombie()
{
	health = 100;
	attack = 9;
}

void Zombie::setHealth(int health)
{
	this->health = health;
	// take note
}

void Zombie::setAttack(int atk)
{
	attack = atk;
}

void Zombie::setOccupation(char job[])
{
	strcpy(occupation, job);
}

void Zombie::printStats()
{
	cout << "Health: " << health << endl;
	cout << "Attack: " << attack << endl;
	cout << "Occupation: " << occupation << endl;
}

void Zombie::quickSet()
{
	health = 100;
	attack = 8;
	strcpy(occupation, "Full-Time Zombie");
}

void Zombie::attackTarget(Zombie& target)
{
	int damage = attack + rand() % 7;
	damage = attack + rand() % 7;
	damage = attack + rand() % 7;
	target.health -= damage;
	cout << damage;
}

int Zombie::getHealth()
{
	return health;
}

void Zombie::killed()
{
	isAlive = false;
}

bool Zombie::getIsAlive()
{
	return isAlive;
}
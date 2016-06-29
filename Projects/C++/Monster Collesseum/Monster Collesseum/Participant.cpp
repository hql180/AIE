#include "Participant.h"
#include <iostream>
#include <cstdlib>

int Participant::_globalID = 0;

Participant::Participant()
{
	_health = 100;
	_armour = 5;
	_damage = 10;
	_id = ++_globalID;
}

Participant::~Participant()
{
}

int Participant::Attack()
{
	int randSwing = _damage * .3;
	if (randSwing < 3)
	{
		randSwing = 3;
	}
	int damage = _damage - randSwing;
	damage = rand() % randSwing + (damage + 1);
	damage = rand() % randSwing + (damage + 1);

	return damage;
}

int Participant::UpdateHealth(int value)
{
	int damage = value - _armour;
	if (damage < 0)
	{
		damage = 1;
	}
	_health -= damage;

	return damage;
}

int Participant::GetHeath()
{
	return _health;
}

void Participant::GetClass()
{
	std::cout << _participant;
}

int Participant::GetID()
{
	return _id;
}






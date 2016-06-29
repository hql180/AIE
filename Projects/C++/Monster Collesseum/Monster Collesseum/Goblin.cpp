#include "Goblin.h"
#include <iostream>


Goblin::Goblin() : Participant()
{
	_health *= .7;
	_armour *= 1.3;
	_damage *= 1.2;
	strcpy(_participant, "Goblin");
}


Goblin::~Goblin()
{
}

int Goblin::Attack()
{
	return Participant::Attack();
}

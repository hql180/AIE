#include "HugeRat.h"
#include <iostream>

HugeRat::HugeRat() : Participant()
{
	_health = 20;
	_armour = 0;
	_damage = 3;
	strcpy(_participant, "Huge Rat");
}


HugeRat::~HugeRat()
{
}

int HugeRat::Attack()
{
	return Participant::Attack();
}

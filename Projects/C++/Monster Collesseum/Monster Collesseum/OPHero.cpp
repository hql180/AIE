#include "OPHero.h"
#include <iostream>


OPHero::OPHero() : Participant()
{
	_health *= 2;
	_armour *= 1;
	_damage *= 2;
	strcpy(_participant, "OP Hero");
}


OPHero::~OPHero()
{
}

int OPHero::Attack()
{
	return Participant::Attack();
}

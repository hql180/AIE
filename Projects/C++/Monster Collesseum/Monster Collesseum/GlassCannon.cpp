#include "GlassCannon.h"
#include <iostream>

GlassCannon::GlassCannon() : Participant()
{
	_health *= .4;
	_armour = 0;
	_damage *= 4;
	strcpy(_participant, "Glass Cannon");
}


GlassCannon::~GlassCannon()
{
}

int GlassCannon::Attack()
{
	return Participant::Attack();
}

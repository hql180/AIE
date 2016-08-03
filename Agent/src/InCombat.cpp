#include "InCombat.h"




InCombat::InCombat()
{
}


InCombat::~InCombat()
{
}

Status InCombat::update(Agent* agent, Application2D* pA2D, float dt)
{
	if (agent->combatTimer > 0) // Timer checks if attacked another target or under attack
		return SUCCESS; 
	return FAILURE;
}

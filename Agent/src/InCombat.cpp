#include "InCombat.h"




InCombat::InCombat()
{
}


InCombat::~InCombat()
{
}

Status InCombat::update(Agent * agent, float dt)
{
	if (agent->combatTimer <= 0)
		return SUCCESS;
	return FAILURE;
}

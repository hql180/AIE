#include "LowHealth.h"



LowHealth::LowHealth()
{
}


LowHealth::~LowHealth()
{
}

Status LowHealth::update(Agent* agent, Application2D* pA2D, float dt)
{
	if ((float)agent->HP / (float)agent->maxHP <= .35f)
		return SUCCESS;
	return FAILURE;
}

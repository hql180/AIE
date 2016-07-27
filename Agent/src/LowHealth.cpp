#include "LowHealth.h"



LowHealth::LowHealth()
{
}


LowHealth::~LowHealth()
{
}

Status LowHealth::update(Agent * agent, float dt)
{
	if ((float)agent->HP / (float)agent->maxHP <= .30f)
		return SUCCESS;
	return FAILURE;
}

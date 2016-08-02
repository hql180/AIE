#include "IsDead.h"

IsDead::IsDead()
{
}


IsDead::~IsDead()
{
}

Status IsDead::update(Agent * agent, Application2D * pA2D, float dt)
{
	if (agent->HP <= 0)
	{
		agent->isDead = true;
		//agent->velocity = Vector3(0, 0, 0);
		return SUCCESS;
	}
	return FAILURE;
}

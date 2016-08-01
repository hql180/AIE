#include "InRange.h"



InRange::InRange()
{
}


InRange::~InRange()
{
}

Status InRange::update(Agent * agent, Application2D * pA2D, float dt)
{
	if (agent->target)
		if ((agent->target->position - agent->position).magnitude() <= agent->attackRange)
			return SUCCESS;
	return FAILURE;
}

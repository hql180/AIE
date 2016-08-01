#include "Pursue.h"


Pursue::Pursue()
{
}


Pursue::~Pursue()
{
}

Status Pursue::update(Agent* agent, Application2D* pA2D, float dt)
{
	if (agent->target)
	{
		Vector3 force = Vector3::normalise(agent->target->position + agent->target->velocity - agent->position) * agent->maxVelocity;

		agent->AddForce(force - agent->velocity);

		return SUCCESS;
	}

	return FAILURE;
}

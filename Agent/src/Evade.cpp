#include "Evade.h"



Evade::Evade()
{
}


Evade::~Evade()
{
}

Status Evade::update(Agent* agent, Application2D* pA2D, float dt)
{
	if (agent->fleeTarget)
	{
		Vector3 force = Vector3::normalise(agent->position + agent->velocity - agent->fleeTarget->position) * agent->maxVelocity;

		agent->AddForce(force - agent->velocity);

		return SUCCESS;
	}

	return FAILURE;
}

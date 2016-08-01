#include "Flee.h"



Flee::Flee()
{
}


Flee::~Flee()
{
}

Status Flee::update(Agent* agent, Application2D* pA2D, float dt)
{
	if (agent->fleeTarget)
	{
		Vector3 force = Vector3::normalise(agent->position - agent->fleeTarget->position) * agent->maxVelocity;

		agent->AddForce(force - agent->velocity);

		return SUCCESS;
	}

	return FAILURE;
}

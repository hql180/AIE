#include "Flee.h"



Flee::Flee()
{
}


Flee::~Flee()
{
}

void Flee::update(Agent * agent, float dt)
{
	if (agent->fleeTarget)
	{
		Vector3 force = Vector3::normalise(agent->position - agent->fleeTarget->position) * agent->maxVelocity;

		agent->AddForce(force - agent->velocity);
	}
}

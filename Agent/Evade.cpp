#include "Evade.h"



Evade::Evade()
{
}


Evade::~Evade()
{
}

void Evade::update(Agent * agent, float dt)
{
	if (agent->fleeTarget)
	{
		Vector3 force = Vector3::normalise(agent->position + agent->velocity - agent->fleeTarget->position) * agent->maxVelocity;

		agent->AddForce(force - agent->velocity);
	}
}

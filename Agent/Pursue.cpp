#include "Pursue.h"


Pursue::Pursue()
{
}


Pursue::~Pursue()
{
}

void Pursue::update(Agent * agent, float dt)
{
	if (agent->target)
	{
		Vector3 force = Vector3::normalise(agent->target->position + agent->target->velocity - agent->position) * agent->maxVelocity;

		agent->AddForce(force - agent->velocity);
	}
}

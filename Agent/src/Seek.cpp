#include "Seek.h"



Seek::Seek()
{
}


Seek::~Seek()
{
}

void Seek::update(Agent * agent, float dt)
{
	if (agent->target)
	{
		Vector3 force = Vector3::normalise(agent->target->position - agent->position) * agent->maxVelocity;

		agent->AddForce(force - agent->velocity);
	}
}

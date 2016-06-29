#include "Seek.h"



Seek::Seek()
{
}


Seek::~Seek()
{
}

void Seek::update(Agent * agent, float dt)
{
	Vector3 force = Vector3::normalise(agent->target->position - agent->position) * agent->maxVelocity;

	Vector3 forceToApply = force - agent->velocity;
}

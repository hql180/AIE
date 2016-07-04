#include "Flee.h"



Flee::Flee()
{
}


Flee::~Flee()
{
}

void Flee::update(Agent * agent, float dt)
{
	Vector3 force = Vector3::normalise(agent->position - agent->target->position) * agent->maxVelocity;

	agent->AddForce(force - agent->velocity);
}

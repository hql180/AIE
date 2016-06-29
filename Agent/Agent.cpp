#include "Agent.h"
#include "IBehaviour.h"


Agent::Agent()
{
}


Agent::~Agent()
{
}

void Agent::AddForce(float dt)
{
	velocity = velocity + acceleration * dt;
	position = position + velocity * dt;
}

void Agent::update(float dt)
{
	for (auto const& it : behaviourList)
		it->update(this, dt);
}

void Agent::draw(SpriteBatch * spriteBatch)
{
}


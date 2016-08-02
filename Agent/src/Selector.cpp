#include "Selector.h"



Selector::Selector()
{
}


Selector::~Selector()
{
}

Status Selector::update(Agent* agent, Application2D* pA2D, float dt)
{
	for (auto & c : childBehaviours)
		if (c->update(agent, pA2D, dt) == SUCCESS)
			return SUCCESS;
	return FAILURE;
}

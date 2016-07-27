#include "Selector.h"



Selector::Selector()
{
}


Selector::~Selector()
{
}

Status Selector::update(Agent * agent, float dt)
{
	for (auto & c : childBehaviours)
		if (c.update(agent, dt) == SUCCESS)
			return SUCCESS;
	return FAILURE;
}

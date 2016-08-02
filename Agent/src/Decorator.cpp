#include "Decorator.h"



Decorator::Decorator()
{
}


Decorator::~Decorator()
{
}

Status Decorator::update(Agent * agent, Application2D * pA2D, float dt)
{
	for (auto child : childBehaviours)
	{
		if (child->update(agent, pA2D, dt) == FAILURE)
			return SUCCESS;
		else if (child->update(agent, pA2D, dt) == SUCCESS)
			return FAILURE;
	}
	return FAILURE;
}

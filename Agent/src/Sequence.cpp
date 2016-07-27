
#include "Sequence.h"


Sequence::Sequence()
{
}


Sequence::~Sequence()
{
}

Status Sequence::update(Agent * agent, float dt)
{
	for (auto & c : childBehaviours)
		if (c.update(agent, dt) == FAILURE)
			return FAILURE;
	return SUCCESS;
}

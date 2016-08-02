
#include "Sequence.h"


Sequence::Sequence()
{
}


Sequence::~Sequence()
{
}

Status Sequence::update(Agent* agent, Application2D* pA2D, float dt)
{
	for (auto & c : childBehaviours)
		if (c->update(agent, pA2D, dt) == FAILURE)
			return FAILURE;
	return SUCCESS;
}

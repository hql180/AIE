#pragma once
#include "IBehaviour.h"
class InCombat :
	public IBehaviour
{
public:
	InCombat();
	~InCombat();

	virtual Status update(Agent* agent, float dt);
};


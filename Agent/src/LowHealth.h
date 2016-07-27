#pragma once
#include "IBehaviour.h"
class LowHealth :
	public IBehaviour
{
public:
	LowHealth();
	~LowHealth();

	virtual Status update(Agent* agent, float dt);
};


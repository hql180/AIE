#pragma once

#include "IBehaviour.h"

#include <vector>

class Agent;

class Composite :
	public IBehaviour
{
public:
	Composite();
	~Composite();
	
	virtual Status update(Agent* agent, float dt) = 0;

	std::vector<IBehaviour> childBehaviours;
};


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
	
	virtual Status update(Agent* agent, Application2D* pA2D, float dt) = 0;

};


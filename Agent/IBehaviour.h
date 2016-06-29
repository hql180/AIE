#pragma once
#include "Agent.h"

class IBehaviour 
{
public:
	IBehaviour();
	~IBehaviour();

	virtual void update(Agent* agent, float dt) = 0;
};


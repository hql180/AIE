#pragma once
#include "IBehaviour.h"
class Flee :
	public IBehaviour
{
public:
	Flee();
	~Flee();

	virtual Status update(Agent* agent, float dt);
};


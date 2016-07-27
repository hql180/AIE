#pragma once
#include "IBehaviour.h"
class LineOfSight :
	public IBehaviour
{
public:
	LineOfSight();
	~LineOfSight();

	virtual Status update(Agent* agent, float dt);
};


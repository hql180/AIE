#pragma once
#include "IBehaviour.h"
#include "Application2D.h"

class LineOfSight :
	public IBehaviour
{
public:
	LineOfSight();
	~LineOfSight();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


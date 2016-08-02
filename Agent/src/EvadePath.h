#pragma once
#include "IBehaviour.h"
class EvadePath :
	public IBehaviour
{
public:
	EvadePath();
	~EvadePath();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


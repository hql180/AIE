#pragma once
#include "IBehaviour.h"
class LowHealth :
	public IBehaviour
{
public:
	LowHealth();
	~LowHealth();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


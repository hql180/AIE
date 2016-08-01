#pragma once
#include "IBehaviour.h"
class InRange :
	public IBehaviour
{
public:
	InRange();
	~InRange();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


#pragma once
#include "IBehaviour.h"
class IsDead :
	public IBehaviour
{
public:
	IsDead();
	~IsDead();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


#pragma once
#include "IBehaviour.h"
class Attack :
	public IBehaviour
{
public:
	Attack();
	~Attack();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


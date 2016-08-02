#pragma once
#include "IBehaviour.h"
class Heal :
	public IBehaviour
{
public:
	Heal();
	~Heal();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


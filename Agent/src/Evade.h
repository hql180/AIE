#pragma once
#include "IBehaviour.h"

class Evade :
	public IBehaviour
{
public:
	Evade();
	~Evade();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


#pragma once
#include "IBehaviour.h"
class SelectTarget :
	public IBehaviour
{
public:
	SelectTarget();
	~SelectTarget();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


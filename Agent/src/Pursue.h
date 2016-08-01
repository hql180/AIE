#pragma once
#include "IBehaviour.h"
class Pursue :
	public IBehaviour
{
public:
	Pursue();
	~Pursue();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


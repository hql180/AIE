#pragma once
#include "IBehaviour.h"
class Flee :
	public IBehaviour
{
public:
	Flee();
	~Flee();

	virtual void update(Agent* agent, float dt);
};


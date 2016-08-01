#pragma once

#include "Composite.h"

class Selector :
	public Composite
{
public:
	Selector();
	~Selector();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


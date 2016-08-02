#pragma once
#include "Composite.h"
class Decorator :
	public Composite
{
public:
	Decorator();
	~Decorator();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


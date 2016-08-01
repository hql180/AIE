#pragma once
#include "Composite.h"
class Sequence :
	public Composite
{
public:
	Sequence();
	~Sequence();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);

};


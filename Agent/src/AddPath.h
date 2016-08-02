#pragma once
#include "IBehaviour.h"
class AddPath :
	public IBehaviour
{
public:
	AddPath();
	~AddPath();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


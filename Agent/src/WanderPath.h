#pragma once
#include "IBehaviour.h"
class WanderPath :
	public IBehaviour
{
public:
	WanderPath();
	~WanderPath();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);

	Vector3 displacement;
};


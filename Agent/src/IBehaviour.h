#pragma once
#include "Agent.h"

class IBehaviour 
{
public:
	IBehaviour();
	~IBehaviour();

	static Vector3 truncate(Vector3 vec, float max);

	virtual void update(Agent* agent, float dt) = 0;
};


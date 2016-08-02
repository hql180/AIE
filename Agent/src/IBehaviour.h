#pragma once
#include "Agent.h"


enum Status
{
	INVALID,
	SUCCESS,
	FAILURE,
	RUNNING,
	PENDING
};

class IBehaviour 
{
public:
	IBehaviour() : eStatus(INVALID) {};
	~IBehaviour();

	static Vector3 truncate(Vector3 vec, float max);

	virtual Status update(Agent* agent, Application2D* pA2D, float dt) = 0;

	Status eStatus;

	std::vector<IBehaviour*> childBehaviours;
};


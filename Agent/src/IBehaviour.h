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
	IBehaviour() : eStatus(INVALID), observer(nullptr) {};
	~IBehaviour();

	static Vector3 truncate(Vector3 vec, float max);

	virtual Status update(Agent* agent, float dt) = 0;

	Status eStatus;

	IBehaviour* observer;
};


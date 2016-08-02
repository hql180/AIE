#pragma once
#include "IBehaviour.h"
class SeekPath :
	public IBehaviour
{
public:
	SeekPath();
	~SeekPath();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);
};


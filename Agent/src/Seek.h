#pragma once
#include "IBehaviour.h"
class Seek : public IBehaviour
{
public:
	Seek();
	virtual ~Seek();

	virtual Status update(Agent* agent, float dt);
};


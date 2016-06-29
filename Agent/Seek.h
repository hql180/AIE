#pragma once
#include "IBehaviour.h"
class Seek : public IBehaviour
{
public:
	Seek();
	virtual ~Seek();

	virtual void update(Agent* agent, float dt);
};


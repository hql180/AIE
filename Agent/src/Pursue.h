#pragma once
#include "C:\Users\huy.le\Documents\AIE\Agent\src\IBehaviour.h"
class Pursue :
	public IBehaviour
{
public:
	Pursue();
	~Pursue();

	virtual void update(Agent* agent, float dt);
};


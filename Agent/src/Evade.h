#pragma once
#include "C:\Users\huy.le\Documents\AIE\Agent\src\IBehaviour.h"
class Evade :
	public IBehaviour
{
public:
	Evade();
	~Evade();

	virtual Status update(Agent* agent, float dt);
};


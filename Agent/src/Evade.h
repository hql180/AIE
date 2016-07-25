#pragma once
#include "C:\Users\huy.le\Documents\AIE\Agent\src\IBehaviour.h"
class Evade :
	public IBehaviour
{
public:
	Evade();
	~Evade();

	virtual void update(Agent* agent, float dt);
};


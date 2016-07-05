#pragma once

#include "Agent.h"
#include "StateMachine.h"

class State
{
public:
	State();
	~State();

	virtual void enter(Agent* pAgent, StateMachine* pSM, float dt) = 0;

	virtual void update(Agent* pAgent, StateMachine* pSM, float dt) = 0;

	virtual void exit(Agent* pAgent, StateMachine* pSM, float dt) = 0;

};


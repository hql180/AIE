#pragma once
#include "State.h"
#include "Agent.h"

class AttackState :
	public State
{
public:
	AttackState();
	~AttackState();

	virtual void enter(Agent* pAgent);

	virtual void update(Agent* pAgent, StateMachine* pSM, float dt);

	virtual void exit(Agent* pAgent);

private:
	WayPoint mouseLocation;
};


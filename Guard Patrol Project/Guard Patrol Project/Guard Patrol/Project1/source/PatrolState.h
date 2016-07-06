#pragma once
#include "State.h"
#include "Agent.h"
#include <vector>

class PatrolState :
	public State
{
public:
	PatrolState();
	~PatrolState();

	virtual void enter(Agent* pAgent);

	virtual void update(Agent* pAgent, StateMachine* pSM, float dt);

	virtual void exit(Agent* pAgent);

private:
	std::vector<WayPoint> patrolPath;
};


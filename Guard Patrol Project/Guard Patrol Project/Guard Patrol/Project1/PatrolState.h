#pragma once
#include "C:\Users\huy.le\Documents\AIE\Guard Patrol Project\Guard Patrol Project\Guard Patrol\Project1\source\State.h"
class PatrolState :
	public State
{
public:
	PatrolState();
	~PatrolState();

	virtual void enter(Agent* pAgent, StateMachine* pSM, float dt);

	virtual void update(Agent* pAgent, StateMachine* pSM, float dt);

	virtual void exit(Agent* pAgent, StateMachine* pSM, float dt);
};


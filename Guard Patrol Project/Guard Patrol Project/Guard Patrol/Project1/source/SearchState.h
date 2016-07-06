#pragma once
#include "State.h"

class SearchState :
	public State
{
public:
	SearchState();
	~SearchState();

	virtual void enter(Agent* pAgent);

	virtual void update(Agent* pAgent, StateMachine* pSM, float dt);

	virtual void exit(Agent* pAgent);


};


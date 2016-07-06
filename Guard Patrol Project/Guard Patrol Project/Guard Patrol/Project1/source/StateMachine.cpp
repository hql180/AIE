#include "StateMachine.h"
#include "State.h"


StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
}

void StateMachine::update(Agent * pAgent, float dt)
{
	if (current)
		current->update(pAgent, this, dt);
}

void StateMachine::changeState(Agent * pAgent, State * newState)
{
	if (newState)
		if (current)
		{
			if (prev)
				delete prev;
			prev = current;
			current->exit(pAgent);
			newState->enter(pAgent);
			current = newState;
		}

}

State * StateMachine::getCurrentState()
{
	if (current)
		return current;
	return nullptr;
}

State * StateMachine::getPrevState()
{
	if (prev)
		return prev;
	return nullptr;
}

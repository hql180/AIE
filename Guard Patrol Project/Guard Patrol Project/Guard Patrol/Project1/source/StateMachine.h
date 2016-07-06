#pragma once
class Agent;
class State;
class StateMachine
{
public:
	StateMachine();
	virtual ~StateMachine();

	void update(Agent* pAgent, float dt);

	void changeState(Agent* pAgent, State* newState);

	State* getCurrentState();

	State* getPrevState();

private:
	State* current;
	State* prev;
};


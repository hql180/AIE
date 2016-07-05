#pragma once
class Agent;
class State;
class StateMachine
{
public:
	StateMachine();
	virtual ~StateMachine();

	void update(float dt);

	void changeState(Agent* pAgent, State* pState);

	State* getCurrentState();

	State* getPrevState();

private:
	State* current;
	State* prev;
};


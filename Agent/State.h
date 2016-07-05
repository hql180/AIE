#pragma once

class Agent;
class State
{
public:
	State();
	~State();

	virtual void enter(Agent* agent, float dt) = 0;

	virtual void update(Agent* agent, float dt) = 0;

	virtual void exit(Agent* agent, float dt) = 0;
};


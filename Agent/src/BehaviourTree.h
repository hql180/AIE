#pragma once

#include <deque>
#include "IBehaviour.h"

class BehaviourTree
{
public:
	BehaviourTree();
	~BehaviourTree();

	void insert(IBehaviour& bh, IBehaviour* observer = NULL);

	void terminate(IBehaviour& bh, Status result);

	void tick();

	bool step();

protected:
	std::deque<IBehaviour*> behaviours;
};


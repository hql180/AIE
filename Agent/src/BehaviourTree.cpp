#include "BehaviourTree.h"



BehaviourTree::BehaviourTree()
{
}


BehaviourTree::~BehaviourTree()
{
}

void BehaviourTree::insert(IBehaviour & bh, IBehaviour * observer)
{

}

void BehaviourTree::terminate(IBehaviour & bh, Status result)
{
	bh.eStatus = result;

	/*if (bh.observer)
		bh.observer->*/
}

void BehaviourTree::tick()
{
	behaviours.push_back(NULL);

	while (step())
		continue;
}

bool BehaviourTree::step()
{
	IBehaviour* current = behaviours.front();
	behaviours.pop_front();

	if (current == NULL)
		return false;

	//current->tick();


}

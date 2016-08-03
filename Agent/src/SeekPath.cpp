#include "SeekPath.h"
#include "Seek.h"


SeekPath::SeekPath()
{
}


SeekPath::~SeekPath()
{
}

Status SeekPath::update(Agent * agent, Application2D * pA2D, float dt)
{
	if (!agent->path.empty())
	{
		agent->combatTimer -= dt;
		Vector3 force = Vector3::normalise(Vector3(agent->path.front()->pos.x, agent->path.front()->pos.y, 1) - agent->position) * agent->maxVelocity;
		
		if ((Vector3(agent->path.front()->pos.x, agent->path.front()->pos.y, 1) - agent->position).magnitude() < 20)
		{			
			agent->path.pop_front();
			if (!agent->path.empty())
				agent->currentNode = agent->path.front();
				
		}
		agent->AddForce(force - agent->velocity);

		return SUCCESS;		
	}
	return FAILURE;
}

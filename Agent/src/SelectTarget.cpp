#include "SelectTarget.h"
#include "Application2D.h"

#include <vector>
#include <algorithm>
#include <math.h>


SelectTarget::SelectTarget()
{
}


SelectTarget::~SelectTarget()
{
}

Status SelectTarget::update(Agent * agent, Application2D * pA2D, float dt)
{
	std::vector<Agent*> potentialTargets;
	for (auto target : pA2D->agents)
		if ((target->position - agent->position).magnitude() <= agent->visionRange)
			if (target != agent)
				potentialTargets.push_back(target);

	if (potentialTargets.empty())
		return FAILURE;

	std::sort(potentialTargets.begin(), potentialTargets.end(), 
		[agent](Agent* a, Agent* b) 
	{
		return (a->position - agent->position).magnitude() < (b->position - agent->position).magnitude(); 
	});

	for (auto target : potentialTargets)
	{
		float angleToTarget = acosf(Vector3::normalise(agent->velocity).dot(Vector3::normalise(target->position)));
		if (angleToTarget <= agent->maxViewAngle)
		{
			Vector3 rayToTarget = Vector3::normalise(target->position - agent->position);

			bool treeInWay = false;
			for (auto tree : pA2D->trees)
			{
				// Tree position projected onto raycast
				Vector3 treeProjectedPos = tree->position - agent->position;
				float projection = rayToTarget.dot(treeProjectedPos);
				// clamp projection between 0 and distance from target;

				float distanceFromTarget = (target->position - agent->position).magnitude();
				// to clamp projection scalar
				float min = std::min(0.0f, distanceFromTarget);
				float max = std::max(0.0f, distanceFromTarget);

				if (projection < min)
					projection = min;
				else if
					(projection > max)
					projection = max;

				treeProjectedPos = agent->position + projection * rayToTarget;

				float distance = (treeProjectedPos - tree->position).magnitude();

				if (distance < tree->radius)
				{
					treeInWay = true;
				}
			}
			if (treeInWay == false)
			{
				agent->target = target;
				return SUCCESS;
			}
		}
	}

	return FAILURE;

}

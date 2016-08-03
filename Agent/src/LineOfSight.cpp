#include "LineOfSight.h"
#include "Vector3.h"
#include "Application2D.h"

#include <math.h>
#include <algorithm>

LineOfSight::LineOfSight()
{
}


LineOfSight::~LineOfSight()
{
}

Status LineOfSight::update(Agent* agent, Application2D* pA2D, float dt)
{
	if (agent->target)
	{
		float distanceFromTarget = (agent->target->position - agent->position).magnitude();
		if (distanceFromTarget <= agent->visionRange)
		{
			float angleToTarget = acosf(Vector3::normalise(agent->velocity).dot(Vector3::normalise(agent->target->position)));
			if (angleToTarget <= agent->maxViewAngle)
			{
				Vector3 rayToTarget = Vector3::normalise(agent->target->position - agent->position);
				for (auto tree : pA2D->trees)
				{
					// Tree position projected onto raycast
					Vector3 treeProjectedPos = tree->position - agent->position;
					float projection = rayToTarget.dot(treeProjectedPos);
					// clamp projection between 0 and distance from target;

					// to clamp projection scalar
					float min = std::min(0.f, distanceFromTarget);
					float max = std::max(0.f, distanceFromTarget);
					
					if (projection < min)
						projection = min;
					else if
						(projection > max)
						projection = max;

					treeProjectedPos = agent->position + projection * rayToTarget;

					float distance = (treeProjectedPos - tree->position).magnitude();

					if (distance < tree->radius)
					{
						return FAILURE;
					}
				}
				return SUCCESS;
			}
		}
	}
	return FAILURE;
}
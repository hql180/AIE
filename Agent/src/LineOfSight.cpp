#include "LineOfSight.h"
#include "Vector3.h"
#include "Application2D.h"
#include <math.h>

LineOfSight::LineOfSight()
{
}


LineOfSight::~LineOfSight()
{
}

Status LineOfSight::update(Agent * agent, float dt)
{
	float distanceFromTarget = Vector3::magnitude(agent->target->position - agent->position);
	if (distanceFromTarget <= agent->visionRange)
	{
		if (acosf(Vector3::normalise(agent->velocity).dot(Vector3::normalise(agent->target->position))) <= agent->maxViewAngle)
		{
			Vector3 rayToTarget = Vector3::normalise(agent->target->position - agent->position) * agent->visionRange;


		}
	}
		


	

}
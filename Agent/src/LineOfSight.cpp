#include "LineOfSight.h"
#include "Vector3.h"

LineOfSight::LineOfSight()
{
}


LineOfSight::~LineOfSight()
{
}

Status LineOfSight::update(Agent * agent, float dt)
{
	if (Vector3::magnitude(agent->position - agent->target->position) < agent->visionRange);

	

}
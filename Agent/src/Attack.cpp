#include "Attack.h"
#include "Arrow.h"
#include "Application2D.h"

Attack::Attack()
{
}


Attack::~Attack()
{
}

Status Attack::update(Agent * agent, Application2D * pA2D, float dt)
{
	if (agent->target)
	{
		if (agent->attackTime > 0)
			agent->attackTime -= dt;

		if (agent->attackTime <= 0)
		{
			pA2D->arrows.push_back(new Arrow(agent, pA2D));
			agent->attackTime = agent->maxAttackTime;
			agent->combatTimer = 5;
			return SUCCESS;
		}
	}
	return FAILURE;
}

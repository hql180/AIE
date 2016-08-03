#include "Heal.h"



Heal::Heal()
{
}


Heal::~Heal()
{
}

Status Heal::update(Agent * agent, Application2D * pA2D, float dt)
{
	if (agent->HP < agent->maxHP)
	{
		agent->path.clear();
		agent->HP += (40 * dt);
		return SUCCESS;
	}
	else
	{
		agent->HP = agent->maxHP;
		return FAILURE;
	}
}

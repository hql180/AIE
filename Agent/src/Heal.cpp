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
		agent->HP += (20 * dt);
		return SUCCESS;
	}
	else if(agent->HP > agent->maxHP)
	{
		agent->HP = agent->maxHP;
	}
	return SUCCESS;
}

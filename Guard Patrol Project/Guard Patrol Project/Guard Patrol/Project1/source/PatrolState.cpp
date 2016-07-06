#include "PatrolState.h"
#include "Input.h"
#include "AttackState.h"

#include <algorithm>


PatrolState::PatrolState()
{
}


PatrolState::~PatrolState()
{
}

void PatrolState::enter(Agent * pAgent)
{
	patrolPath.push_back(WayPoint(100, 100));
	patrolPath.push_back(WayPoint(100, 400));
	patrolPath.push_back(WayPoint(400, 400));
	patrolPath.push_back(WayPoint(400, 100));

	pAgent->m_path = &patrolPath.front();
	pAgent->SetColour(Green);
}

void PatrolState::update(Agent * pAgent, StateMachine * pSM, float dt)
{
	if (pAgent->GetDistanceFromTarget(patrolPath.front().x, patrolPath.front().y) < 1)
	{
		std::rotate(patrolPath.begin(), patrolPath.begin() + 1, patrolPath.end());
		pAgent->m_path = &patrolPath.front();
	}

	if (pAgent->GetDistanceFromTarget(Input::GetSingleton()->GetMouseX(), Input::GetSingleton()->GetMouseY()) < pAgent->m_nSightRange)
		pSM->changeState(pAgent, new AttackState());
}

void PatrolState::exit(Agent * pAgent)
{
}

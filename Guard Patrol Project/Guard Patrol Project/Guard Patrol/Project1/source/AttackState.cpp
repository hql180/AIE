#include "AttackState.h"
#include "Input.h"
#include "SearchState.h"


AttackState::AttackState()
{
}


AttackState::~AttackState()
{
}

void AttackState::enter(Agent * pAgent)
{
	pAgent->SetColour(Red);
	mouseLocation = WayPoint(Input::GetSingleton()->GetMouseX(), Input::GetSingleton()->GetMouseY());
	pAgent->m_path = &mouseLocation;
}

void AttackState::update(Agent * pAgent, StateMachine * pSM, float dt)
{
	if(pAgent->GetDistanceFromTarget(Input::GetSingleton()->GetMouseX(), Input::GetSingleton()->GetMouseY()) < pAgent->m_nSightRange)
		mouseLocation = WayPoint(Input::GetSingleton()->GetMouseX(), Input::GetSingleton()->GetMouseY());

	if (pAgent->GetDistanceFromTarget(mouseLocation.x, mouseLocation.y) < 1)
	{
		if (pAgent->GetDistanceFromTarget(Input::GetSingleton()->GetMouseX(), Input::GetSingleton()->GetMouseY()) > pAgent->m_nSightRange)
			pSM->changeState(pAgent, new SearchState());
	}
	
}

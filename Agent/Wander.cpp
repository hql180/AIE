#include "Wander.h"



Wander::Wander()
{
	radius = 25;
	jitter = 25;
	distance = 25;
	decisionTime = 0;
}


Wander::~Wander()
{
}

void Wander::update(Agent * agent, float dt)
{
	//if(decisionTime += dt > 50)

	Vector3 circleCenter;
	circleCenter = agent->velocity;
	circleCenter.normalise();
	circleCenter = circleCenter * distance;

	Vector3 displacement(0, -1, 0);


}

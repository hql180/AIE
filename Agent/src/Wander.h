#pragma once
#include "IBehaviour.h"
class Wander :
	public IBehaviour
{
public:
	Wander();
	~Wander();

	virtual Status update(Agent* agent, Application2D* pA2D, float dt);

	void setAngle(Vector3& displacement, float angleInDeg);

	Vector3 wander(Agent* agent);

private:
	float radius;
	float jitter;
	float distance;
	
	Vector3 displacement;

};

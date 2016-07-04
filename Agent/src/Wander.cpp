#define _USE_MATH_DEFINES
#include <math.h>

#include "Wander.h"

#include <random>
#include <time.h>

std::mt19937 gen;
std::uniform_real_distribution<float> dis(0, 1);

Wander::Wander()
{
	radius = 25;
	jitter = 25;
	distance = 25;	
}



Wander::~Wander()
{
}

void Wander::update(Agent * agent, float dt)
{
	Vector3 target(agent->position.x + radius, agent->position.y, 1);

	target = target + (Vector3(dis(gen), dis(gen), 1) * jitter) ;

	target = target.normalise() * radius;	

	target = target * distance;

	Vector3 force = Vector3::normalise(target - agent->position) * agent->maxVelocity;

	agent->AddForce(force - agent->velocity);
	

	/*Vector3 wanderForce;
	if (decisionTime > 1)
	{
		decisionTime = 0;
		wanderForce = wander(agent);
	}
		

	decisionTime += dt;*/
	//Vector3	wanderForce = wander(agent);

	//wanderForce = IBehaviour::truncate(wanderForce, agent->maxVelocity);
	//agent->AddForce(wanderForce);

	//agent->velocity = IBehaviour::truncate(agent->velocity + wanderForce, agent->maxVelocity);

	//agent->position = agent->position + agent->velocity*dt;

	/*agent->force = Vector3(wanderForce - agent->position).normalise() * agent->maxVelocity;

	agent->velocity = agent->force - agent->velocity;

	agent->velocity = agent->velocity + agent->acceleration * dt;

	agent->position = agent->position + agent->velocity * dt;*/
	
}

void Wander::setAngle(Vector3 & displacement, float angleInDeg)
{
	float rad = angleInDeg * M_PI / 180;

	float cos = cosf(rad);
	float sin = sinf(rad);

	/*float x = displacement.x * cos - displacement.y * sin;
	float y = displacement.x * sin + displacement.y * cos;*/

	float length = displacement.magnitude();

	float x = cosf(angleInDeg) * length;
	float y = sinf(angleInDeg) * length;

	displacement.x = x;
	displacement.y = y;
}

Vector3 Wander::wander(Agent* agent)
{
	

	Vector3 circleCenter;
	circleCenter = agent->velocity;
	circleCenter.normalise();
	circleCenter = circleCenter * distance;

	Vector3 displacement(1, -1, 0);
	displacement = displacement * radius;


	

	// Change wanderAngle slightly according to jitter;
	float num = dis(gen);
	//wanderAngle += ((dis(gen) * jitter) - (jitter * .5));

	Vector3 wanderForce;
	wanderForce = circleCenter + displacement;
	return wanderForce;
}

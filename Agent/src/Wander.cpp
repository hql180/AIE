#define _USE_MATH_DEFINES
#include <math.h>

#include "Wander.h"

#include <random>
#include <time.h>

//std::mt19937 gen;
//std::uniform_int_distribution<int> dis(0, 10);

Wander::Wander()
{
	radius = 50;
	jitter = 35;
	distance = 100;
//	displacement = Vector3::normalise(Vector3(dis(gen) - 5 , dis(gen) - 5, 1));
}



Wander::~Wander()
{
}

Status Wander::update(Agent* agent, Application2D* pA2D, float dt)
{
	//Vector3 target = agent->position + Vector3::normalise(agent->velocity) * distance;	
	//
	//displacement = displacement.normalise() * radius;

	//target = target + displacement;

	////target = target + Vector3::normalise(Vector3(dis(gen) - 5, dis(gen) - 5, 1)) * jitter * radius;

	//Vector3 force = Vector3::normalise(target - agent->position) * agent->maxVelocity;

	//agent->AddForce(force - agent->velocity);

	//displacement = displacement + Vector3::normalise(Vector3(dis(gen) - 5, dis(gen) - 5, 1)) * jitter;

	//return SUCCESS;

	// Put this in constructor
	// displacement = random unit vector (at the start)
	// forward = position + velocity.normalise() * distance	
	// wanderTarget = forward + (displacment * radius)
	// seekTo(wanderTarget)
	// update displacement so it will randomly wander
	// displacement += jitter (random vector2)
	// renormalize displacement so its still a unit vector


/*	Vector3 target(agent->position.x + radius, agent->position.y, 1);

	float test = dis(gen);

	target = target + (Vector3(dis(gen), dis(gen), 1) * jitter) ;

	target = target.normalise() * radius;	

	target = target * distance;

	agent->AddForce(target);*/ // AddForce truncates

	//Vector3 force = Vector3::normalise(target - agent->position) * agent->maxVelocity;

	//agent->AddForce(force - agent->velocity);
	

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

	return FAILURE;
	
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
	

	//Vector3 circleCenter;
	//circleCenter = agent->velocity;
	//circleCenter.normalise();
	//circleCenter = circleCenter * distance;

	//Vector3 displacement(1, -1, 0);
	//displacement = displacement * radius;


	//

	//// Change wanderAngle slightly according to jitter;
	//float num = dis(gen);
	////wanderAngle += ((dis(gen) * jitter) - (jitter * .5));

	//Vector3 wanderForce;
	//wanderForce = circleCenter + displacement;
	//return wanderForce;

	return Vector3();
}

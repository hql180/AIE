#include "Agent.h"
#include "IBehaviour.h"
#include "Application2D.h"

#include <vector>


Agent::Agent()
{
}

Agent::Agent(Texture * a_sprite)
{
	sprite = a_sprite;
	//pA2D = appPointer;
	maxVelocity = 200;
	velocity = Vector3();
	acceleration = Vector3();
	position = Vector3(1280 / 2, 720 / 2, 1);
	velocity = Vector3(1, 1, 1);
	combatTimer = 0;
	isDead = false;
	pathFinder = nullptr;
	target = nullptr;
	fleeTarget = nullptr;
	currentNode = nullptr;


}


Agent::~Agent()
{
}

void Agent::AddForce(Vector3 f)
{
	force = IBehaviour::truncate(force + f, maxVelocity);
}

void Agent::update(Application2D* pA2D, float dt)
{
	force = Vector3(0, 0, 0);

	if (dt > 1)
		dt = 1;

	for (auto & it : behaviourList)
	{
		it->update(this, pA2D, dt);
	}		

	velocity = velocity + force * dt;

	IBehaviour::truncate(velocity, maxVelocity);

	position = position + velocity * dt;

	Vector3 temp = Vector3::normalise(velocity);

	float angle = atan2(temp.y, temp.x);

	local_transform = Matrix3::CreateRotation(angle) * Matrix3::CreateTranslation(position);

	UpdateTransforms();

}

void Agent::draw(SpriteBatch * spriteBatch)
{
	//spriteBatch->drawSprite(sprite, position.x, position.y, 50, 50);
	
	spriteBatch->drawSpriteTransformed3x3(sprite,
		(float*)global_transform, 25, 25);
}


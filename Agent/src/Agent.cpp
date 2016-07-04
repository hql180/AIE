#include "Agent.h"
#include "IBehaviour.h"


Agent::Agent()
{
}

Agent::Agent(Texture * a_sprite)
{
	sprite = a_sprite;
	maxVelocity = 200;
	velocity = Vector3();
	acceleration = Vector3();
	position = Vector3(1280 / 2, 720 / 2, 1);
	velocity = Vector3(10, 10, 1);
}


Agent::~Agent()
{
}

void Agent::AddForce(Vector3 f)
{
	force = IBehaviour::truncate(force + f, maxVelocity);
}

void Agent::update(float dt)
{
	force = Vector3(0, 0, 0);

	for (auto const& it : behaviourList)
	{
		it->update(this, dt);
	}
		

	velocity = velocity + force * dt;

	IBehaviour::truncate(velocity, maxVelocity);

	position = position + velocity * dt;

	Vector3 temp = Vector3::normalise(velocity);

	float angle = atan2(temp.y, temp.x);

	local_transform = Matrix3::CreateScale(Vector3(.2, .2, 1)) * Matrix3::CreateRotation(angle - 1.5708) * Matrix3::CreateTranslation(position);

	UpdateTransforms();

}

void Agent::draw(SpriteBatch * spriteBatch)
{
	//spriteBatch->drawSprite(sprite, position.x, position.y, 50, 50);
	
	spriteBatch->drawSpriteTransformed3x3(sprite,
		(float*)global_transform);
}


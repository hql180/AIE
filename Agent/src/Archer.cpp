#include "Archer.h"
#include "IBehaviour.h"


Archer::Archer()
{
}

Archer::Archer(Texture * a_sprite, Vector3 pos, float a_maxVel, int hp, float a_damage, float a_attackTime, float a_range, float a_vision, float a_vAngle, float a_accuracy, float cTimer)
{
	sprite = a_sprite;
	position = pos;
	maxVelocity = a_maxVel;
	maxHP = hp;
	HP = maxHP;
	attackDamage = a_damage;
	attackTime = a_attackTime;
	maxAttackTime = attackTime;
	attackRange = a_range;
	visionRange = a_vision;
	maxViewAngle = a_vAngle;
	accuracy = a_accuracy;
	combatTimer = cTimer;
	velocity = Vector3(1, 1, 1);
	isDead = false;

	pathFinder = nullptr;
	currentNode = nullptr;
}

Archer::~Archer()
{
}

void Archer::update(Application2D * pA2D, float dt)
{
	force = Vector3(0, 0, 0);

	if (dt > 1)
		dt = 1;

	for (auto & it : behaviourList)
	{
		it->update(this, pA2D, dt);
	}

	velocity = velocity + force * dt;

	velocity = IBehaviour::truncate(velocity, maxVelocity);

	position = position + velocity * dt;

	Vector3 temp = Vector3::normalise(velocity);

	float angle = atan2(temp.y, temp.x);

	local_transform = Matrix3::CreateRotation(angle) * Matrix3::CreateTranslation(position);

	UpdateTransforms();
}

void Archer::draw(SpriteBatch * spriteBatch)
{
	spriteBatch->drawSpriteTransformed3x3(sprite,
		(float*)global_transform, 25, 25);
}

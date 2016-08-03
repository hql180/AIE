#include "Arrow.h"
#include "Seek.h"
#include "Application2D.h"


Arrow::Arrow()
{
}

Arrow::Arrow(Agent* shooter, Application2D* pA2D)
{
	if (shooter->target)
	{
		sprite = pA2D->m_arrow;
		position = shooter->position;
		target = shooter->target;
		maxVelocity = 650;
		attackDamage = shooter->attackDamage;
		behaviourList.push_back(new Seek());
		isDead = false;
		velocity = shooter->velocity;
		combatTimer = 1.2;
	}
	else
		isDead = true;
}


Arrow::~Arrow()
{
	//for (int i = behaviourList.size() - 1; i >= 0; --i)
	//	delete behaviourList[i];
	
}

void Arrow::update(Application2D * pA2D, float dt)
{
	for (auto & tree : pA2D->trees)
		if ((tree->position - position).magnitude() < tree->radius*(3 / 4.f))
			isDead = true;

	combatTimer -= dt;

	if (combatTimer < 0)
		isDead = true;
	else if (target && !target->isDead)
	{
		force = Vector3(0, 0, 0);

		for (auto & it : behaviourList)
		{
			it->update(this, pA2D, dt);
		}

		velocity = velocity + force * dt;

		IBehaviour::truncate(velocity, maxVelocity);

		position = position + velocity * dt;

		Vector3 temp = Vector3::normalise(velocity);

		float angle = atan2(temp.y, temp.x);

		local_transform = Matrix3::CreateRotation(angle + 3.14159) * Matrix3::CreateTranslation(position);

		UpdateTransforms();

		if (Vector3(target->position - position).magnitude() <= 10)
		{
			target->combatTimer = 5;
			target->HP -= attackDamage;
			isDead = true;
		}
	}
	else
		isDead = true;
}

void Arrow::draw(SpriteBatch * spriteBatch)
{
	spriteBatch->drawSpriteTransformed3x3(sprite,(float*)global_transform, 25, 25);

}

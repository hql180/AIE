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
		maxVelocity = 200;
		attackDamage = shooter->attackDamage;
		behaviourList.push_back(new Seek());
		isDead = false;
		velocity = shooter->velocity;
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
	if (target && target->isDead == false)
	{
		force = Vector3(0, 0, 0);
		
		float localDT = dt;
		if (dt > 1)
			localDT = 1;

		for (auto & it : behaviourList)
		{
			it->update(this, pA2D, localDT);
		}

		velocity = velocity + force * localDT;

		IBehaviour::truncate(velocity, maxVelocity);

		position = position + velocity * localDT;

		Vector3 temp = Vector3::normalise(velocity);

		float angle = atan2(temp.y, temp.x);

		local_transform = Matrix3::CreateRotation(angle) * Matrix3::CreateTranslation(position);

		UpdateTransforms();

		if (Vector3(target->position - position).magnitude() <= 5)
		{
			target->combatTimer = 5;
			target->HP -= attackDamage;
			isDead = true;
		}
	}
	isDead = true;

}

void Arrow::draw(SpriteBatch * spriteBatch)
{
	spriteBatch->drawSpriteTransformed3x3(sprite,(float*)global_transform, 25, 25);

}

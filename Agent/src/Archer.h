#pragma once

#include "Agent.h"
#include "SpriteBatch.h"

class Archer :
	public Agent
{
public:
	Archer();
	Archer(Texture* a_sprite, Vector3 pos, float a_maxVel = 50, int hp = 100, float a_damage = 10, float a_attackTime = 3, 
			float a_range = 100, float a_vision = 150, float a_vAngle = 45, float a_accuracy = 20, float cTimer = 0);
	~Archer();

	virtual void update(Application2D* pA2D, float dt);

	virtual void draw(SpriteBatch* spriteBatch);

};


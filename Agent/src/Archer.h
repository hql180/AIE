#pragma once

#include "Agent.h"
#include "SpriteBatch.h"

class Archer :
	public Agent
{
public:
	Archer();
	Archer(Texture* a_sprite, Vector3 pos, float a_maxVel = 75, int hp = 100, float a_damage = 30, float a_attackTime = 1.5, 
			float a_range = 250, float a_vision = 400, float a_vAngle = 1.91986, float a_accuracy = 20, float cTimer = 0);
	~Archer();

	virtual void update(Application2D* pA2D, float dt);

	virtual void draw(SpriteBatch* spriteBatch);

};


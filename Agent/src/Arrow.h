#pragma once

#include "Texture.h"
#include "Agent.h"
class Arrow :
	public Agent
{
public:
	Arrow();
	Arrow(Agent* shooter, Application2D* pA2D);
	~Arrow();

	virtual void update(Application2D* pA2D, float dt);

	virtual void draw(SpriteBatch* spriteBatch);
};


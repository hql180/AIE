#pragma once
#include "MathLib.h"
#include "src\SceneNode.h"
#include "src\SpriteBatch.h"

class IBehaviour;

class Agent : public SceneNode
{
public:
	Agent();
	~Agent();

	void AddForce(float dt);

	virtual void update(float dt);

	virtual void draw(SpriteBatch* spriteBatch);



	Vector3 position;
	Vector3 velocity;
	float maxVelocity;
	Vector3 acceleration;

	Agent* target;
	
	float force;

	std::vector<IBehaviour*> behaviourList;
};


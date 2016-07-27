#pragma once
#include "MathLib.h"
#include "SceneNode.h"
#include "SpriteBatch.h"

class IBehaviour;
class Texture;

class Agent : public SceneNode
{
public:
	Agent();
	Agent(Texture* a_sprite);
	~Agent();

	void AddForce(Vector3 f);

	virtual void update(float dt);

	virtual void draw(SpriteBatch* spriteBatch);

	Vector3 position;
	Vector3 velocity;
	float maxVelocity;
	Vector3 acceleration;
	Texture* sprite;
	Vector3 force;

	float combatTimer;
	float visionRange;
	float attackRange;
	float maxViewAngle;

	int HP;
	int maxHP;

	

	Agent* target;
	Agent* fleeTarget;

	std::vector<IBehaviour*> behaviourList;
	
};


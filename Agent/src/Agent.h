#pragma once
#include "MathLib.h"
#include "SceneNode.h"
#include "SpriteBatch.h"
#include "PathFinder.h"
#include <list>
#include "Graph.h"

class IBehaviour;
class Application2D;


class Agent : public SceneNode
{
public:
	Agent();
	Agent(Texture* a_sprite);
	~Agent();

	void AddForce(Vector3 f);

	virtual void update(Application2D* pA2D, float dt);

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
	float attackTime;
	float maxAttackTime;
	float attackDamage;
	float accuracy;
	bool isDead;

	float HP;
	float maxHP;	

	Agent* target;
	Agent* fleeTarget;
	Graph::Node* currentNode;

	PathFinder* pathFinder;
	std::list<Graph::Node*> path;


	std::vector<IBehaviour*> behaviourList;
	
};


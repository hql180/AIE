#include "WanderPath.h"
#include "Graph.h"
#include "Application2D.h"
#include "PathFinder.h"

#include <random>
#include <algorithm>
#include <time.h>

std::mt19937 gen;
std::uniform_int_distribution<int> dis(0, 50);

WanderPath::WanderPath()
{
	radius = 50;
	jitter = 20;
	distance = 100;
	displacement = Vector3::normalise(Vector3(dis(gen) - 5, dis(gen) - 5, 1));
}


WanderPath::~WanderPath()
{
}

Status WanderPath::update(Agent * agent, Application2D * pA2D, float dt)
{
	Vector3 target = agent->position + Vector3::normalise(agent->velocity) * distance;

	displacement = displacement.normalise() * radius;

	target = target + displacement;

	Vector3 force = Vector3::normalise(target - agent->position) * agent->maxVelocity;

	displacement = displacement + Vector3::normalise(Vector3(dis(gen) - 5, dis(gen) - 5, 1)) * jitter;

	if (agent->pathFinder)
		delete agent->pathFinder;
	
	agent->pathFinder = new PathFinder();

	std::vector<Graph::Node*> closestStart;

	std::vector<Graph::Node*> closestEnd;
	
	pA2D->m_graph->FindNodesInRange(closestStart, agent->position.x, agent->position.y, 50);

	pA2D->m_graph->FindNodesInRange(closestEnd, target.x, target.y, 50);
	
	std::sort(closestStart.begin(), closestStart.end(),
		[agent](Graph::Node* a, Graph::Node* b)
	{
		Vector2 agentPos = Vector2(agent->position.x, agent->position.y);
		return (a->pos - agentPos).magnitude() < (b->pos - agentPos).magnitude();
	});	

	std::sort(closestEnd.begin(), closestEnd.end(),
		[agent](Graph::Node* a, Graph::Node* b)
	{
		Vector2 agentPos = Vector2(agent->position.x, agent->position.y);
		return (a->pos - agentPos).magnitude() < (b->pos - agentPos).magnitude();
	});
	
	Graph::Node* start = closestStart.front();

	Graph::Node* end = closestEnd.front();	

	agent->path.clear();

	agent->pathFinder->AStar(start, end, agent->path);

	return SUCCESS;
}

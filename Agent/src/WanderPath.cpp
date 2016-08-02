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
	displacement = Vector3::normalise(Vector3(dis(gen) - 5, dis(gen) - 5, 1));
}


WanderPath::~WanderPath()
{
}

Status WanderPath::update(Agent * agent, Application2D * pA2D, float dt)
{
	Vector3 target = agent->position + Vector3::normalise(agent->velocity) * 700;

	displacement = displacement.normalise() * 150;

	target = target + displacement;

	//target = target + Vector3::normalise(Vector3(dis(gen) - 5, dis(gen) - 5, 1)) * jitter * radius;

	Vector3 force = Vector3::normalise(target - agent->position) * agent->maxVelocity;

	agent->AddForce(force - agent->velocity);

	displacement = displacement + Vector3::normalise(Vector3(dis(gen) - 5, dis(gen) - 5, 1)) * 100;

	Graph::Node* targetNode = pA2D->m_graph->findNode(Vector2(displacement.x, displacement.y), 30);

	PathFinder finder();

	

	agent->pathFinder = new PathFinder();

	std::vector<Graph::Node*> closestStart;
	std::vector<Graph::Node*> closestEnd;

	
	pA2D->m_graph->FindNodesInRange(closestStart, agent->position.x, agent->position.y, 50);

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
	

	pA2D->m_graph->FindNodesInRange(closestEnd, agent->position.x, agent->position.y, 100);

	Graph::Node* start = closestStart.front();;

	Graph::Node* end = closestEnd.front();

	agent->path.clear();

	agent->pathFinder->AStar(start, end, agent->path);

	return SUCCESS;

}

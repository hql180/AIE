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
	distance = 150;
	displacement = Vector3::normalise(Vector3(dis(gen) - dis(gen), dis(gen) - dis(gen), 1));
}


WanderPath::~WanderPath()
{
}

Status WanderPath::update(Agent * agent, Application2D * pA2D, float dt)
{
	Vector3 target = agent->position + Vector3::normalise(agent->velocity) * distance;

	displacement = displacement.normalise() * radius;

	target = target + displacement; // seek to this

	//Vector3 force = Vector3::normalise(target - agent->position) * agent->maxVelocity; // Not used

	displacement = displacement + Vector3::normalise(Vector3(dis(gen) - dis(gen), dis(gen) - dis(gen), 1)) * jitter;

	if (agent->pathFinder)
		delete agent->pathFinder;
	
	agent->pathFinder = new PathFinder();

	if (!agent->currentNode)
	{
		std::vector<Graph::Node*> closestStart;

		int counter = 50;

		pA2D->m_graph->FindNodesInRange(closestStart, agent->position.x, agent->position.y, counter);

		while(closestStart.empty())
			pA2D->m_graph->FindNodesInRange(closestStart, agent->position.x, agent->position.y, counter += 50);

		std::sort(closestStart.begin(), closestStart.end(),
			[agent](Graph::Node* a, Graph::Node* b)
		{
			Vector2 agentPos = Vector2(agent->position.x, agent->position.y);
			return (a->pos - agentPos).magnitude() < (b->pos - agentPos).magnitude();
		});

		agent->currentNode = closestStart.front();
	}

	std::vector<Graph::Node*> closestEnd;
	
	int counter = 50;

	pA2D->m_graph->FindNodesInRange(closestEnd, target.x, target.y, counter);

	while (closestEnd.empty())
		pA2D->m_graph->FindNodesInRange(closestEnd, target.x, target.y, counter += 50);

	std::sort(closestEnd.begin(), closestEnd.end(),
		[&target](Graph::Node* a, Graph::Node* b)
	{
		Vector2 agentPos = Vector2(target.x, target.y);
		return (a->pos - agentPos).magnitude() < (b->pos - agentPos).magnitude();
	});

	Graph::Node* end = closestEnd.front();	

	agent->path.clear();

	agent->pathFinder->AStar(agent->currentNode, end, agent->path);

	return SUCCESS;
}

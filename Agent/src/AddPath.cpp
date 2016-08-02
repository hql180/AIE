#include "AddPath.h"
#include "PathFinder.h"
#include "Graph.h"
#include "Application2D.h"
#include "Agent.h"
#include "MathLib.h"

#include <vector>
#include <algorithm>




AddPath::AddPath()
{
}


AddPath::~AddPath()
{
}

Status AddPath::update(Agent * agent, Application2D * pA2D, float dt)
{
	if (agent->pathFinder)
		delete agent->pathFinder;

	Graph::Node* start;

	agent->pathFinder = new PathFinder();

	std::vector<Graph::Node*> closestStart;
	std::vector<Graph::Node*> closestEnd;

	if (agent->path.front())
		start = agent->path.front();
	else
	{
		pA2D->m_graph->FindNodesInRange(closestStart, agent->position.x, agent->position.y, 50);

		std::sort(closestStart.begin(), closestStart.end(),
			[agent](Graph::Node* a, Graph::Node* b)
		{			
			Vector2 agentPos = Vector2(agent->position.x, agent->position.y);
			return (a->pos - agentPos).magnitude() < (b->pos - agentPos).magnitude();
		});

		start = closestStart.front();
	}

	std::sort(closestEnd.begin(), closestEnd.end(),
		[agent](Graph::Node* a, Graph::Node* b)
	{
		Vector2 agentPos = Vector2(agent->position.x, agent->position.y);
		return (a->pos - agentPos).magnitude() < (b->pos - agentPos).magnitude();
	});
		
	pA2D->m_graph->FindNodesInRange(closestEnd, agent->position.x, agent->position.y, 50);

	Graph::Node* end = closestEnd.front();

	agent->path.clear();

	agent->pathFinder->AStar(start, end, agent->path);
	
	return SUCCESS;
}

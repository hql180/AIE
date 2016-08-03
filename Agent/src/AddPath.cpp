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
	if (agent->pathFinder != nullptr)
		delete agent->pathFinder;

	agent->pathFinder = new PathFinder();	

	if (!agent->currentNode)
	{
		std::vector<Graph::Node*> closestStart;

		int counter = 50;

		pA2D->m_graph->FindNodesInRange(closestStart, agent->position.x, agent->position.y, counter);

		while (closestStart.empty())
			pA2D->m_graph->FindNodesInRange(closestStart, agent->position.x, agent->position.y, counter += 50);

		std::sort(closestStart.begin(), closestStart.end(),
			[agent](Graph::Node* a, Graph::Node* b)
		{
			Vector2 agentPos = Vector2(agent->position.x, agent->position.y);
			return (a->pos - agentPos).magnitude() < (b->pos - agentPos).magnitude();
		});

		agent->currentNode = closestStart.front();
	}
	

	Graph::Node* end;

	if (!agent->target->currentNode)
	{
		std::vector<Graph::Node*> closestEnd;

		int counter = 50;

		pA2D->m_graph->FindNodesInRange(closestEnd, agent->target->position.x, agent->target->position.y, counter);

		while (closestEnd.empty())
			pA2D->m_graph->FindNodesInRange(closestEnd, agent->target->position.x, agent->target->position.y, counter += 50);

		std::sort(closestEnd.begin(), closestEnd.end(),
			[agent](Graph::Node* a, Graph::Node* b)
		{
			Vector2 agentPos = Vector2(agent->target->position.x, agent->target->position.y);
			return (a->pos - agentPos).magnitude() < (b->pos - agentPos).magnitude();
		});

		end = closestEnd.front();
	}
	else
		end = agent->target->currentNode;

	agent->path.clear();

	agent->pathFinder->AStar(agent->currentNode, end, agent->path);
	
	return SUCCESS;
}

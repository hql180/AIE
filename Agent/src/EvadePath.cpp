#include "EvadePath.h"
#include "Application2D.h"
#include "IBehaviour.h"
#include "Graph.h"
#include "PathFinder.h"

#include <vector>
#include <algorithm>


EvadePath::EvadePath()
{
}


EvadePath::~EvadePath()
{
}

Status EvadePath::update(Agent * agent, Application2D * pA2D, float dt)
{
	std::vector<Agent*> potentialTargets;
	for (auto target : pA2D->agents)
		if ((target->position - agent->position).magnitude() <= agent->visionRange)
			if (target != agent)
				potentialTargets.push_back(target);

	if (potentialTargets.empty())
		return FAILURE;

	Vector3 forceToApply(0, 0, 0);

	for (auto & target : potentialTargets)
	{
		float distanceFromTarget = (agent->position - target->position).magnitude();

		if (distanceFromTarget <= agent->visionRange)
		{
			Vector3 rayToTarget = Vector3::normalise(target->position - agent->position);
			for (auto tree : pA2D->trees)
			{
				// Tree position projected onto raycast
				Vector3 treeProjectedPos = tree->position - agent->position;
				float projection = rayToTarget.dot(treeProjectedPos);
				// clamp projection between 0 and distance from target;

				// to clamp projection scalar
				float min = std::min(0.f, distanceFromTarget);
				float max = std::max(0.f, distanceFromTarget);

				if (projection < min)
					projection = min;
				else if
					(projection > max)
					projection = max;

				treeProjectedPos = agent->position + projection * rayToTarget;

				float distance = (treeProjectedPos - tree->position).magnitude();

				if (distance > tree->radius)
				{
					Vector3 force = (Vector3::normalise(agent->position - target->position) * agent->maxVelocity) - agent->velocity;
					forceToApply = IBehaviour::truncate(forceToApply + force, agent->maxVelocity);
				}				
			}
		}
	}
	forceToApply = forceToApply * 200 + agent->position;

	if (agent->pathFinder)
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

	
	std::vector<Graph::Node*> closestEnd;

	pA2D->m_graph->FindNodesInRange(closestEnd, forceToApply.x, forceToApply.y, 50);

	int counter = 50;

	pA2D->m_graph->FindNodesInRange(closestEnd, agent->position.x, agent->position.y, counter);

	while (closestEnd.empty())
		pA2D->m_graph->FindNodesInRange(closestEnd, agent->position.x, agent->position.y, counter += 50);

	std::sort(closestEnd.begin(), closestEnd.end(),
		[&forceToApply](Graph::Node* a, Graph::Node* b)
	{
		Vector2 agentPos = Vector2(forceToApply.x, forceToApply.y);
		return (a->pos - agentPos).magnitude() < (b->pos - agentPos).magnitude();
	});


	Graph::Node* end = closestEnd.front();

	agent->path.clear();

	agent->pathFinder->AStar(agent->currentNode, end, agent->path);

	return SUCCESS;
}

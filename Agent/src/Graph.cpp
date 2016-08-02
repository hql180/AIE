#include "Graph.h"



Graph::Graph()
{
}


Graph::~Graph()
{
}

Graph::Node * Graph::AddNode(float xPos, float yPos)
{
	Graph::Node* nNode = new Graph::Node(Vector2(xPos, yPos));
	nodeList.push_back(nNode);
	return nNode;
}

void Graph::AddConnection(Node * n1, Node * n2)
{
	n1->connections.push_back(Graph::Edge(n2, n1->pos.distance(n2->pos)));
}

void Graph::FindPathDijkstras(Node * startNode, Node * endNode, std::list<Node*> &outPath)
{
	std::list<Node*> openList;
	std::list<Node*> closedList;

	openList.push_back(startNode);

	while (!openList.empty())
	{
		openList.sort([](Node* a, Node* b) // Some Lambda witchcraft
		{
			return a->gScore < b->gScore; // Figure out what this returns
		});

		Node* current = openList.front();

		if (current == endNode)
			break;

		openList.pop_front();
		closedList.push_back(current);

		for (auto const& it : current->connections) // Note to self : give iterators better names in future
		{
			bool added = false;
			for (auto const& c : closedList)
				if (c == it.connection)
					added = true;
			if (!added)
				openList.push_back(it.connection);
			it.connection->gScore = current->gScore + it.cost;
			it.connection->parent = current;
		}
	}

	std::list<Vector2> path;
	Node* current = endNode;
	while (current)
	{
		outPath.push_front(current);
		current = current->parent;
	}
}

void Graph::FindNodesInRange(std::vector<Node*>& outNodes, float xPos, float yPos, float radius)
{
	for (auto const& it : nodeList)
	{
		if (it->pos.distance(Vector2(xPos, yPos)) < radius)
			outNodes.push_back(it);
	}
}

void Graph::RemoveNodeAt(Vector2 a_pos)
{
	Graph::Node* deleteThis = findNode(a_pos);

	if (deleteThis)
	{
		for (int i = nodeList.size() - 1; i >= 0; --i)
		{
			for (int a = nodeList[i]->connections.size() - 1; a >= 0; --a)
			{
				if (nodeList[i]->connections[a].connection == deleteThis)
				{
					nodeList[i]->connections.erase(nodeList[i]->connections.begin() + a);
				}
			}
		}
		for (int i = nodeList.size() - 1; i >= 0; --i)
			if (nodeList[i] == deleteThis)
			{
				nodeList.erase(nodeList.begin() + i);
				delete deleteThis;
			}

	}
}

void Graph::RemoveNodeAt(Vector2 a_pos, float radius)
{
	while (findNode(a_pos, radius))
	{
		Graph::Node* deleteThis = findNode(a_pos, radius);

		for (int i = nodeList.size() - 1; i >= 0; --i)
		{
			for (int a = nodeList[i]->connections.size() - 1; a >= 0; --a)
			{
				if (nodeList[i]->connections[a].connection == deleteThis)
				{
					nodeList[i]->connections.erase(nodeList[i]->connections.begin() + a);
				}
			}
		}
		for (int i = nodeList.size() - 1; i >= 0; --i)
			if (nodeList[i] == deleteThis)
			{
				nodeList.erase(nodeList.begin() + i);
				delete deleteThis;
			}
	}
}

Graph::Node * Graph::findNode(Vector2 a_pos, float radius)
{
	for (auto const &it : nodeList)
		if (it->pos.distance(a_pos) <= radius)
			return it;
	return nullptr;
}

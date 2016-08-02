#pragma once
#include "Vector2.h"

#include <vector>
#include <list>

class Graph
{
public:
	struct Edge;

	struct Node
	{
		Vector2 pos;

		float gScore;

		Node* parent;

		std::vector<Edge> connections;

		Node() : pos(0, 0), gScore(0), parent(nullptr) {}

		Node(Vector2 a_pos) : pos(a_pos), gScore(0), parent(nullptr) {}

		Node(Vector2 a_pos, float a_gScore, Node* a_parent) :
				pos(a_pos), gScore(a_gScore), parent(a_parent) {}

	};

	struct Edge
	{
		Node* connection;

		float cost;

		Edge() : connection(nullptr), cost(0) {}

		Edge(Node* a_connection) : connection(a_connection), cost(0) {}

		Edge(Node* a_connection, float a_cost) : 
			connection(a_connection), cost(a_cost) {}
	};

	Graph();
	virtual ~Graph();

	Node* AddNode(float xPos, float yPos);

	void AddConnection(Node* n1, Node* n2);

	void FindPathDijkstras(Node* startNode, Node* endNode, std::list<Node*> &outPath);

	void FindNodesInRange(std::vector<Node*> &outNodes, float xPos, float yPos, float radius);

	void RemoveNodeAt(Vector2 a_pos);

	void RemoveNodeAt(Vector2 a_pos, float radius);

	Node* findNode(Vector2 a_pos, float radius = 10);

	std::vector<Node*> nodeList;
};


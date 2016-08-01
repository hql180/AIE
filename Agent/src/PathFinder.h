#pragma once

#include "Graph.h"

class PathFinder
{
public:
	PathFinder();
	virtual ~PathFinder();
	
	void Dijkstras(Graph::Node* startNode, Graph::Node* endNode, std::list<Graph::Node*> &outPath);

	void AStar(Graph::Node* startNode, Graph::Node* endNode, std::list<Graph::Node*> &outPath);
private:
	bool added;

	struct Node
	{
		Graph::Node* pNode;

		Node *pParent;
		int dos;
		float gScore;
		float hScore;
		float fScore;
		

		Node(Graph::Node* oNode) : pNode(oNode), pParent(nullptr), dos(0), gScore(0) {}
	};
};


#pragma once

#include <vector>
class Vector2
{
public:
	Vector2()
	{

	}
	Vector2(int a, int b)
	{
		x = a;
		y = b;
	}
	~Vector2()
	{

	}

	int x, y;
};




class Graph
{
public:
	Graph();
	~Graph();

	class Node;

	class Edge
	{
	public:
		Edge()
		{
		}
		Edge(Node* destination, int data)
		{
			m_destination = destination;
			m_cost = data;
		}
		int m_cost;
		Node* m_destination;
	};

	class Node
	{
	public:
		Node(Vector2 data)
		{
			m_data = data;
		}

		Vector2 m_data;
		std::vector<Edge> m_connections;
	};


	Node* AddNode(Vector2 data);
	Node* FindNode(Vector2 data);
	

	void RemoveNode(Node* pNode);
	void ConnectNodes(Node* nodeA, Node* nodeB, int data);

	std::vector<Node*> m_nodeList;

protected:
	



};



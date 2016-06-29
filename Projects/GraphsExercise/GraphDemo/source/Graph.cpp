#include "Graph.h"

Graph::Graph()
{
	
}


Graph::~Graph()
{
	for (auto & element : m_nodeList)
	{
		delete element;
	}
}

Graph::Node * Graph::AddNode(Vector2 data)
{
	Node* newNode = new Node(data);
	m_nodeList.push_back(newNode);
	return newNode;
}

Graph::Node * Graph::FindNode(Vector2 data)
{
	int length = m_nodeList.size();
	for (int i = 0; i < length; ++i)
	{
		int a = (m_nodeList[i]->m_data.x - data.x);
		int b = (m_nodeList[i]->m_data.y - data.y);
		a *= a;
		b *= b;

		if (a + b < (10 * 10))
		{
			return m_nodeList[i];
		}
	}
}

void Graph::RemoveNode(Node * pNode)
{
	for (int i = m_nodeList.size() - 1; i >= 0; --i)
	{
		if (m_nodeList[i] == pNode)
		{
			m_nodeList.erase(m_nodeList.begin() + i);
			delete pNode;
		}
		else
		{
			for (int a = m_nodeList[i]->m_connections.size() - 1; a >= 0; --a)
			{
				if (m_nodeList[i]->m_connections[a].m_destination == pNode)
				{
					m_nodeList[i]->m_connections.erase(m_nodeList[i]->m_connections.begin() + a);
				}
			}
		}
	}
	
}

void Graph::ConnectNodes(Node * nodeA, Node * nodeB, int data)
{
	nodeA->m_connections.push_back(Edge(nodeB, data));
}




#include <vector>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

class Graph
{
public:
	// predefine classes
	struct Node;
	struct Edge
	{
		Node *connection;
		// default constructor
		Edge() : connection(NULL) { }
		// overloaded construct
		Edge(Node *node) : connection(node) { }
	};
	struct Node
	{
		int value;
		int dos;
		std::vector< Graph::Edge > connections;
		// default constructor
		Node() : value(0), dos(0) {}
		// overloaded constructor
		Node(int val, int ds) : value(val), dos(ds) {}
		// overloaded constructor
		Node(int val) : value(val), dos(0) {}
	};
	~Graph()
	{
		// make sure to delete all nodes added to the graph
		for (auto iter = m_nodes.begin(); iter != m_nodes.end(); iter++)
			delete (*iter);
		m_nodes.clear();
	}
	Node *AddNode(int value)
	{
		m_nodes.push_back(new Node(value));
		return m_nodes.back();
	}
	void AddConnection(Node *n1, Node *n2)
	{
		n1->connections.push_back(Edge(n2));
		n2->connections.push_back(Edge(n1));
	}
//private:
	std::vector< Node * > m_nodes;
};

void PrintBFS(Graph::Node* startNode)
{
	deque<Graph::Node*> openList;
	list<Graph::Node*> closedList;
	
	openList.push_back(startNode);

	while (!openList.empty())
	{
		Graph::Node* currentNode = openList.front();

		cout << currentNode->value << " ";

		openList.pop_front();
		closedList.push_back(currentNode);
		
		for (auto & it : currentNode->connections) // iterates through all connections of current node
		{
			bool added = false; // a check for if item is in closed list
			for (auto & it2 : closedList) // iterates through whole closedList
			{
				if (it.connection == it2) // checks to see if current node connection is in closed list
				{
					added = true;
				}
			}
			for (auto & it2 : openList)
			{
				if (it.connection == it2) // checks to see if current node connection is in closed list
				{
					added = true;
				}
			}
			if (!added) // if currentnode is not in closed list
			{
				openList.push_front(it.connection); // adds connection to front of queue
			}
		}
	}
	cout << "\n";
}

void PrintDFS(Graph::Node* startNode)
{
	deque<Graph::Node*> openList;
	list<Graph::Node*> closedList;

	openList.push_back(startNode);

	while (!openList.empty())
	{
		Graph::Node* currentNode = openList.front();

		cout << currentNode->value << " ";

		openList.pop_front();
		closedList.push_back(currentNode);

		for (auto & it : currentNode->connections) // iterates through all connections of current node
		{
			bool added = false; // a check for if item is in closed list
			for (auto & it2 : closedList) // iterates through whole closedList
			{
				if (it.connection == it2) // checks to see if current node connection is in closed list
				{
					added = true;
				}
			}
			for (auto & it2 : openList)
			{
				if (it.connection == it2) // checks to see if current node connection is in closed list
				{
					added = true;
				}
			}
			if (!added) // if currentnode is not in closed list
			{
				openList.push_back(it.connection); // adds connection to front of queue
			}
		}
	}
	cout << "\n";
}

void BFS(Graph::Node* startNode)
{
	list<Graph::Node*> openList;
	list<Graph::Node*> closedList;

	openList.push_back(startNode);

	while (!openList.empty())
	{
		openList.sort([](Graph::Node* a, Graph::Node* b)
		{
			return a->dos < b->dos;
		});

		Graph::Node* currentNode = openList.front();

		cout << currentNode->value << ":" << currentNode->dos << " ";
		
		openList.pop_front();
		closedList.push_back(currentNode);

		for (auto & it : currentNode->connections) // iterates through all connections of current node
		{
			bool added = false; // a check for if item is in closed list
			for (auto & it2 : closedList) // iterates through whole closedList
			{
				if (it.connection == it2) // checks to see if current node connection is in closed list
				{
					added = true;
				}
			}
			for (auto & it2 : openList)
			{
				if (it.connection == it2) // checks to see if current node connection is in closed list
				{
					added = true;
				}
			}
			if (!added) // if currentnode is not in closed list
			{
				it.connection->dos = currentNode->dos + 1;
				openList.push_front(it.connection); // adds connection to front of queue
			}
		}
	}
	cout << "\n";
}

void DFS(Graph::Node* startNode)
{
	list<Graph::Node*> openList;
	list<Graph::Node*> closedList;

	openList.push_back(startNode);

	while (!openList.empty())
	{
		openList.sort([](Graph::Node* a, Graph::Node* b)
		{
			return a->dos > b->dos;
		});

		Graph::Node* currentNode = openList.front();

		cout << currentNode->value << ":" << currentNode->dos << " ";

		openList.pop_front();
		closedList.push_back(currentNode);

		for (auto & it : currentNode->connections) // iterates through all connections of current node
		{
			bool added = false; // a check for if item is in closed list
			for (auto & it2 : closedList) // iterates through whole closedList
			{
				if (it.connection == it2) // checks to see if current node connection is in closed list
				{
					added = true;
				}
			}
			for (auto & it2 : openList)
			{
				if (it.connection == it2) // checks to see if current node connection is in closed list
				{
					added = true;
				}
			}
			if (!added) // if currentnode is not in closed list
			{
				it.connection->dos = currentNode->dos + 1;
				openList.push_back(it.connection); // adds connection to front of queue
			}
		}
	}
	cout << "\n";
}

int main(int argc, char **argv)
{
	Graph *pGraph = new Graph();
	Graph::Node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
	a = pGraph->AddNode('a'); b = pGraph->AddNode('b');
	c = pGraph->AddNode('c'); d = pGraph->AddNode('d');
	e = pGraph->AddNode('e'); f = pGraph->AddNode('f');
	g = pGraph->AddNode('g'); h = pGraph->AddNode('h');
	i = pGraph->AddNode('i'); j = pGraph->AddNode('j');
	pGraph->AddConnection(a, b); pGraph->AddConnection(a, d);
	pGraph->AddConnection(a, e); pGraph->AddConnection(b, c);
	pGraph->AddConnection(d, h); pGraph->AddConnection(e, h);
	pGraph->AddConnection(e, f); pGraph->AddConnection(f, c);
	pGraph->AddConnection(f, j); pGraph->AddConnection(g, c);
	pGraph->AddConnection(g, j); pGraph->AddConnection(i, j);
	pGraph->AddConnection(i, h);

	PrintBFS(pGraph->m_nodes.front());
	PrintDFS(pGraph->m_nodes.front());
	BFS(pGraph->m_nodes.front());
	DFS(pGraph->m_nodes.front());

	delete pGraph;

	system("pause");
	return 0;
};


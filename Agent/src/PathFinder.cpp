#include "PathFinder.h"



PathFinder::PathFinder()
{
}


PathFinder::~PathFinder()
{
}

void PathFinder::Dijkstras(Graph::Node * startNode, Graph::Node * endNode, std::list<Graph::Node*>& outPath)
{
	/*std::list<Graph::Node*> openList;
	std::list<Graph::Node*> closedList;*/

	// create a list of nodes
	// refer to nodes by index in the list not by pointer
	// Node.pNode
	// Node.parent = index of parent node
	// parent == -1 then its "null"

	bool finished = false;

	std::list<Node*> openList;
	std::list<Node*> closedList;
		
	openList.push_back(new Node(startNode));

	Node* current;

	while (!openList.empty())
	{
		openList.sort([](Node* a, Node* b) // Some Lambda witchcraft
		{
			return a->gScore < b->gScore; // Figure out what this returns
		});

		current = openList.front();

		if (current->pNode == endNode)
			break;

		closedList.push_front(current);
		openList.pop_front();
		

		for (auto &it : current->pNode->connections)
		{
			added = false;
			for (auto & clist : closedList)
				if (clist->pNode == it.connection)
					added = true;

			for(auto & olist :openList)
				if (olist->pNode == it.connection)
					added = true;
			
			if (!added)
			{
				openList.push_front(new Node(it.connection));
				openList.front()->gScore = current->gScore + it.cost;
				openList.front()->pParent = current;
			}
		}
	}

	if (current->pNode == endNode)
	{
		while (current)
		{
			outPath.push_front(current->pNode);
			current = current->pParent;
		}
	}

	for (Node* node : openList)
		delete node;

	for (Node* node : closedList)
		delete node;


	///////////////////////////////////////////////////////////////////////////////////

	//std::list<Node> openList;
	//std::list<Node> closedList;

	//openList.push_back(Node(startNode));

	//
	//
	//while (!openList.empty() && !finished)
	//{
	//	openList.sort([](Node a, Node b) // Some Lambda witchcraft
	//	{
	//		return a.gScore < b.gScore; // Figure out what this returns
	//	});

	//	Node current = openList.front();

	//	if (current.pNode == endNode)
	//		break;

	//	closedList.push_front(current);
	//	openList.pop_front();


	//	for (auto &it : current.pNode->connections) // Note to self : give iterators better names in future
	//	{
	//		bool added = false;
	//		for (auto & clist : closedList)
	//			if (clist.pNode == it.connection && !added)
	//				added = true;	

	//		for (auto & olist : closedList)
	//			if (olist.pNode == it.connection && !added)
	//				added = true;
	//	
	//		if (added == false)
	//		{
	//			openList.push_front(Node(it.connection));
	//			openList.front().gScore = current.gScore + it.cost;
	//			openList.front().pParent = &closedList.front();
	//		}
	//	}
	//	
	//}

	//Node* current = &openList.front();

	//while (current)
	//{
	//	outPath.push_front(current->pNode);
	//	current = current->pParent;
	//}
	//
	//finished = true;

}

void PathFinder::AStar(Graph::Node * startNode, Graph::Node * endNode, std::list<Graph::Node*>& outPath)
{
	std::list<Node*> openList;
	std::list<Node*> closedList;

	openList.push_back(new Node(startNode));

	Node* current;

	while (!openList.empty())
	{
		openList.sort([](Node* a, Node* b) // Some Lambda witchcraft
		{
			return a->fScore < b->fScore; // Figure out what this returns
		});

		current = openList.front();

		if (current->pNode == endNode)
			break;

		closedList.push_front(current);
		openList.pop_front();


		for (auto &it : current->pNode->connections)
		{
			/*added = false;
			for (auto & clist : closedList)
				if (clist->pNode == it.connection)
					added = true;

			for (auto & olist : openList)
				if (olist->pNode == it.connection)
					added = true;

			if (!added)
			{
				openList.push_front(new Node(it.connection));
				openList.front()->gScore = current->gScore + it.cost;
				openList.front()->hScore = openList.front()->pNode->pos.distance(endNode->pos);
				openList.front()->fScore = openList.front()->gScore + openList.front()->hScore;
				openList.front()->pParent = current;
			}*/

			/////////////////////// *FIX* ////////////////////


			added = false;

			float gScore = current->gScore + it.cost;

			for (auto & clist : closedList)
				if (clist->pNode == it.connection)
				{
					added = true;
					if (clist->gScore > gScore)
					{
						clist->gScore = gScore;
						clist->fScore = clist->gScore + clist->hScore;
						clist->pParent = current;
					}
				}

			for (auto & olist : openList)
				if (olist->pNode == it.connection)
				{
					added = true;
					if (olist->gScore > gScore)
					{
						olist->gScore = gScore;
						olist->fScore = olist->gScore + olist->hScore;
						olist->pParent = current;
					}
				}
			
			if (!added)
			{
				openList.push_front(new Node(it.connection));
				openList.front()->gScore = current->gScore + it.cost;
				openList.front()->hScore = openList.front()->pNode->pos.distance(endNode->pos);
				openList.front()->fScore = openList.front()->gScore + openList.front()->hScore;
				openList.front()->pParent = current;
			}
		}
	}

	if (current->pNode == endNode)
	{
		while (current)
		{
			outPath.push_front(current->pNode);
			current = current->pParent;
		}
	}

	for (Node* node : openList)
		delete node;

	for (Node* node : closedList)
		delete node;
}

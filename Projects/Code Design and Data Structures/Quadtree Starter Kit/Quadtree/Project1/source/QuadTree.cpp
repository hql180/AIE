#include "QuadTree.h"



QuadTree::QuadTree()
{

}

QuadTree::QuadTree(Vector2 left, Vector2 right, int max)
{
	root = Node(left, right, max);
}


QuadTree::~QuadTree()
{
}

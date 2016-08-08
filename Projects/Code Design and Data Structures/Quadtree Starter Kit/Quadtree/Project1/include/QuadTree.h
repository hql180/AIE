#pragma once
#include "Vector2.h"
#include "Enemy.h"

#include <vector>

class QuadTree
{
public:
	class Node
	{
	public:
		Node() 
		{
			quad[0] = nullptr;
			quad[1] = nullptr;
			quad[2] = nullptr;
			quad[3] = nullptr;
		}

		Node(Vector2 topLeft, Vector2 bottomRight, int max = 2)
		{
			tLeft.x = topLeft.x;
			tLeft.y = topLeft.y;
			bRight.x = bottomRight.x;
			bRight.y = bottomRight.y;

			float middleX = (tLeft.x + bRight.x) / 2;
			float middleY = (tLeft.y + bRight.y) / 2;
			
			if (--max >= 0)
			{
				quad[0] = new Node(tLeft, Vector2(middleX, middleY), max);
				quad[1] = new Node(Vector2(middleX, tLeft.y), Vector2(bRight.x, middleY), max);
				quad[2] = new Node(Vector2(tLeft.x, middleY), Vector2(middleX, bRight.y), max);
				quad[3] = new Node(Vector2(middleX, middleY), bRight, max);
			}
			else
			{
				quad[0] = nullptr;
				quad[1] = nullptr;
				quad[2] = nullptr;
				quad[3] = nullptr;
			}
		}

		~Node() {}

		bool AddEnemy(Enemy* enemy)
		{
			for (int i = 0; i < 4; ++i)
			{
				if (quad[i] != nullptr)
				{
					if (quad[i]->AddEnemy(enemy))
					{
						return true;
					}					
				}
				else if (enemy->GetPos() >= tLeft && enemy->GetPos() < bRight)
				{
					eList.push_back(enemy);
					return true;
				}
			}			
			return false;
		}

		void Get(Vector2 mouse, std::vector<Enemy*>& list, int radius = 2)
		{
			Vector2 tempLeft(mouse.x - radius, mouse.y - radius);
			Vector2 tempRight(mouse.x + radius, mouse.y + radius);

			if (tempLeft.x < bRight.x &&
				tempRight.x > tLeft.x &&
				tempLeft.y < bRight.y &&
				tempRight.y > tLeft.y)
			{
				if (quad[0] != nullptr)
				{
					for (int i = 0; i < 4; ++i)
					{
						quad[i]->Get(mouse, list, radius);
					}
				}
				else
				{
					for (int i = 0; i < eList.size(); ++i)
					{
						list.push_back(eList[i]);
					}
				}
			}

		}

		Vector2 tLeft;
		Vector2 bRight;
		Node* quad[4];

	protected:
		

		std::vector<Enemy*> eList;

		
		/*Node* quad2;
		Node* quad3;
		Node* quad4;*/
	};
	
	QuadTree();

	QuadTree(Vector2 left, Vector2 right, int max = 2);

	~QuadTree();

	Node root;
private:
	
};


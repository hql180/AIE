#pragma once

#include "Item.h"


class Inventory
{
	Item _list[20];
	int _itemCount = 0;

public:
	//void newItem(std::string name);
	
	void newItem(std::string name, int weight, bool stackable, int stacks);

	void removeItem(int item)
	{

	}
};
#include "Inventory.h"

#include <string>

//void Inventory::newItem(std::string name)
//{
//
//	Item(name);
//	_itemCount++;
//}


void Inventory::newItem(std::string name, int weight, bool stackable, int stacks)
{
	Item(name, weight, stackable, stacks);
	_itemCount++;
}

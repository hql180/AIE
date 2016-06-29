#include "Item.h"
#include <iostream>
#include <string>


Item::Item()
{
	_weight = 1;
	_stackable = false;
	_stackCount = 1;
}

Item::Item(std::string name)
{
	_name = name;
}

Item::Item(const std::string& name, int weight, bool stackable, int stacks) :
	_name = name,
	_weight = weight,
	_stackable = stackable,
	_stackCount = stacks,
{
	_name = name;
	_weight = weight;
	_stackable = stackable;
	_stackCount = stacks;
}

void Item::setName(const std::string& name)
{
	_name = name;
}

void Item::setWeight(int w)
{
	_weight = w;
}

void Item::setStackable(bool stacks)
{
	_stackable = stacks;
}

void Item::setStackCount(int count)
{
	_stackCount = count;
}
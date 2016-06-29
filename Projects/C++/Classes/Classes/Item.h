#pragma once

#include <string>

class Item
{
	std::string _name;
	int _weight;
	bool _stackable = false;
	int _stackCount = 1;

public:
	Item();

	Item(std::string name);

	Item(const std::string& name, int weight, bool stackable, int stacks);

	void setName(const std::string& name);

	void setWeight(int w);

	void setStackable(bool stacks);

	void setStackCount(int count);
};
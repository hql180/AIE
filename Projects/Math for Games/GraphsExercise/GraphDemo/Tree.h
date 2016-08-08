#pragma once
#include <iostream>

class Tree
{
public:
	class Node
	{
	public:
		Node() : leftNode(nullptr), rightNode(nullptr), value(0) {}
		Node(int value) : leftNode(nullptr), rightNode(nullptr), value(value) {}

		int value;
		Node* leftNode;
		Node* rightNode;
	};

	bool isEmpty()
	{
		if (root == nullptr)
		{
			return true;
		}
		else if (root->leftNode == nullptr && root->rightNode == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Node* getNode(Node* current, int value)
	{
		if (current->value < value && current->rightNode != nullptr)
		{
			return current->rightNode;
		}
		else if (current->value > value && current->leftNode != nullptr)
		{
			return current->leftNode;
		}
		else
		{
			return current;
		}
	}

	void insert(int value)
	{
		Node* current = root;
		Node* next = getNode(current, value);
		while (current != next)
		{
			current = next;
			next = getNode(current, value);
		}

		Node* newNode = new Node(value);

		if (current->value < value)
		{
			current->rightNode = newNode;
		}
		else if (current->value > value)
		{
			current->leftNode = newNode;
		}
		else
		{
			delete newNode;
		}
	}

	bool find(int value)
	{
		Node* current = root;
		Node* next = getNode(current, value);

		while (current != next)
		{
			if (current->value == value)
			{
				return true;
			}
			current = next;
			next = getNode(current, value);
		}
		return false;
	}

	Tree() : root(NULL) {}

	Tree(int value) { root = new Node(value); }

	Node* root;
};


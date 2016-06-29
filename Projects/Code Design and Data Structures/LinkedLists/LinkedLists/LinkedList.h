#pragma once

template<class T>
class LinkedList
{
public:
	class Node
	{
	public:
		Node()
		{
			_prev = nullptr;
			_next = nullptr;
		}
		T _data;

		void SetPrev(Node* node)
		{
			_prev = node;
		}

		void SetNext(Node* node)
		{
			_next = node;
		}

		Node* _prev;
		Node* _next;
	};

	LinkedList()
	{
		_start = new Node();
		_end = new Node();
		_size = 0;
		_start->_next = _end;
		_end->_prev = _start;
		/*_start.Node::_next = _end;
		_end.Node::_prev = _start;*/
		//_end.SetPrev(_start);
	}

	~LinkedList()
	{}

	Node& operator[] (int index)
	{
		if (index < _size)
		{
			Node* currentNode = _start->_next;
			for (int i = 0; i < index; ++i)
			{
				currentNode = currentNode->_next;
			}
			return currentNode;
		}
		return nullptr;
	}
	
	void AddStart(T data)
	{
		newNode = new Node;
		newNode.data = data;

		newNode._next = 
	}

private:
	Node* _start;
	Node* _end;
	int _size;
};


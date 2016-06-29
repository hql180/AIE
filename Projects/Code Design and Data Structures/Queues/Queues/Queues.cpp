#include <iostream>

template<class T>
class Queue
{
public:
	class Node
	{
	public:
		Node()
		{
			m_prev = nullptr;
			m_next = nullptr;
		}

		~Node()
		{
		}

		T _data;
		Node* m_prev;
		Node* m_next;
	};

	Queue()
	{
		m_start = new Node();
		m_end = new Node();
		m_size = 0;
		m_start->m_next = m_end;
		m_end->m_prev = m_start;
	}

	~Queue()
	{
		if (m_size > 0);
		{
			Node* current = m_start->m_next;
			for (int i = 0; i < m_size; ++i)
			{
				Node* next = current->m_next;
				delete current;
				current = next;
			}
		}
		if (m_start != nullptr)
		{
			delete m_start;
		}
		if (m_end != nullptr)
		{
			delete m_end;
		}
	}

	Node& operator[] (int index)
	{
		if (index < m_size)
		{
			Node* currentNode = m_start->m_next;
			for (int i = 0; i < index; ++i)
			{
				currentNode = currentNode->m_next;
			}
			return*currentNode;
		}
	}

	Node* GetNode(int index)
	{
		Node* currentNode = m_start->m_next;
		for (int i = 0; i < index; ++i)
		{
			currentNode = currentNode->m_next;
		}
		return currentNode;
	}


	void AddStart(T data)
	{
		Node* newNode = new Node;

		newNode->_data = data;

		newNode->m_next = m_start->m_next;
		newNode->m_prev = m_start;

		m_start->m_next->m_prev = newNode;
		m_start->m_next = newNode;

		++m_size;
	}

	void Push(T data)
	{
		Node* newNode = new Node;

		newNode->_data = data;

		newNode->m_prev = m_end->m_prev;
		newNode->m_next = m_end;

		m_end->m_prev->m_next = newNode;
		m_end->m_prev = newNode;

		++m_size;
	}

	void Pop()
	{
		if (m_size > 0)
		{
			RemoveAt(0);
		}
	}

	bool IsEmpty()
	{
		return !m_size;
	}

	int GetSize()
	{
		return m_size;
	}

	void AddAt(T data, int index)
	{
		Node* newNode = new Node;
		Node* current = GetNode(index);

		newNode->m_next = current;
		newNode->m_prev = current->m_prev;

		newNode->_data = data;

		current->m_prev->m_next = newNode;
		current->m_prev = newNode;

		++m_size;
	}

	// Example here
	void AddAfter(T data, int index)
	{
		Node* newNode = new Node;
		Node* current = GetNode(index);

		newNode->m_next = current->m_next;
		//newNode->m_next = GetNode(index)->m_next;
		newNode->m_prev = current;

		newNode->_data = data;

		current->m_next->m_prev = newNode;
		current->m_next = newNode;

		++m_size;
	}

	void RemoveAt(int index)
	{
		if (index < m_size)
		{
			Node* current = GetNode(index);
			current->m_prev->m_next = current->m_next;
			current->m_next->m_prev = current->m_prev;

			delete current;
			--m_size;
		}
	}

	void ClearList()
	{
		while (m_size > 0)
		{
			RemoveAt(0);
		}
	}

	void Swap(int a, int b)
	{
		Node* swapA = GetNode(a);
		Node* swapB = GetNode(b);
		Node* afterA = swapA->m_next;
		Node* afterB = swapB->m_next;
		Node* beforeA = swapA->m_prev;
		Node* beforeB = swapB->m_prev;

		swapA->m_next = afterB;
		swapB->m_next = afterA;
		swapA->m_prev = beforeB;
		swapB->m_prev = beforeA;

		beforeA->m_next = swapB;
		beforeB->m_next = swapA;
		afterA->m_prev = swapB;
		afterB->m_prev = swapA;
	}

	void Print()
	{
		Node* current = m_start->m_next;

		for (int i = 0; i < m_size; ++i)
		{
			std::cout << current->_data << " ";
			current = current->m_next;
		}
	}

private:
	Node* m_start;
	Node* m_end;
	int m_size;
};


int main()
{
    return 0;
}


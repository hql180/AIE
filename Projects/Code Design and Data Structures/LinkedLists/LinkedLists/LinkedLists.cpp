#include <iostream>


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

		~Node()
		{
		}

		T _data;
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
	}

	~LinkedList()
	{
		if (_size > 0);
		{
			Node* current = _start->_next;
			for (int i = 0; i < _size; ++i)
			{
				Node* next = current->_next;
				delete current;
				current = next;
			}
		}
		if (_start != nullptr)
		{
			delete _start;
		}
		if (_end != nullptr)
		{
			delete _end;
		}
	}

	Node& operator[] (int index)
	{
		if (index < _size)
		{
			Node* currentNode = _start->_next;
			for (int i = 0; i < index; ++i)
			{
				currentNode = currentNode->_next;
			}
			return* currentNode;
		}
	}

	Node* GetNode(int index)
	{
		Node* currentNode = _start->_next;
		for (int i = 0; i < index; ++i)
		{
			currentNode = currentNode->_next;
		}
		return currentNode;
	}


	void AddStart(T data)
	{
		Node* newNode = new Node;

		newNode->_data = data;

		newNode->_next = _start->_next;
		newNode->_prev = _start;

		_start->_next->_prev = newNode;
		_start->_next = newNode;

		++_size;
	}

	void AddEnd(T data)
	{
		Node* newNode = new Node;

		newNode->_data = data;

		newNode->_prev = _end->_prev;
		newNode->_next = _end;
	
		_end->_prev->_next = newNode;
		_end->_prev = newNode;

		++_size;
	}

	void AddAt(T data, int index)
	{
		Node* newNode = new Node;
		Node* current = GetNode(index);

		newNode->_next = current;
		newNode->_prev = current->_prev;

		newNode->_data = data;

		current->_prev->_next = newNode;
		current->_prev = newNode;

		++_size;
	}

	// Example here
	void AddAfter(T data, int index)
	{
		Node* newNode = new Node;
		Node* current = GetNode(index);

		newNode->_next = current->_next;
		//newNode->_next = GetNode(index)->_next;
		newNode->_prev = current;

		newNode->_data = data;

		current->_next->_prev = newNode;
		current->_next = newNode;

		++_size;
	}

	void RemoveAt(int index)
	{
		if (index < _size)
		{
			Node* current = GetNode(index);
			current->_prev->_next = current->_next;
			current->_next->_prev = current->_prev;

			delete current;
			--_size;
		}
	}

	void ClearList()
	{
		while (_size > 0)
		{
			RemoveAt(0);
		}
	}

	void Swap(int a, int b)
	{
		Node* swapA = GetNode(a);
		Node* swapB = GetNode(b);
		Node* afterA = swapA->_next;
		Node* afterB = swapB->_next;
		Node* beforeA = swapA->_prev;
		Node* beforeB = swapB->_prev;

		swapA->_next = afterB;
		swapB->_next = afterA;
		swapA->_prev = beforeB;
		swapB->_prev = beforeA;

		beforeA->_next = swapB;
		beforeB->_next = swapA;
		afterA->_prev = swapB;
		afterB->_prev = swapA;
	}
	
	void Print()
	{
		Node* current = _start->_next;
		
		for (int i = 0; i < _size; ++i)
		{
			std::cout << current->_data << " ";
			current = current->_next;
		}		
	}

	void Merge(T* list, int start, int middle, int end)	//  - 10 - 21
	{
		int leftEnd = middle - start + 1;	// 10 -1 + 1 = 10;
		int rightEnd = end - middle;	// 10 - 20 = 10

		int* leftArray = new int[leftEnd];
		int* rightArray = new int[rightEnd];

		/*int leftArray[leftEnd];
		int rightArray[rightEnd];*/

		for (int i = 0; i < leftEnd; ++i)	// 10  iterates 0 - 9; good
		{
			leftArray[i] = list[start + i - 1];	//  1(start) + i (0) - 1 = 0 inbounds;
		}
		for (int i = 0; i < rightEnd; ++i)	// 10 iterates 0 - 9 + 10(middle) = 10-19 good
		{
			rightArray[i] = list[middle + i];	// 10 + 0(i) = 10
		}

		int i = 0;
		int j = 0;

		for (int k = start - 1; k < end; ++k) // -1 to correct start iterates 0-19
		{
			if (i < leftEnd && (leftArray[i] < rightArray[j] || j == rightEnd))	//iterates 0 - 9
			{
				list[k] = leftArray[i];
				i++;
			}
			else if (j < rightEnd)	//iterates 0 - 9
			{
				list[k] = rightArray[j]; //
				j++;
			}

		}

		delete[] leftArray;
		delete[] rightArray;
	}

	void MergeSort(T* list, int start, int end) // eg list[21] start = 1, end = 21
	{
		if (start < end)
		{
			int q = (start + end) / 2;	// q = 10?
			MergeSort(list, start, q);	// 1 - 10
			MergeSort(list, q + 1, end);	// 11 - 21
			Merge(list, start, q, end);	// 1 - 10 - 21

		}
	}

	void BubbleSort()
	{
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < _size - 1; ++i) // -1 to keep in bounds
			{
				if (list[i] > list[i + 1]) // reason for the -1
				{
					int temp = list[i];
					list[i] = list[i + 1];
					list[i + 1] = temp;
					sorted = false;
				}
			}
		}
	}

private:
	Node* _start;
	Node* _end;
	int _size;
};





int main()
{
	
		LinkedList<int> test;

		test.AddStart(11);
		test.AddStart(10);
		test.AddEnd(20);
		test.AddAt(30, 1);
		test.AddAfter(33, 1);

		test.Print();
		

		std::cout << "\n";
		test.Swap(0, 4);
		test.Print();


		
	

	system("pause");
    return 0;
}


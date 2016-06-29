#include <iostream>

template<class T>
class MyStack
{
public:
	MyStack()
	{
		m_stack = new T[10];
		m_size = 0;
		m_capacity = 10;
	}

	~MyStack()
	{
		delete[] m_stack;
	}

	void Resize()
	{
		m_capacity *= 2;

		T* temp = new T[m_capacity];

		for (int i = 0; i < m_size; ++i)
		{
			temp[i] = m_stack[i];
		}

		delete[] m_stack;

		m_stack = temp;
	}

	bool Empty()
	{
		return !m_size;
	}

	int Size()
	{
		return m_size;
	}

	void Push(T value)
	{
		if (m_size == m_capacity)
		{
			Resize();
		}
		m_stack[m_size++] = value;
	}

	void Pop()
	{
		--m_size;
	}

	T Top()
	{
		return m_stack[m_size - 1];
	}

	void Print()
	{
		int index = 0;
		while (index < m_size)
		{
			std::cout << m_stack[index++];
			if (index < m_size)
			{
				std::cout << ", ";
			}
			else
			{
				std::cout << "\n";
			}
		}
	}

private:
	T* m_stack;
	int m_size, m_capacity;
};



int main()
{
	MyStack<int> test;
	std::cout << test.Empty();
	test.Push(1);
	test.Push(1);
	test.Push(1);
	test.Push(20);
	test.Push(1);
	test.Push(1);
	test.Push(1);
	test.Push(20);
	test.Push(1);
	test.Push(1);
	test.Push(1);
	test.Push(20);
	test.Push(1);
	test.Push(1);
	test.Push(1);
	test.Push(20);
	test.Print();
	std::cout << test.Size();
	std::cout << test.Empty();

	system("pause");
    return 0;
}


#pragma once

template<class T>
class HStack
{
public:
	HStack()
	{
		m_stack = new T[10];
		m_size = 0;
		m_capacity = 10;
	}

	~HStack()
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

	bool IsEmpty()
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

	T* Top()
	{
		//return m_stack[m_size - 1];
		return m_stack;
	}

	void Draw(void(*drawCallback)(const T*))
	{
		// since the template doesn't know how to draw the template type,
		// use a callback function to draw the elements in our stack
		T* pEnd = m_stack + m_size;
		for (T* p = pEnd; p > m_stack; --p) {
			drawCallback(p);
		}
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


#include <iostream>

template <typename T> class MyContainer
{
public:
	MyContainer()
	{
		container = nullptr;
		_size = 0;
		_capacity = 0;
	}

	MyContainer(MyContainer& rhs) : MyContainer(rhs._capacity)
	{
		_size = rhs._size;
		for (int i = 0; i < _size; ++i)
		{
			container[i] = rhs.container[i];
		}
	}
	
	MyContainer(int capacity)
	{
		container = new T[capacity];
		_size = 0;
		_capacity = capacity;
	}

	~MyContainer()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}

	void AddEnd(T add)
	{
		if (_size == _capacity)
		{
			Expand();
		}
		container[_size++] = add;
	}

	void RemoveEnd()
	{
		if (_size > 0)
		{
			--_size;
		}
	}

	void RemoveAt(int index)
	{
		if (index < _size)
		{
			--_size;
			for (int i = 0; i < _size; ++i)
			{
				container[i] = container[i + 1];
			}
		}
	}

	void RemoveUnordered(int index)
	{
		if (index < _size)
		{
			container[index] = container[_size];
			--_size;
		}
	}

	void Resize()
	{
		_capacity = _size;
		T* newArray = new T[_capacity];
		for (int i = 0; i < _size; ++i)
		{
			newArray[i] = container[i];
		}
		
		if (container != nullptr)
		{
			delete[] container;
		}

		container = newArray;
	}

	void Resize(int size)
	{
		if (size >= _size)
		{
			_capacity = size;
			T newArray = new T[_capacity];
			for (int i = 0; i < _size; ++i)
			{
				newArray[i] = container[i];
			}

			if (container != nullptr)
			{
				delete[] container;
			}

			container = newArray;
		}
	}

	void Expand()
	{
		_capacity *= 2;
		T* newArray = new T[_capacity];
		for (int i = 0; i < _size; ++i)
		{
			newArray[i] = container[i];
		}

		if (container != nullptr)
		{
			delete[] container;
		}

		container = newArray;
	}

	void ClearList()
	{
		_size = 0;
	}

	T& operator= (T* rhs)
	{
		*this = rhs;
	}

	T& operator[] (int index)
	{
		return container[index];
	}

	void Print()
	{
		for (int i = 0; i < _size; ++i)
		{
			std::cout << container[i] << "\n";
		}
	}

private:
	T* container;
	int _size, _capacity;
};

int main()
{
	MyContainer<int> test(10);

	
	int run = 200;
	
	for (int i = 0; i < run; ++i)
	{
		test.AddEnd(i);
	}
	test.Print();
	
	

	system("pause");
    return 0;
}


#include <iostream>


template <typename T> 
T Min(T a, T b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

template <typename T> 
T Max(T a, T b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

template <typename T> 
T Clamp(T min, T max, T val)
{
	if (val < min)
	{
		val = min;
	}
	else if (val > max)
	{
		val = max;
	}

	return val;
}

template<>
char Min(char a, char b)
{
	if (isalpha(a) != 0 && isalpha(b) != 0)
	{
		return Min<int>(a, b);
	}
	//else if (isalpha(a) == 0 && isalpha(b) == 0)
	//{
	//	std::cout << a << " and " << b << " are is not letters" << "\n";
	//}
	//else if (isalpha(a) == 0)
	//{
	//	std::cout << a << " is not a letter" << "\n";
	//}
	//else if (isalpha(b) == 0)
	//{
	//	std::cout << b << " is not a letter" << "\n";
	//}
}

template<>
char Max(char a, char b)
{
	if (isalpha(a) != 0 && isalpha(b) != 0)
	{
		return Max<int>(a, b);
	}
	//else if (isalpha(a) == 0 && isalpha(b) == 0)
	//{
	//	std::cout << a << " and " << b<< " are is not letters" << "\n";
	//}
	//else if(isalpha(a) == 0)
	//{
	//	std::cout << a << " is not a letter" << "\n";
	//}
	//else if (isalpha(b) == 0)
	//{
	//	std::cout << b << " is not a letter" << "\n";
	//}
}

template<typename T, int a>
class Exercise2	
{
public:
	Exercise2()
	{
		_array = new T[a];
		memset(_array, 0, sizeof(T) * a);
	};

	~Exercise2()
	{
		if (_array != nullptr)
		{
			delete[] _array;
		}
	};

	void Add(T add)
	{
		if (_size == _capacity)
		{
			Expand();
		}
		_array[_size] = add;
		_size++;
	}

	void Expand()
	{
		T* temp = new T[_capacity * 2];
		memcpy(temp, _array, sizeof(T)*_size);
		if (_array != nullptr)
		{
			delete[] _array;
		}
		_array = temp;
	}

	void Set(int index, T value)
	{
		_array[index] = value;
	}

	T& operator [] (int index)
	{
		if (index >= _size)
		{
			std::cout << "Out of bounds \n";
		}
		else if (index != 0)
		{
			
			return _array[index];

		}
		else
		{
			std::cout << "Array is empty \n";
		}
}

private:
	T* _array;
	int _size = 0;
	int _capacity = a;
};



int main()
{

	Exercise2 <int, 10> test;

	for (int i = 0; i < 10; ++i)
	{
		test.Add(i);
	}
	
	std::cout << test[3] << "\n";

	test.Add(30);

	std::cout << test[10];


	

	

	system("PAUSE");
    return 0;
}


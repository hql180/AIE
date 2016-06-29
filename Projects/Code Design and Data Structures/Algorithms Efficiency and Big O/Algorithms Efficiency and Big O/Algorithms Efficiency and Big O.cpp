#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>

int bogosortAttempts = 0;

template <typename RandomAccessIterator, typename Predicate>
void bogo_sort(RandomAccessIterator begin, RandomAccessIterator end,
	Predicate p) {
	std::random_device rd;
	std::mt19937 generator(rd());
	while (!std::is_sorted(begin, end, p)) 
	{
		std::shuffle(begin, end, generator);
		bogosortAttempts++;
	}
}

template <typename RandomAccessIterator>
void bogo_sort(RandomAccessIterator begin, RandomAccessIterator end) 
{
	bogo_sort(
		begin, end,
		std::less<
		typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

void printList(int* list, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
}

void bogoSort()
{
	//o(n!)
	int size = 20;
	int a[20];
	for (int i = 0; i < size; i++)
	{
		std::cin >> a[i];
	}
	
	bogo_sort(std::begin(a), std::end(a));
	copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	std::cout << bogosortAttempts << std::endl;
}

void bubbleSort(int* list, int length)
{
	// O(n2)

	if (length < 0)
	{
		std::cout << "List is empty\n";
	}
	else
	{
		while (true)
		{
			bool stillRunning = false;

			for (int i = 0; i < length; ++i)
			{
				if (i + 1 < length)
				{
					if (list[i] > list[i + 1])
					{
						int temp = list[i];
						list[i] = list[i + 1];
						list[i + 1] = temp;
						stillRunning = true;
					}
				}
			}
			if (stillRunning == false)
			{
				printList(list, length);
				break;
			}
			printList(list, length);
		}
	}
}

void insertionSort()
{
	// O(n^2)
}

void quickSort()
{
	// o(n log n)
}

int main()
{
	bogoSort();
	system("pause");
    return 0;
}


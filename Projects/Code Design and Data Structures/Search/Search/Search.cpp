#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

bool LinearSearch(int* list, int length, int search)
{
	for (int i = 0; i < length; ++i)
	{
		if (list[i] == search)
		{
			return true;
		}
	}
	return false;
}

int BinarySearch(int* list, int length, int key)
{
	int min = 0;
	int max = length - 1;

	while (max != min)
	{
		int middle = (min + max) / 2;

		if (list[middle] == key)
		{
			return middle;
		}
		else if (list[max] == key)
		{
			return max;
		}
		else if (list[min] == key)
		{
			return min;
		}
		else if (list[middle] > key)
		{
			max = middle - 1;
		}
		else if (list[middle] < key)
		{
			min = middle + 1;
		}
	}
	return -1;
}

void InsertionSort(int* list, int listLength)
{
	for (int i = 1; i < listLength; ++i) // started from second element and counting up
	{
		int temp = list[i]; // temp = 4nd element
		int j = i - 1;	// j = element before temp element
		while (j >= 0 && list[j] > temp) // while j points to 2nd element or greater and j element is greater than temp
		{
			list[j + 1] = list[j]; // shifts j element up one
			j = j - 1;	// set j to previous element
		}
		list[j + 1] = temp; // inserts temp where it belongs
	}
}

int* GenerateList(const int length)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> distribution(1, length);

	int* list = new int[length];

	for (int i = 0; i < length; ++i)
	{
		list[i] = distribution(generator);
	}
	return list;
}

void PrintList(int* list, int listLength)
{
	for (int i = 0; i < listLength; ++i)
	{
		cout << list[i] << "\n";
	}
	cout << endl;
}

void E1()
{
	const int LENGTH = 1000;

	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> distribution(1, LENGTH);

	int list[LENGTH];

	for (int i = 0; i < LENGTH; ++i)
	{
		list[i] = distribution(generator);
	}
	

	std::sort(std::begin(list), std::end(list));

	PrintList(list, LENGTH);

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	cout << "Found?" << BinarySearch(list, LENGTH, 357) << "\n";

	high_resolution_clock::time_point t2 = high_resolution_clock::now();



	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
		t2 - t1).count();
	cout << duration << endl;
	t1 = high_resolution_clock::now();

	

	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(
		t2 - t1).count();
	cout << duration << endl;


}

int main()
{
	E1();
	

	system("pause");
    return 0;
}


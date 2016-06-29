#include <iostream>
#include <chrono>
#include <cstdio>
#include <time.h>

using namespace std;
using namespace std::chrono;

void BubbleSort(int* list, int listLength)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 0; i < listLength - 1; ++i) // -1 to keep in bounds
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

void Merge(int* list, int start, int middle, int end)	//  - 10 - 21
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

void MergeSort(int* list, int start, int end) // eg list[21] start = 1, end = 21
{
	if (start < end)
	{
		int q = (start + end) / 2;	// q = 10?
		MergeSort(list, start, q);	// 1 - 10
		MergeSort(list, q + 1, end);	// 11 - 21
		Merge(list, start, q, end);	// 1 - 10 - 21

	}
}

int* GenerateList(int length)
{
	int* list = new int[length];
	for (int i = 0; i < length; ++i)
	{
		list[i] = rand() % length;
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

bool Sorted(int* list, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		if (list[i] > list[i + 1])
		{
			return false;
		}
	}
	return true;
}

void E1()
{
	// A = {31,41,59,26,41,58}
	// A = {THIS26,31,41,59,41,58}
	// A = {26,31,41,THIS41,59,58}
	// A = {26,31,41,41,THIS58,59}
}

void E2()
{
	int length = 20;
	int* list = GenerateList(length);
	int* list2 = GenerateList(length);
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	InsertionSort(list2, length);

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	PrintList(list2, length);

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
		t2 - t1).count();
	cout << duration << endl;
	t1 = high_resolution_clock::now();

	BubbleSort(list, length);

	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(
		t2 - t1).count();
	cout << duration << endl;
}

int main()
{
	int length = 10;
	int* list = GenerateList(length);

	cout << Sorted(list, length) << "\n";

	cout << "running" << endl;

	MergeSort(list, 1, length);

	//BubbleSort(list, length);

	//InsertionSort(list, length);

	list[9] = 0;

	PrintList(list, length);

	cout << Sorted(list, length) << "\n";

	system("pause");
    return 0;
}


#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

static int makeItHappen = 0;

void evenToZero(int& i)
{
	makeItHappen++;
	if (makeItHappen % 2 == 0)
	{
		i = 0;
	}
}

int main()
{
	std::vector<int> vectorOfInts;

	vectorOfInts.push_back(5);
	vectorOfInts.push_back(2);
	vectorOfInts.push_back(7);

	int secondValue = vectorOfInts.at(1); // Setting secondValue to 2nd element (2)
	int thirdValue = vectorOfInts[2]; // thirdValue to 3rd index (7)

	vectorOfInts[2] = 10; // Changing stored values 7 -> 10

	// Becareful to not access/write outofbounds

	typedef std::vector<int>::iterator IntVectorIterator; // Or use auto

	IntVectorIterator it = vectorOfInts.begin(); // auto it = ...

	int iValue = (*it); // iValue -> 5 // remember to dereference
	(*it) = 12; // 5 -> 12

	it = vectorOfInts.begin();
	it = it + 2; // it now points to third element (10)

	std::vector<int> random;
	for (int i = 0; i < 20; ++i)
	{
		random.push_back(rand());
	}

	for (int num : random)
	{
		std::cout << num << "\n";
	}

	std::cout << "\n";

	std::sort(random.rbegin(), random.rend()); // rbeing & rend to reverse iterators

												//<functional>
	//std::sort(random.begin(), random.end(), std::greater<int>()); also an option
	//std::reverse


	for (int num : random)
	{
		std::cout << num << "\n";
	}

	std::cout << "\n";

	//for (int i = 0; i < 20; ++i)
	//{
	//	if ((i + 1) % 2 == 0)
	//	{
	//		random[i] = 0;
	//	}
	//}

	for (int num : random)
	{
		std::cout << num << "\n";
	}

	std::for_each(random.begin(), random.end(), evenToZero);

	for (int num : random)
	{
		std::cout << num << "\n";
	}

	std::cout << "Number of zeroes: " << std::count(random.begin(), random.end(), 0) <<"\n";

	system("pause");
    return 0;
}


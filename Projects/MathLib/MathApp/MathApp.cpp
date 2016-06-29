#include "Utility.h"
#include "unittest.h"
#include <iostream>

int main()
{
	/*Matrix3 test;

	float counter = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			test.m[i][j] = ++counter;
		}
	}

	Matrix3 test2;

	test2 = test.GetTranspose();

	Matrix3 test3;
	test3 = test * test2;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << test3.m[i][j] << " ";
		}
		std::cout << std::endl;
	}*/

	//Matrix2 test(2, 3, 5, 10);
	//Matrix2 test2(20, 34, 6, 8);

	//Matrix2 test3 = test * test2;

	//for (int i = 0; i < 2; ++i)
	//{
	//	for (int j = 0; j < 2; ++j)
	//	{
	//		std::cout << test3.m[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	


	
	if (runUnitTests())
	{
		std::cout << "All tests passed \n";
	}

	system("pause");
    return 0;
}


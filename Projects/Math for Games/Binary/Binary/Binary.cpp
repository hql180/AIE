#include <iostream>
#include <bitset>

using namespace std;

//void q1()
//{
//	// 1)
//	1
//
//	// 42)
//	42/2 = 21 : 0
//	21/2 = 10 : 1
//	10/2 = 5 : 0
//	5/2 = 2 : 1
//	2/2 = 1: 0
//	1/2 = 0: 1
//
//	101010
//
//	// 256)
//
//	256/2 = 128 : 0
//	128/2 = 64 : 0
//	64/2 = 32 : 0
//	32 = 16 : 0
//	16 = 8 : 0
//	8 = 4 : 0
//	4 = 2 : 0
//	2 = 1 : 0
//	1 = 0 : 1
//
//	100000000
//
//	// 4,294,967,296
//}
//
//void q2()
//{
//	// 1000 0000
//	2 ^ 7 = 128
//
//	// 1010 1010
//	2 ^ 7 + 2 ^ 5 + 2 ^ 3 + 2 ^ 1 = 170
//
//	// 1111 0000
//	240
//
//
//}

//void q5()
//{
//	// 1000 0000
//	-128
//
//	// 10101010
//
//	-86
//
//	// 1111 0000
//
//	-16
//
//	// 11001100
//
//	-52
//
//	// -16
//	
//	1111 0000
//
//	// 128
//
//	REQUIRES 9 BITS
//
//	// -128
//
//	1000 0000
//
//	// -123
//
//	1000 0101
//}

void q6()
{
	int e1 = 31 | 31;
	cout << "11111 | 11111 = 11111:31 " << e1 <<endl;

	int e2 = 31 ^ 31;

	cout << "11111 ^ 11111 = 00000:0 " << e2 << endl;

	int e3 = 21 & 31;

	cout << "10101 & 11111 = 10101:21 " << e3 << endl;

	int e4 = 21 | 31;

	cout << "10101 | 11111 = 11111:31 " << e4 << endl;

	int e5 = 0 ^ 31;

	cout << "00000 ^ 11111 = 11111:31 " << e5 << endl;

	int e6 = 1 << 3;

	cout << "1 << 3 = 1000:8 " << e6 << endl;

	int e7 = 100 >> 2;

	cout << "100 >> 2 = 11001:25 " << e7 << endl;

	unsigned char e8 = ~21;

	cout << "~0001 0101 = 1110 1010:234 " << (int)e8 << endl;

	int e9 = 100 << 1;

	cout << "100 << 1 = 200 " << e9 << endl;

	int e10 = 1010 >> 1;

	cout << "1010 >> 1 = 505 " << e10 << endl;

	unsigned char e11 = ~31;

	cout << "~0001 1111 = 1110 0000 " << e10 << endl;
}

void q7()
{
	
}

bool IsLeftMostBitSet(unsigned int value) // 32 bits
{
	unsigned int bitmask = 1 << (sizeof(value) * 8 - 1);
		
	return value & bitmask;
}

bool IsRightMostBitSet(unsigned int value)
{
	unsigned int bitmask = 1;

	return value & bitmask;
}

bool IsBitSet(unsigned int value, unsigned char bit_to_check)
{
	unsigned int bitmask = 1 << bit_to_check - 1;

	return value & bitmask;
}

int GetRightMostSetBit(unsigned int value)
{
	int count = 1;
	while (count <= 32)
	{
		if (IsRightMostBitSet(value))
		{
			return count;
		}
		else
		{
			value >>= 1;
			++count;			
		}
	}
	return -1;
}

void PrintBinary(unsigned int value)
{
	cout << (bitset<sizeof(value) * 8>) value << "\n";
}

bool IsPowerOf2(unsigned int value)
{
	int count = 0;
	int found = 0;

	if (IsRightMostBitSet(value))
		return false;

	while (count < 33)
	{
		if (IsRightMostBitSet(value))
		{
			++found;
		}
		value >>= 1;
		++count;
	}
	if (found == 1)
		return true;
	else
		return false;
}

int main()
{

	//q6();

	unsigned int bit = 65;

	PrintBinary(bit);
	cout << IsPowerOf2(bit) << " " << (bitset<32>) bit;


	system("pause");
    return 0;
}


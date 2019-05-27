#include<iostream>
using namespace std;

int* _012Sort(int* flags, int size)
{
	int low = 0, mid = 0, high = size - 1;
	while (mid <= high)
	{
		if (flags[mid] ==0)
		{
			int temp = flags[mid];
			flags[mid] = flags[low];
			flags[low] = temp;
			low++;
			mid++;
		}
		else if (flags[mid]==2)
		{
			int temp = flags[mid];
			flags[mid] = flags[high];
			flags[high] = temp;
			high--;
		}
		else
			mid++;
	}
	return flags;
}
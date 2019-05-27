#include<iostream>
using namespace std;

int* flagCount(int* flags, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		count += flags[i];
	int* sortedFlags = (int*)malloc(sizeof(int)*size);
	int i;
	for (i = 0; i < size - count; i++)
		sortedFlags[i] = 0;
	for (; i < size; i++)
		sortedFlags[i] = 1;
	return sortedFlags;
}


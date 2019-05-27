#include<iostream>
using namespace std;

int* flagSwap(int* flags, int size)
{
	int top = 0, back = size - 1;
	while (1)
	{
		while (flags[top] == 0)
			top++;
		while (flags[back] == 1)
			back--;
		if (top >= back)
			break;
		flags[top] = 0;
		flags[back] = 1;
	}
	return flags;
}

/*
int main()
{
	int* flags;
	int size;
	cout << "Enter No.Of Flags:";
	cin >> size;
	flags = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
		cin >> flags[i];
	flags = flagSwap(flags, size);
	for (int i = 0; i < size; i++)
		cout << flags[i] << " ";
	system("pause");
	return 0;
}*/
#include<iostream>
using namespace std;


int* flagSort(int* flags, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (flags[i]>flags[j])
			{
				int temp = flags[i];
				flags[i] = flags[j];
				flags[j]= temp;
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
	flags = flagSort(flags, size);
	for (int i = 0; i < size; i++)
		cout << flags[i] << " ";
	system("pause");
	return 0;
}*/
#include<iostream>
using namespace std;


int* spiral(int** mat, int m, int n)
{
	int* res = (int*)malloc(sizeof(int)*m*n);
	int pos = 0;
	int lowRow = 0, lowCol = 0, highRow =m, highCol = n;
	while (lowRow < highRow && lowCol < highCol)
	{
		for (int i = lowRow, j = lowRow; j < highCol; j++)
			res[pos++] = mat[i][j];
		lowRow++;
		if (lowRow >= highRow || lowCol >= highCol)
			break;
		for (int i = lowRow, j = highCol - 1; i < highRow; i++)
			res[pos++] = mat[i][j];
		highCol--;
		if (lowRow >= highRow || lowCol >= highCol)
			break;
		for (int i = highRow - 1, j = highCol - 1; j >lowCol; j--)
			res[pos++] = mat[i][j];
		highRow--;
		if (lowRow >= highRow || lowCol >= highCol)
			break;
		for (int i = highRow, j = lowCol; i >= lowRow; i--)
			res[pos++] = mat[i][j];
		lowCol++;
	}
	return res;
}


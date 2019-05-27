#include<iostream>
using namespace std;

void spiralRec(int* res,int** mat,int lowRow, int lowCol, int highRow, int highCol)
{
	static int pos = 0;
	if (lowRow >= highRow || lowCol >= highCol)
		return;
	for (int i = lowRow, j = lowRow; j < highCol; j++)
		res[pos++] = mat[i][j];
	lowRow++;
	if (lowRow >= highRow || lowCol >= highCol)
		return;
	for (int i = lowRow, j = highCol - 1; i < highRow; i++)
		res[pos++] = mat[i][j];
	highCol--;
	if (lowRow >= highRow || lowCol >= highCol)
		return;
	for (int i = highRow - 1, j = highCol - 1; j >lowCol; j--)
		res[pos++] = mat[i][j];
	highRow--;
	if (lowRow >= highRow || lowCol >= highCol)
		return;
	for (int i = highRow, j = lowCol; i >= lowRow; i--)
		res[pos++] = mat[i][j];
	lowCol++;
	spiralRec(res, mat, lowRow, lowCol, highRow, highCol);
}

#include<iostream>
using namespace std;
 
int** transpose(int** mat,int m,int n)
{
	int** tMat = new int*[n];
	for (int i = 0; i < n; i++)
		tMat[i] = new int[m];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tMat[j][i] = mat[i][j];
	return tMat;
}

#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE* fp = fopen("1-A.txt", "r");
	FILE* fp1 = fopen("1-B.txt", "r");
	int AA[6][6] = { 0 };//剛開始讀檔放進二維
	int BB[6][6] = { 0 };//剛開始讀檔放進二維
	int CC[6][6] = { 0 };//稀疏乘完放進二維
	int AAA[20][3] = { 0 };//二維轉乘稀疏矩陣
	int BBB[20][3] = { 0 };//二維轉乘稀疏矩陣
	int CCC[20][3] = { 0 };//二維轉乘稀疏矩陣
	int x = 0, y = 0;
	if (fp == NULL)
	{
		printf("not!\n");
	}
	else {
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				fscanf(fp, "%d", &AA[i][j]);
			}
		}
	}
	if (fp1 == NULL)
	{
		printf("not!\n");
	}
	else {
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				fscanf(fp1, "%d", &BB[i][j]);
			}
		}
	}
	int i = 0, j = 0, count = 1, aa = 0, bb = 0, k = 0, l = 0, cc = 0, p = 0;
	for (i = 0; i < 6; i++)//把A矩陣變成稀疏矩陣
	{
		for (j = 0; j < 6; j++)
		{
			if (AA[i][j] != 0)
			{
				AAA[count][0] = i;
				AAA[count][1] = j;
				AAA[count][2] = AA[i][j];
				count++;
			}
		}
	}
	AAA[0][0] = 6;
	AAA[0][1] = 6;
	AAA[0][2] = count - 1;
	printf("A:稀疏\n");
	for (x = 0; x < count; x++)
	{
		printf("\n");
		for (y = 0; y < 3; y++)
		{
			printf("%d\t", AAA[x][y]);
		}
	}
	printf("\nB:稀疏:\n");
	count = 1;
	for (i = 0; i < 6; i++)//把B矩陣變成稀疏矩陣
	{
		for (j = 0; j < 6; j++)
		{
			if (BB[i][j] != 0)
			{
				BBB[count][0] = i;
				BBB[count][1] = j;
				BBB[count][2] = BB[i][j];
				count++;
			}
		}
	}
	BBB[0][0] = 6;
	BBB[0][1] = 6;
	BBB[0][2] = count - 1;
	for (x = 0; x < count; x++)
	{
		printf("\n");
		for (y = 0; y < 3; y++)
		{
			printf("%d\t", BBB[x][y]);
		}
	}
	printf("\n");
	for (i = 0; i < 6; i++)//AB矩陣相乘
	{
		for (j = 0; j < 6; j++)
		{
			for (p = 0; p < 6; p++)
			{

				for (k = 1; k < 20; k++)
				{
					if (AAA[k][0] == i && AAA[k][1] == p) {
						aa = AAA[k][2];
						break;
					}

					else
						aa = 0;
				}
				for (l = 1; l < 20; l++)
				{
					if (BBB[l][0] == p && BBB[l][1] == j) {
						bb = BBB[l][2];
						break;
					}
					else
						bb = 0;
				}
				cc += (aa * bb);
			}
			CC[i][j] += cc;
			cc = 0;
		}
	}
	for (i = 0; i < 6; i++)
	{
		printf("\n");
		for (j = 0; j < 6; j++)
		{
			printf("%d ", CC[i][j]);
		}
	}
	count = 1;
	for (i = 0; i < 6; i++)//把C矩陣變成稀疏矩陣
	{
		for (j = 0; j < 6; j++)
		{
			if (CC[i][j] != 0)
			{
				CCC[count][0] = i;
				CCC[count][1] = j;
				CCC[count][2] = CC[i][j];
				count++;
			}
		}
	}
	CCC[0][0] = 6;
	CCC[0][1] = 6;
	CCC[0][2] = count - 1;

	printf("\n====================================\nA*B稀疏:\n");
	for (x = 0; x < count; x++)
	{
		printf("\n");
		for (y = 0; y < 3; y++)
		{
			printf("%d\t", CCC[x][y]);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
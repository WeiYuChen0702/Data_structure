#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
void way(int i, int j, int a[SIZE][SIZE]);

int main()
{
	int a[10][10] = { 0 };
	FILE* fp = fopen("2-1.txt", "r");
	if (fp == NULL)
	{
		printf("not!\n");
	}
	else {
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				fscanf(fp, "%d", &a[i][j]);
			}
		}
	}
	a[8][8] = 9;
	way(8, 8, a);

	for (int i = 0; i < SIZE; i++)
	{
		printf("\n");
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
	system("pause");
	return 0;
}
void way(int i, int j, int a[SIZE][SIZE])
{
	if (i == 1 & j == 1)
		return;
	if (a[i][j - 1] == 0)
	{
		a[i][j - 1] = 2;//¥k
		way(i, j - 1, a);
	}
	if (a[i - 1][j] == 0)
	{
		a[i - 1][j] = 3;//¤U
		way(i - 1, j, a);
	}
	if (a[i][j + 1] == 0)
	{
		a[i][j + 1] = 4;//¥ª
		way(i, j + 1, a);
	}
	if (a[i + 1][j] == 0)
	{
		a[i + 1][j] = 5;//¤W
		way(i + 1, j, a);
	}
}


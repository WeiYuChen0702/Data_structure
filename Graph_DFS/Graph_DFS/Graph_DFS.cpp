#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

struct link
{
	int val;
	struct link* next;
};
int run[8];
int n = 0;
void makeList(struct link* start[], int matrix[][8])
{
	struct link* currentPtr = NULL;
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (matrix[i][j] == 1)
			{
				struct link* newPtr = (struct link*)malloc(sizeof(struct link));
				newPtr->val = j;
				if (start[i] == NULL)
				{
					start[i] = newPtr;
					currentPtr = newPtr;
				}
				else
				{
					currentPtr->next = newPtr;
					currentPtr = newPtr;
				}
			}
		}
		currentPtr->next = NULL;
	}
}

void dfs(int current, struct link* start[])
{
	struct link* ptr;
	run[current] = 1;
	printf("[%d]  ", current);
	ptr = start[current];
	while (ptr != NULL)
	{
		if (run[ptr->val] == 0)
			dfs(ptr->val, start);
		ptr = ptr->next;
	}
}

int main()
{
	int matrix[8][8] = { 0 };
	int i = 0;
	struct link* start[8] = { NULL };
	FILE* fp;
	fp = fopen("1.txt", "r");
	fscanf(fp, "%d", &n);
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(fp, "%d", &matrix[i][j]);
		}
	}
	makeList(start, matrix);
	dfs(0, start);

	system("pause");
	return 0;
}
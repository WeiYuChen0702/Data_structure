#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

struct link
{
	int val;
	struct link* next;
};
int run[8];
int queue[8] = { 0 };
int addcount = 0;
int printcount = 0;
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

void addQ(int** Front, int** Rear, int current)
{
	queue[addcount] = current;
	addcount++;
	*Front = queue;
}

int deleteQ(int** Front, int** Rear, int current)
{
	int take = queue[0];
	for (int i = 0; i < 7; i++)
		queue[i] = queue[i + 1];
	addcount--;
	*Front = queue;
	return take;
}

void bfs(int current, struct link* start[])
{
	struct link* ptr;
	int* queueFront = NULL, * queueRear = NULL;
	printf("[%d] ", current);
	printcount++;
	run[current] = 1;
	addQ(&queueFront, &queueRear, current);
	ptr = start[current];
	while (printcount < 8)
	{
		current = deleteQ(&queueFront, &queueRear, current);
		for (struct link* w = start[current]; w; w = w->next)
		{
			if (!run[w->val])
			{
				printf("[%d] ", w->val);
				printcount++;
				addQ(&queueFront, &queueRear, w->val);
				run[w->val] = 1;
			}
		}
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
	bfs(0, start);

	system("pause");
	return 0;
}
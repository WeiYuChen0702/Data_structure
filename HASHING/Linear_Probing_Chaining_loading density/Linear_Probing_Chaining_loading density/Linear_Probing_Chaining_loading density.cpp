#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	node *nexnode;
};

typedef node *nodeptr;

void show(int showarrary[]);
void showbucket(int showarrary[10][3], int *count);
void shiftfolding(char numcode[20][30], int shift[20]);
void boundariesfolding(char numcode[20][30], int boundaries[20]);
void mod10(int testarray[], int newarray[10][3]);
void chaining(int testarray[]);

int main()
{
	char numcode[20][30];
	int shift[20] = { 0 }, boundaries[20] = { 0 }, count = 0, newshift[10][3] = { 0 };
	FILE *open = fopen("17.txt", "r");
	for (int i = 0; i < 20; i++)
	{
		fgets(numcode[i], 30, open);
	}
	fclose(open);
	puts("Origan：");
	for (int i = 0; i<20; i++)
	{
		printf("The digital of %d：%s", i + 1, numcode[i]);
	}
	puts("\n\nShift folding：");
	shiftfolding(numcode, shift);
	show(shift);
	puts("\n\nFolding at the boundaries：");
	boundariesfolding(numcode, boundaries);
	show(boundaries);
	puts("\n\nA new hash of shift folding：");
	mod10(shift, newshift);
	showbucket(newshift, &count);
	puts("\n\nThe final hash table by using Chaining of shift folding：");
	chaining(shift);
	printf("\n\nloading density ：%f", (float)count / 30);
	puts("");
	system("pause");
	return 0;
}

void show(int showarrary[])
{
	for (int i = 0; i<20; i++)
	{
		printf("The digital of %d：%d\n", i + 1, showarrary[i]);
	}
}

void showbucket(int showarrary[10][3], int *count)
{
	int key = 0;
	for (int i = 0; i < 10; i++)
	{
		key = 0;
		printf("Bucket %d：", i);
		for (int j = 0; j < 3; j++)
		{
			if (showarrary[i][j] != 0)
			{
				printf("%d ", showarrary[i][j]);
				key = 1;
				(*count)++;
			}
		}
		if (key == 0)
		{
			printf("NULL");
		}
		puts("");
	}
}

void shiftfolding(char numcode[20][30], int shift[20])
{
	int j;
	for (int i = 0; i <20; i++)
	{
		for (j = 0; j < strlen(numcode[i]) - 4; j += 3)
		{
			shift[i] += 100 * (numcode[i][j] - '0') + 10 * (numcode[i][j + 1] - '0') + (numcode[i][j + 2] - '0');//一開始
		}
		if ((strlen(numcode[i]) - j) % 3 == 1)
		{
			shift[i] += 100 * (numcode[i][j] - '0') + 10 * (numcode[i][j + 1] - '0') + (numcode[i][j + 2] - '0');//滿足3個數字
		}
		else if ((strlen(numcode[i]) - j) % 3 == 0)
		{

			shift[i] += 10 * (numcode[i][j] - '0') + (numcode[i][j + 1] - '0');//剩下的數字是2位數
		}
		else
		{
			shift[i] += numcode[i][j] - '0';//剩下的數字是1位數
		}
	}
}

void boundariesfolding(char numcode[20][30], int boundaries[20])
{
	int j;
	for (int i = 0; i < 20; i++)
	{
		for (j = 0; j < strlen(numcode[i]) - 4; j += 3)
		{
			if (j % 2 == 0)//基數
			{
				boundaries[i] += 100 * (numcode[i][j] - '0') + 10 * (numcode[i][j + 1] - '0') + (numcode[i][j + 2] - '0');
			}
			else//偶數
			{
				boundaries[i] += 100 * (numcode[i][j + 2] - '0') + 10 * (numcode[i][j + 1] - '0') + (numcode[i][j] - '0');
			}
		}
		if ((strlen(numcode[i]) - j) % 3 == 1)
		{
			if (j % 2 == 0)
			{
				boundaries[i] += 100 * (numcode[i][j] - '0') + 10 * (numcode[i][j + 1] - '0') + (numcode[i][j + 2] - '0');
			}
			else
			{
				boundaries[i] += 100 * (numcode[i][j + 2] - '0') + 10 * (numcode[i][j + 1] - '0') + (numcode[i][j] - '0');
			}
		}
		else if ((strlen(numcode[i]) - j) % 3 == 0)
		{
			if (j % 2 == 0)
			{
				boundaries[i] += 10 * (numcode[i][j] - '0') + (numcode[i][j + 1] - '0');
			}
			else
			{
				boundaries[i] += 10 * (numcode[i][j + 1] - '0') + (numcode[i][j] - '0');
			}
		}
		else
		{
			if (j % 2 == 0)
			{
				boundaries[i] += numcode[i][j] - '0';
			}
			else
			{
				boundaries[i] += +numcode[i][j] - '0';
			}
		}
	}
}

void mod10(int testarray[], int newarray[10][3])
{
	int resi;
	int resicount[10] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		resi = testarray[i] % 10;//求HASH
		while (resicount[resi] == 3)//目前有沒有滿3個
		{
			resi++;
			if (resi == 10)//HASH到第10個自動歸零 0~9
			{
				resi = 0;
			}
		}
		newarray[resi][resicount[resi]] = testarray[i];//存放新陣列 處理溢位
		resicount[resi]++;
	}
}

void chaining(int testarray[])
{
	nodeptr resibucket[10], current;
	int bucketcount[10] = { 0 }, resi;

	for (int i = 0; i < 20; i++)
	{
		nodeptr temp = (nodeptr)malloc(sizeof(nodeptr));
		temp->data = testarray[i];//
		temp->nexnode = NULL;//
		if (testarray[i] != 0)
		{
			resi = testarray[i] % 10;
			if (bucketcount[resi] != 0)
			{
				nodeptr resiindex = resibucket[resi];
				while (resiindex != NULL)
				{
					current = resiindex;
					resiindex = resiindex->nexnode;
				}
				current->nexnode = temp;
			}
			else
			{
				temp->nexnode = NULL;
				resibucket[resi] = temp;
				bucketcount[resi]++;
			}
		}
	}

	int key = 0;
	for (int i = 0; i < 10; i++)
	{
		key = 0;
		printf("Bucket %d：", i);
		if (bucketcount[i] != 0)
		{
			while (resibucket[i] != NULL)
			{
				if (key != 0)
				{
					printf(" -> ");
				}
				printf("%d ", resibucket[i]->data);
				resibucket[i] = resibucket[i]->nexnode;
				key++;
			}
		}
		else
		{
			printf("NULL");
		}
		puts("");
	}
}

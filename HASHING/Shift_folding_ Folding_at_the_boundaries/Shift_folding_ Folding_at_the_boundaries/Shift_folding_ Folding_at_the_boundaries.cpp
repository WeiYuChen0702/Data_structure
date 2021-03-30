#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
float cou = 0;
void bubble(int at[][SIZE], int slot[])
{
	int i = 0, j = 0;

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (j = 0; j < SIZE - 1 - i; j++)
		{
			int temp, temp1;
			if (slot[j] > slot[j + 1])
			{
				temp = slot[j + 1];
				slot[j + 1] = slot[j];
				slot[j] = temp;
				temp1 = at[0][j + 1];
				at[0][j + 1] = at[0][j];
				at[0][j] = temp1;

			}

		}
	}
}
void linear(int chaining[SIZE][SIZE],int linearX[SIZE][SIZE], int slot[SIZE])
{
	int count1 = 0;
	int temp[10] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		
		for (int j = 0; j < SIZE; j++)
		{
			
			if (j > 4 && chaining[i][j] != 0)
			{

			}
			else
			{
				linearX[i][j] = chaining[i][j];
			}
		}
	}

}
void chain(int at[][SIZE], int chaining[SIZE][SIZE], int slot[SIZE])
{
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (slot[i] == 0)
		{
			chaining[0][count1] = at[0][i];
			count1++;
		}
		else if (slot[i] == 1)
		{
			chaining[1][count2] = at[0][i];
			count2++;
		}
		if (slot[i] == 2)
		{
			chaining[2][count3] = at[0][i];
			count3++;
		}
		if (slot[i] == 3)
		{
			chaining[3][count4] = at[0][i];
			count4++;
		}
		if (slot[i] == 4)
		{
			chaining[4][count5] = at[0][i];
			count5++;
		}
		if (slot[i] == 5)
		{
			chaining[5][count6] = at[0][i];
			count6++;
		}
		if (slot[i] == 6)
		{
			chaining[6][count7] = at[0][i];
			count7++;
		}
		if (slot[i] == 7)
		{
			chaining[7][count8] = at[0][i];
			count8++;
		}
		if (slot[i] == 8)
		{
			chaining[8][count9] = at[0][i];
			count9++;
		}
	}
}
void open(int at[][SIZE])
{
	int chaining[SIZE][SIZE] = {};
	int count = 0;
	int x[SIZE] = {};//Shift folding and Folding at the boundaries
	int k = 0;
	int linearX[SIZE][SIZE] = {};
	char num[3] = {}, num1[3] = {};
	int chanum = 0, chanum1 = 0;
	char c;
	FILE *cp;
	int slot[SIZE] = {};
	cp = fopen("17.txt", "r");

	for (int i = 0; i < SIZE; i++)
	{
		num[0] = '0';
		num[1] = '0';
		num[2] = '0';
		k = 3;

		while (1)
		{
			k = 3;
			for (int j = 0; j < 3; j++)
			{
				fscanf(cp, "%c", &c);
				if (c == '\n')
				{
					if (j == 1)
					{
						num[2] = num[0];
						num[1] = '0';
						num[0] = '0';
						chanum = atoi(num);
						at[0][i] = chanum + at[0][i];
						x[i] = chanum + x[i];
						num1[2] = '0';
						num1[0] = '0';
					}
					if (j == 2)
					{
						num[2] = num[1];
						num[1] = num[0];
						num[0] = '0';
						chanum = atoi(num);
						at[0][i] = chanum + at[0][i];
						x[i] = chanum + x[i];
						num1[2] = '0';
					}
					break;

				}
				num[j] = c;
				num1[--k] = c;
			}
			if (c == '\n')
			{
				break;
			}
			chanum = atoi(num);//沒有顛倒
			chanum1 = atoi(num1);//被顛倒
			at[0][i] = chanum + at[0][i];

			if (count % 2 == 1)
			{
				x[i] = chanum1 + x[i];
				count++;
			}
			else if (count % 2 == 0)
			{
				x[i] = chanum + x[i];
				count++;
			}


		}
		slot[i] = at[0][i] % 10;
		count = 0;
		cou++;

		printf("%d\t%d\t%d\n", at[0][i], slot[i], x[i]);

	}
	bubble(at, slot);
	chain(at, chaining, slot);
	linear(chaining, linearX, slot);
	printf("Chaining (x)\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("\n");
		for (int j = 0; j < SIZE; j++)
		{
			if (chaining[i][j] != 0)
			{
				printf("%d\t", chaining[i][j]);
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("\n");
		for (int j = 0; j < SIZE; j++)
		{
			if (linearX[i][j] != 0)
			{
				printf("%d\t", linearX[i][j]);
			}
		}
	}
}

int main()
{
	int at[2][SIZE] = { 0 };
	open(at);

	float y = cou / (10 * 3);
	printf("%.3f", y);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findshort(int choosenode, int orig[5][5]);
void showpoint(int start, int end, int dis);
void showload(int resi, int lastnode[5], int start);
void shownode(int resi);

int main()
{
	FILE* open = fopen("2.txt", "r");
	int row = 0, col = 0, orig[5][5];
	char choose[5] = { 0 }, g, node[2][3], * cut;
	if (open == NULL)
	{
		printf("開檔失敗");
	}
	else
	{

		while (!feof(open))
		{

			fscanf(open, "%c ", &g);
			fscanf(open, "%c ", &g);
			fscanf(open, "%c ", &g);
			fscanf(open, "%c ", &g);
			fscanf(open, "%c ", &g);
			fscanf(open, "%c ", &g);
			fscanf(open, "%c ", &g);
			for (int i = 0; i < 5; i++)
			{
				fscanf(open, "%c ", &g);
				for (int j = 0; j < 5; j++)
				{
					fscanf(open, "%d ", &orig[i][j]);
					if (orig[i][j] == 0)
					{
						orig[i][j] = 999;
					}
				}
			}

		}
	}
	printf("檔案內容：\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (orig[i][j] == 999)
			{
				printf("0 ");
			}
			else
			{
				printf("%d ", orig[i][j]);
			}
		}
		puts("");
	}
	while (strcmp(node[0], "-1") != 0)
	{
		printf("\n請問要算哪個點到其餘點的最短距離(只有s.t.x.y.z):\n(-1 結束) ");
		gets_s(node[0]);
		while (strcmp(node[0], "-1") != 0 && strcmp(node[0], "s") && strcmp(node[0], "t") && strcmp(node[0], "x") && strcmp(node[0], "y") && strcmp(node[0], "z"))
		{
			printf("Start node error,enter start node again: ");
			gets_s(node[0]);
		}
		if (strcmp(node[0], "s") == 0)
		{
			printf("s -> s = 0 (s)\n");
			findshort(0, orig);
		}
		else if (strcmp(node[0], "t") == 0)
		{
			printf("t -> t = 0 (t)\n");
			findshort(1, orig);
		}
		else if (strcmp(node[0], "x") == 0)
		{
			printf("x -> x = 0 (x)\n");
			findshort(2, orig);
		}
		else if (strcmp(node[0], "y") == 0)
		{
			printf("y -> y = 0 (y)\n");
			findshort(3, orig);
		}
		else if (strcmp(node[0], "z") == 0)
		{
			printf("z -> z = 0 (z)\n");
			findshort(4, orig);
		}
	}
	puts("");
	system("pause");
	return 0;
}

void findshort(int choosenode, int orig[5][5])
{
	int resi, min, count = 1, next;
	int lastnode[5], shortextdis[5] = { 0 }, visit[5] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		shortextdis[i] = orig[choosenode][i];
		lastnode[i] = choosenode;
		visit[i] = 0;
	}

	visit[choosenode] = 1;
	shortextdis[choosenode] = 0;

	while (count < 4)
	{
		min = 999;

		for (int i = 0; i < 5; i++)
		{
			if (shortextdis[i] < min && visit[i] != 1)
			{
				min = shortextdis[i];
				next = i;
			}
		}
		visit[next] = 1;

		for (int i = 0; i < 5; i++)
		{
			if (visit[i] != 1)
			{
				if (min + orig[next][i] < shortextdis[i])
				{
					shortextdis[i] = min + orig[next][i];
					lastnode[i] = next;
				}
			}
		}
		count++;
	}

	for (int i = 0; i < 5; i++)
	{
		if (choosenode != i)
		{
			printf("\n");
			showpoint(choosenode, i, shortextdis[i]);
			showload(i, lastnode, choosenode);
			shownode(i);
			printf(")\n");
		}
	}
}

void showpoint(int start, int end, int dis)
{
	shownode(start);
	printf("-> ");
	shownode(end);
	printf(" = %d ( ", dis);
}

void showload(int resi, int lastnode[5], int start)
{
	int res;

	if (resi != start)
	{
		res = lastnode[resi];
		showload(res, lastnode, start);
		shownode(res);
	}
}

void shownode(int resi)
{
	switch (resi)
	{
	case 0:
		printf("s ");
		break;
	case 1:
		printf("t ");
		break;
	case 2:
		printf("x ");
		break;
	case 3:
		printf("y ");
		break;
	case 4:
		printf("z ");
		break;
	}
}
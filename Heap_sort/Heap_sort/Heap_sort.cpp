//[演算法] 插入排序法(Heapsort)
#include<stdio.h>
#include<stdlib.h>
//16 14 10 8 7 9 3 2 4 1

int input(int input1[], int cou)
{
	int num = 0;
	printf("Input：(0結束)\n");
	while (1)
	{
		scanf("%d", &num);

		if (num == 0)
		{
			break;
		}
		else
		{
			input1[cou] = num;
			cou++;
		}
	}
	return cou;
}

void output(int Heap[], int cou)
{
	int i = 0;
	printf("Array：\n");
	for (i = 0; i < cou; i++)
	{
		printf("%d\t", Heap[i]);
	}
	printf("\n");
}

void swap(int heap[], int i, int j) {
	int tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
}

void Heapsort(int heap[], int couu)
{
	int i = 0;
	for (int cou = couu; cou > 0; cou--)
	{
		if (cou % 2 != 0)//基數
		{
			for (i = cou; i > 2; i = i - 2)
			{
				if (heap[i - 1] > heap[(i - 1) / 2 - 1])
				{
					swap(heap, i - 1, (i - 1) / 2 - 1);
				}
				if (heap[i - 2] > heap[(i - 1) / 2 - 1])
				{
					swap(heap, i - 2, (i - 1) / 2 - 1);
				}
			}
		}
		else
		{
			if (heap[cou - 1] > heap[cou / 2 - 1])
			{
				swap(heap, cou - 1, cou / 2 - 1);
			}
			for (i = cou - 1; i > 2; i = i - 2)
			{
				if (heap[i - 1] > heap[(i - 1) / 2 - 1])
				{
					swap(heap, i - 1, (i - 1) / 2 - 1);
				}
				if (heap[i - 2] > heap[(i - 1) / 2 - 1])
				{
					swap(heap, i - 2, (i - 1) / 2 - 1);
				}
			}
		}
		output(heap, couu);
		swap(heap, 0, cou - 1);
	}
}

int del(int heap[], int cou)
{
	int index = 0;
	printf("輸入要刪除的位置(0為開頭):");
	scanf("%d", &index);
	if (index >= 0 && index < cou)
	{
		swap(heap, index, cou - 1);
		heap[cou - 1] = 0;
		cou--;
	}
	else
	{
		printf("輸入範圍錯誤");
	}
	return cou;
}


void modi(int heap[], int cou)
{
	int index = 0;
	printf("輸入要修改的位置(0為開頭):");
	scanf("%d", &index);
	if (index >= 0 && index < cou)
	{
		printf("修改成甚麼數字？");
		scanf("%d", &heap[index]);
	}
	else
	{
		printf("輸入範圍錯誤");
	}
}

int main()
{
	int heap[100] = { 0 };
	int cou = 0;
	int cho = 0;

	cou = input(heap, cou);
	output(heap, cou);
	Heapsort(heap, cou);
	//output(heap, cou);

	while (1)
	{
		printf("1)排序  2) 新增字  3)刪除字  4)修改字   5)印出  -1)跳出");
		scanf("%d", &cho);
		if (cho == 1)//排序
		{
			Heapsort(heap, cou);
		}
		else if (cho == 2)//新增
		{
			cou = input(heap, cou);
			Heapsort(heap, cou);
			output(heap, cou);
		}
		else if (cho == 3)//刪除
		{
			cou = del(heap, cou);
			output(heap, cou);
			Heapsort(heap, cou);
			output(heap, cou);
		}
		else if (cho == 4)//修改
		{
			modi(heap, cou);
			Heapsort(heap, cou);
			output(heap, cou);
		}
		else if (cho == 5)//印出
		{
			output(heap, cou);
		}
		else if (cho == -1)//跳出
		{
			break;
		}
		else
		{
			printf("輸入錯誤");
		}
	}

	system("pause");
	return 0;
}
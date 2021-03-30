//[�t��k] ���J�ƧǪk(Heapsort)
#include<stdio.h>
#include<stdlib.h>
//16 14 10 8 7 9 3 2 4 1

int input(int input1[], int cou)
{
	int num = 0;
	printf("Input�G(0����)\n");
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
	printf("Array�G\n");
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
		if (cou % 2 != 0)//���
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
	printf("��J�n�R������m(0���}�Y):");
	scanf("%d", &index);
	if (index >= 0 && index < cou)
	{
		swap(heap, index, cou - 1);
		heap[cou - 1] = 0;
		cou--;
	}
	else
	{
		printf("��J�d����~");
	}
	return cou;
}


void modi(int heap[], int cou)
{
	int index = 0;
	printf("��J�n�ק諸��m(0���}�Y):");
	scanf("%d", &index);
	if (index >= 0 && index < cou)
	{
		printf("�ק令�ƻ�Ʀr�H");
		scanf("%d", &heap[index]);
	}
	else
	{
		printf("��J�d����~");
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
		printf("1)�Ƨ�  2) �s�W�r  3)�R���r  4)�ק�r   5)�L�X  -1)���X");
		scanf("%d", &cho);
		if (cho == 1)//�Ƨ�
		{
			Heapsort(heap, cou);
		}
		else if (cho == 2)//�s�W
		{
			cou = input(heap, cou);
			Heapsort(heap, cou);
			output(heap, cou);
		}
		else if (cho == 3)//�R��
		{
			cou = del(heap, cou);
			output(heap, cou);
			Heapsort(heap, cou);
			output(heap, cou);
		}
		else if (cho == 4)//�ק�
		{
			modi(heap, cou);
			Heapsort(heap, cou);
			output(heap, cou);
		}
		else if (cho == 5)//�L�X
		{
			output(heap, cou);
		}
		else if (cho == -1)//���X
		{
			break;
		}
		else
		{
			printf("��J���~");
		}
	}

	system("pause");
	return 0;
}
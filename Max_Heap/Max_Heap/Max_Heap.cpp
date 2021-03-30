#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define  Comp(A,B) ((heapMode==MINHEAP)?(A<B):(A>B))
const int Max = 32;
const int MAXHEAP = 2;
const int MINHEAP = 1;
int heap[Max + 1];
int heapSize = 0;
int heapMode = 0;
void Heap_init();

// 上升
int HeapUp(int i)
{
	int y = heap[i];
	for (int c = i / 2; c > 0 && Comp(y, heap[c]); c /= 2)
	{
		heap[i] = heap[c];
		i = c;
	}
	heap[i] = y;
	return i;
}
// 下降
int HeapDown(int i)
{
	int y = heap[i];
	for (int c = 2 * i; c <= heapSize; c *= 2)
	{
		if (c < heapSize && Comp(heap[c + 1], heap[c]))
			c++;
		if (Comp(y, heap[c])) break;
		heap[i] = heap[c];
		i = c;
	}
	heap[i] = y;
	return i;
}
// 調整為 Heap
void Heap_init()
{
	for (int i = heapSize / 2; i >= 1; i--)
		HeapDown(i);
}
// 插入
int Heap_insert(int d)
{
	if (heapSize == Max)
		return 0;
	heap[++heapSize] = d;
	return HeapUp(heapSize);
}
//比較
int compare(int i)
{
	int temp = 0;
	if (heap[2 * i] > heap[i])
	{
		temp = heap[i];
		heap[i] = heap[2 * i];
		heap[2 * i] = temp;
		compare(2 * i);
		return i;
	}
	else if (heap[i] < heap[2 * i + 1])
	{
		temp = heap[i];
		heap[i] = heap[2 * i + 1];
		heap[2 * i + 1] = temp;
		compare(2 * i + 1);
		return i;
	}
	return -1;
}
// 刪除
int Heap_delete(int d)
{
	int i = 0;
	int k = 0, g = 0;
	for (i = 1; i <= heapSize; i++)
	{
		if (heap[i] == d)
		{
			heap[i] = heap[heapSize];
			heap[heapSize] = 0;
			heapSize--;
			break;
		}
	}
	g = log2(i);//要刪除的在第幾層
	k = log2(heapSize);//總共有幾層
	k = k - g;
	for (int c = 0; c < k; c++)
	{
		compare(i);
	}
	return -1;
}

int main(void) {
	int number[100] = {};
	int value1 = 0, value2 = 0;
	int temp[100] = {};
	int i, num, op = 0, count = 0;
	int n = 0, m = 0, o = 0;

	printf("原本有幾個:");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("輸入(%d):", i);
		scanf("%d", &number[i]);
		if (number[i] == 0)
		{
			printf("不能是0!\n");
			scanf("%d", &number[i]);
		}
		count++;
	}
	for (i = 0, heapSize = count; i < count; i++)
		heap[i + 1] = number[i];

	Heap_init();
	for (i = 1; i < count + 1; i++)
		printf("%d ", heap[i]);
	printf("\n");
	while (op != -1)
	{
		printf("1:新增2:刪除-1:跳出");
		scanf("%d", &op);

		if (op == 1)
		{
			printf("輸入要新增的數字:");
			scanf("%d", &value1);
			m++;
			Heap_insert(value1);
			for (i = 1; i <= count + m + o; i++)
			{
				if (heap[i] == NULL)
					printf(" ");
				else
					printf("%d ", heap[i]);
			}
			printf("\n");
		}
		else if (op == 2)
		{
			printf("輸入要刪除的數字:");
			scanf("%d", &value2);
			o++;
			Heap_delete(value2);


			for (i = 1; i <= count + o + m; i++)
			{

				if (heap[i] == 0)
					printf("   ");
				else
					printf("%d ", heap[i]);
			}
			printf("\n");
		}
		else if (op == -1)
			break;
	}
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int index, cow;//指數 係數
};

//二維加法
void sort(struct poly a1[], int count);
void view(struct poly a1[], int i);
int main(void)
{
	poly arr[100], arr1[100], arr2[100], count1[100], count2[100];
	int num1 = 0, num2 = 0, temp1 = 0, temp2 = 0, ch = 0, k = 0;
	printf("多項式A幾項:");
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d %d", &arr[i].cow, &arr[i].index);
	}
	sort(arr, num1);

	for (int i = 0; i < num1; i++)
	{
		printf("%d %d ", arr[i].cow, arr[i].index);
	}

	printf("\n多項式B幾項:");
	scanf("%d", &num2);
	for (int i = 0; i < num2; i++)
	{
		scanf("%d %d", &arr1[i].cow, &arr1[i].index);
	}
	sort(arr1, num2);
	for (int i = 0; i < num2; i++)
	{
		printf("%d %d ", arr1[i].cow, arr1[i].index);
	}
	printf("\n");
	for (int i = 0; i < num1; i++)
	{
		ch = 0;
		for (int j = 0; j < num2; j++)
		{
			if (arr[i].index == arr1[j].index)
			{
				count1[k].index = arr[i].index;
				count1[k].cow = arr[i].cow + arr1[j].cow;
				k++;
				ch = 1;
			}
		}
		if (ch == 0)
		{
			count1[k].cow = arr[i].cow;
			count1[k].index = arr[i].index;
			k++;
		}
	}
	for (int i = 0; i < num2; i++)
	{
		ch = 0;
		for (int j = 0; j < num1; j++)
		{
			if (arr1[i].index == arr[j].index)
			{
				ch = 1;
			}
		}
		if (ch == 0)
		{
			count1[k].cow = arr1[i].cow;
			count1[k].index = arr1[i].index;
			k++;
		}
	}
	sort(count1, k);
	printf("加:");
	view(count1, k);
	printf("\n");



	system("pause");
	return 0;
}

void view(struct poly a1[], int i)
{
	int count = 0, count2 = 0;
	for (int j = 0; j < i; j++)
	{
		if (j < i - 1 && a1[j].cow>0)
		{
			if (count == 0) {
				printf("%dX^%d", a1[j].cow, a1[j].index);
				count++;
			}
			else
				printf("+%dX^%d", a1[j].cow, a1[j].index);
		}
		else if (j < i - 1 && a1[j].cow < 0)
		{
			printf("%dX^%d", a1[j].cow, a1[j].index);
			count++;
		}
		else if (a1[j].cow == 0)
		{
			count2++;
		}
		else if (a1[j].cow == 0 && a1[j].index == 0)
			printf("0");
		else
			printf("+%dX^%d", a1[j].cow, a1[j].index);
	}
	printf("\n");
	if (count == 0)
	{
		if (count2 != 0)
		{
			printf("0\n");
		}
	}
}

void sort(struct poly a1[], int count)
{
	poly temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (a1[j].index < a1[j + 1].index)
			{
				temp = a1[j];
				a1[j] = a1[j + 1];
				a1[j + 1] = temp;
			}
		}
	}

}

#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int temp[100] = { 0 };
	int arr[100] = { 0 }, arr1[100] = { 0 };
	int MOD[100] = { 0 };
	int count2 = 0; int count = 0; int count3 = 0;
	int  K = 0, set = 0, num = 0, num2 = 0, temp1 = 0, temp2 = 0;
	printf("輸入多項式A幾項:");
	scanf("%d", &num);
	printf("輸入A多項式：\n");//輸入A
	for (int x = 0; x < 2 * num; x++)
	{

		scanf("%d", &arr[x]);
	}
	for (int i = 1; i < 2 * num; i = i + 2)
	{
		for (int j = 1; j < 2 * num; j = j + 2)
		{
			if (arr[j] > arr[i])
			{
				temp1 = arr[j];
				arr[j] = arr[i];
				arr[i] = temp1;
				temp2 = arr[j - 1];
				arr[j - 1] = arr[i - 1];
				arr[i - 1] = temp2;
			}
		}
	}


	printf("輸入多項式B幾項:");
	scanf("%d", &num2);
	printf("輸入B多項式：\n");//輸入B
	for (int x = 0; x < 2 * num2; x++)
	{
		scanf("%d", &arr1[x]);
	}
	for (int i = 1; i < 2 * num2; i = i + 2)
	{
		for (int j = 1; j < 2 * num2; j = j + 2)
		{
			if (arr1[j] > arr1[i])
			{
				temp1 = arr1[j];
				arr1[j] = arr1[i];
				arr1[i] = temp1;
				temp2 = arr1[j - 1];
				arr1[j - 1] = arr1[i - 1];
				arr1[i - 1] = temp2;
			}
		}
	}


	printf("二多項式相乘：\n");//乘法
	int k = 0;
	for (int i = 0; i < 100; i = i + 2)
	{
		for (int j = 0; j < 100; j = j + 2)
		{
			if (arr[i] * arr1[j] == 0)
				continue;
			temp[k] = arr[i] * arr1[j];
			MOD[k] = arr[i + 1] + arr1[j + 1];
			k++;
		}
	}

	int ans[100] = { 0 };
	for (int i = 0; i < 100; i++)
	{
		if (temp[i] == 0)
			continue;
		ans[MOD[i]] = ans[MOD[i]] + temp[i];
	}

	for (int i = 99; i >= 0; i--)
	{
		if (ans[i] != 0)
		{
			if (ans[i] < 0)
			{
				printf("%dX^%d", ans[i], i);
				count2++;
			}
			else
			{
				if (count2 == 0) {
					printf(" %dX^%d", ans[i], i);
					count2++;
				}
				else
					printf(" + %dX^%d", ans[i], i);
			}
		}
	}
	system("pause");
	return 0;
}

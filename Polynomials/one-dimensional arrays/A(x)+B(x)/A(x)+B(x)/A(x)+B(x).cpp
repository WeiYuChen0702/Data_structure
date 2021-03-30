#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//針對多項式的項式數目
	int num1[100], num2[100], num3[100];
	int number1 = 0, number2 = 0, count = 0, count1 = 0, count2 = 0, count3 = 0, temp1, temp2;
	printf("多項式1幾項:");//針對多項式的項式數目
	scanf("%d", &number1);
	printf("多項式1:\n");//由常數項(最小位開始輸入，先輸入次方項再輸入常數項
	for (int x = 0; x < 2 * number1; x++)
	{
		scanf("%d", &num1[x]);
	}

	for (int i = 1; i < 2 * number1; i = i + 2)
	{
		for (int j = 1; j < 2 * number1; j = j + 2)
		{
			if (num1[j] > num1[i])
			{
				temp1 = num1[j];
				num1[j] = num1[i];
				num1[i] = temp1;
				temp2 = num1[j - 1];
				num1[j - 1] = num1[i - 1];
				num1[i - 1] = temp2;
			}
		}
	}



	printf("\n多項式2幾項:");
	scanf("%d", &number2);
	printf("多項式2:\n");
	for (int x = 0; x < 2 * number2; x++)
	{
		scanf("%d", &num2[x]);
	}

	for (int i = 1; i < 2 * number2; i = i + 2)
	{
		for (int j = 1; j < 2 * number2; j = j + 2)
		{
			if (num2[j] > num2[i])
			{
				temp1 = num2[j];
				num2[j] = num2[i];
				num2[i] = temp1;
				temp2 = num2[j - 1];
				num2[j - 1] = num2[i - 1];
				num2[i - 1] = temp2;
			}
		}
	}


	printf("\n");
	for (int i = 1; i < 2 * number1; i = i + 2)
	{
		count1 = 0;
		for (int j = 1; j < 2 * number2; j = j + 2)
		{
			if (num1[i] == num2[j])
			{
				num3[count] = num1[i - 1] + num2[j - 1];
				count++;
				num3[count] = num1[i];
				count++;
			}
			if (num1[i] != num2[j])
			{
				count1++;
			}
		}
		if (count1 == number2)
		{
			num3[count] = num1[i - 1];
			count++;
			num3[count] = num1[i];
			count++;
		}
	}

	for (int i = 1; i < 2 * number2; i = i + 2)
	{
		count1 = 0;
		for (int j = 1; j < 2 * number1; j = j + 2)
		{
			if (num2[i] != num1[j])
			{
				count1++;
			}
		}
		if (count1 == number1)
		{
			num3[count] = num2[i - 1];
			count++;
			num3[count] = num2[i];
			count++;
		}
	}

	for (int i = 1; i < count; i = i + 2)
	{
		for (int j = i; j < count; j = j + 2)
		{
			if (num3[j] > num3[i])
			{
				temp1 = num3[j];
				num3[j] = num3[i];
				num3[i] = temp1;
				temp2 = num3[j - 1];
				num3[j - 1] = num3[i - 1];
				num3[i - 1] = temp2;
			}
		}
	}
	for (int i = 0; i < count; i = i + 2)
	{

		if (num3[i] > 0 && i > 1)
			printf("+");


		if (num3[i] > 0 || num3[i] < 0)
		{
			printf("%dX", num3[i]);
			printf("^%d", num3[i + 1]);
			count2++;
		}
	}
	if (count2 == 0)
		printf("0");


	system("pause");
	return 0;
}
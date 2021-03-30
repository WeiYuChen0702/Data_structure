//(a+b)*c
#include <stdio.h> 
#include <stdlib.h>

int main(void) {
	char infix[100] = { '\0' };//中序
	int r1 = 0, r2 = 0, sum = 0;
	int i = 0, stcou = 0;
	char stack[100] = { '\0' };
	int str = 0, end = 0, big = 0, little = 0, com1 = 0, com2 = 0;

	printf("infix：");
	scanf("%s", infix);

	if (infix[0] == '+' || infix[0] == '-' || infix[0] == '*' || infix[0] == '/' || infix[0] == ')')
	{
		str = 1;
	}
	while (infix[i] != '\0')
	{
		if (infix[i] == '(')//遇到(
		{
			com1 = com1 + 1;
		}
		else if (infix[i] == ')')//遇到)
		{
			com2 = com2 + 1;
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')//遇到+-*/
		{
			little = little + 1;
		}
		else//遇到數字
		{
			big = big + 1;
		}
		i++;
	}
	--i;
	if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '(')
	{
		end = 1;
	}
	sum = big - little;
	if (str == 1 || end == 1 || big <= little || com1 != com2 || sum != 1)
	{
		printf("錯誤");
	}
	else
	{
		r1 = 0, r2 = 0;
		i = 0, stcou = 0;
		str = 0, end = 0, big = 0, little = 0, com1 = 0, com2 = 0;

		while (infix[i] != '\0')
		{


			if (infix[i] == '(')//遇到(
			{
				//com1=com1+1;
				stack[stcou++] = infix[i];
			}
			else if (infix[i] == ')')//遇到)
			{
				//com2=com2+1;
				stcou--;
				while (stack[stcou] != '(')
				{
					printf("%c", stack[stcou--]);
				}
			}
			else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')//遇到+-*/
			{
				little = little + 1;
				stack[stcou++] = infix[i];
			}
			else//遇到數字
			{
				big = big + 1;
				printf("%c", infix[i]);//直接印出
			}

			i++;
		}
		--i;
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '(')
		{
			end = 1;
		}

		--stcou;
		while (stcou >= 0)
		{
			if (stack[stcou] != '(')
			{
				printf("%c", stack[stcou--]);
			}
		}
	}
	system("pause");
	return 0;
}

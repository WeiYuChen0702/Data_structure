
#include<stdio.h>
#include<stdlib.h>

struct a
{
	int s, e;
};

void sort(struct a a1[], int count)
{
	a temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (a1[j].e < a1[j + 1].e)
			{
				temp = a1[j];
				a1[j] = a1[j + 1];
				a1[j + 1] = temp;
			}
		}
	}

}
void view(struct a a1[], int i)
{
	for (int j = 0; j < i; j++)
	{
		if (a1[j].s == 0 && a1[j].e != 0)
		{
			while (a1[j].s != 0)
			{
				j++;
			}
		}
		else if (j < i - 1 && a1[j + 1].s>0)
			printf("%dX^%d+", a1[j].s, a1[j].e);
		else if (j < i - 1 && a1[j + 1].s < 0)
			printf("%dX^%d", a1[j].s, a1[j].e);

		else if (a1[j].s == 0 && a1[j].e == 0)
			printf("0");
		else
			printf("%dX^%d", a1[j].s, a1[j].e);
	}
	printf("\n");

};

int insert(struct a a1[])
{
	int i = 0;
	while (1)
	{

		printf("輸入第%d個係數", i + 1);
		scanf("%d", &a1[i].s);
		if (a1[i].s == 1000)
			break;
		printf("輸入第%d個指數", i + 1);
		scanf("%d", &a1[i].e);
		i++;
	}
	sort(a1, i);
	view(a1, i);
	return i;
}
int main()
{

	int k = 0, count1 = 0, count2 = 0, ch;
	struct a a1[50], a2[50], a3[50], a4[50], a5[50];

	count1 = insert(a1);
	count2 = insert(a2);

	for (int i = 0; i < count1; i++)
	{
		ch = 0;
		for (int j = 0; j < count2; j++)
		{
			if (a1[i].e == a2[j].e)
			{
				a3[k].e = a1[i].e;
				a3[k].s = a1[i].s + a2[j].s;
				k++;
				ch = 1;
			}

		}

		if (ch == 0)
		{
			a3[k].e = a1[i].e;
			a3[k].s = a1[i].s;
			k++;
		}
	}
	for (int i = 0; i < count2; i++)
	{
		ch = 0;
		for (int j = 0; j < count1; j++)
		{
			if (a2[i].e == a1[j].e)
			{
				ch = 1;
			}

		}

		if (ch == 0)
		{
			a3[k].e = a2[i].e;
			a3[k].s = a2[i].s;
			k++;
		}
	}
	sort(a3, k);
	view(a3, k);
	k = 0;
	for (int i = 0; i < count1; i++)
	{

		for (int j = 0; j < count2; j++)
		{
			a4[k].e = a1[i].e + a2[j].e;
			a4[k].s = a1[i].s * a2[j].s;
			k++;

		}
	}

	sort(a4, k);
	k = 0;
	for (int i = 0; i < count1 * count2; i++)
	{
		ch = 0;
		for (int j = 0; j < count1 * count2; j++)
		{
			if (i != j && a4[i].e == a4[j].e && ch == 0)//只有一個相同指數的數字
			{
				a5[k].e = a4[i].e;
				a5[k].s = a4[i].s + a4[j].s;
				k++;
				ch++;
			}
			else if (i != j && ch != 0 && a4[i].e == a4[j].e)//如果有兩個以上相同指數的數字
			{
				k--;
				a5[k].e = a4[i].e;
				a5[k].s += a4[j].s;
				k++;
				ch++;

			}
		}
		if (ch == 0)
		{
			a5[k].s = a4[i].s;
			a5[k].e = a4[i].e;
			k++;
		}
		else
		{
			i += ch;
		}
	}

	view(a5, k);

	system("pause");
	return 0;
}
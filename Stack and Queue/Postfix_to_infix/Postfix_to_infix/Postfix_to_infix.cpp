//ABC*+D-
#include<stdio.h>
#include<stdlib.h>
#include<string>
int main()
{
	char o[100] = {}, s[100][100] = {}, p[100] = {};
	int oo = 0, ss = 0, pp = 0, pn = 0;
	int m = 0, mm = 0;//a
	char mc[100] = {}, mmc[100] = {};
	char n[2] = { '(',')' };
	int error = 0;
	printf("��J���򦡡G");
	scanf("%s", p);
	pn = strlen(p);
	while (p[pp] != '\0')
	{
		if (p[pp] == '+' || p[pp] == '-' || p[pp] == '*' || p[pp] == '/')
		{
			if (s[1][0] == '\0')
			{
				printf("���~");
				error = 1;
				break;
			}
			else
			{
				m = strlen(s[--ss]);//�ƻs��b
				for (int i = 0; i < m; i++)
				{
					mc[i] = s[ss][i];
					s[ss][i] = '\0';
				}
				mm = strlen(s[--ss]);//�ƻs��a
				for (int i = 0; i < mm; i++)
				{
					mmc[i] = s[ss][i];
					s[ss][i] = '\0';
				}
				////�B�z��J
				s[ss][0] = n[0];//;��(
				for (int i = 1; i < mm + 1; i++)//��a
				{
					s[ss][i] = mmc[i - 1];
					mmc[i - 1] = '\0';
				}
				s[ss][mm + 1] = p[pp];//��Ÿ�
				int  j = 0;
				for (int i = mm + 2; i < m + mm + 2; i++)//��b
				{
					s[ss][i] = mc[j];
					mc[j] = '\0';
					j++;
				}
				s[ss][m + mm + 2] = n[1];//��)
				ss++;
			}
		}
		else
		{
			s[ss++][0] = p[pp];
		}
		pp++;
	}
	if (s[1][0] != '\0' || error == 1)
	{
		printf("���~");
	}
	else
	{
		printf("���Ǭ��G%s\n", s[0]);
	}
	system("pause");
	return 0;
}
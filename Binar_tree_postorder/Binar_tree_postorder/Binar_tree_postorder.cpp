#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree
{
	char data;
	struct Tree* left;
	struct Tree* right;
};

struct Tree* order(char* inorder, char* postorder, int length)//�L�e��
{
	int root = 0;
	if (length == 0)
		return NULL;
	struct Tree* newPtr = (struct Tree*)malloc(sizeof(struct Tree));
	newPtr->data = *(postorder + length - 1); //�q��ǧ���
	printf("%c ", newPtr->data);//�L�X��
	for (root = 0; root < length; root++)//�q���Ǥ����ڪ����b��M�k�b��
	{
		if (inorder[root] == *(postorder + length - 1))//���b�����
			break;
	}
	newPtr->left = order(inorder, postorder, root);//���j��
	newPtr->right = order(inorder + root + 1, postorder + root, length - (root + 1));//�k�j��
	return newPtr;
}

int main()
{
	char inorder[15];
	char postorder[15];
	int length = 0;
	struct Tree* startPtr = NULL;

	printf("�п�J��ǡG");
	gets_s(postorder);
	printf("�п�J���ǡG");
	gets_s(inorder);

	length = strlen(postorder);
	startPtr = order(inorder, postorder, length);
	printf("\n");

	system("pause");
	return 0;
}
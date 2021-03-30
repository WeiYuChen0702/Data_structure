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

struct Tree* order(char* inorder, char* preorder, int length)//�L���
{
	int root = 0;
	if (length == 0)
		return NULL;
	struct Tree* newPtr = (struct Tree*)malloc(sizeof(struct Tree));
	newPtr->data = *preorder; //��
	for (root = 0; root < length; root++)//�q���Ǥ����ڪ����b��M�k�b��
	{
		if (inorder[root] == *preorder)//���b�����
			break;
	}
	newPtr->left = order(inorder, preorder + 1, root);//���j��
	newPtr->right = order(inorder + root + 1, preorder + root + 1, length - (root + 1));//�k�j��
	printf("%c ", newPtr->data);//�쩳�L�X
	return newPtr;
}

int main()
{
	char inorder[10];
	char preorder[10];
	int length = 0;
	struct Tree* startPtr = NULL;

	printf("�п�J�e�ǡG");
	gets_s(preorder);
	printf("�п�J���ǡG");
	gets_s(inorder);

	length = strlen(preorder);
	startPtr = order(inorder, preorder, length);
	printf("\n");

	system("pause");
	return 0;
}
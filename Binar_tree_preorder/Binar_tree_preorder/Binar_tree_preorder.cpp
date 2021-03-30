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

struct Tree* order(char* inorder, char* preorder, int length)//印後序
{
	int root = 0;
	if (length == 0)
		return NULL;
	struct Tree* newPtr = (struct Tree*)malloc(sizeof(struct Tree));
	newPtr->data = *preorder; //根
	for (root = 0; root < length; root++)//從中序中找到根的左半邊和右半邊
	{
		if (inorder[root] == *preorder)//左半邊長度
			break;
	}
	newPtr->left = order(inorder, preorder + 1, root);//左大邊
	newPtr->right = order(inorder + root + 1, preorder + root + 1, length - (root + 1));//右大邊
	printf("%c ", newPtr->data);//到底印出
	return newPtr;
}

int main()
{
	char inorder[10];
	char preorder[10];
	int length = 0;
	struct Tree* startPtr = NULL;

	printf("請輸入前序：");
	gets_s(preorder);
	printf("請輸入中序：");
	gets_s(inorder);

	length = strlen(preorder);
	startPtr = order(inorder, preorder, length);
	printf("\n");

	system("pause");
	return 0;
}
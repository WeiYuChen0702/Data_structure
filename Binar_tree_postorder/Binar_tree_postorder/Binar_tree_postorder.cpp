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

struct Tree* order(char* inorder, char* postorder, int length)//印前序
{
	int root = 0;
	if (length == 0)
		return NULL;
	struct Tree* newPtr = (struct Tree*)malloc(sizeof(struct Tree));
	newPtr->data = *(postorder + length - 1); //從後序找到根
	printf("%c ", newPtr->data);//印出來
	for (root = 0; root < length; root++)//從中序中找到根的左半邊和右半邊
	{
		if (inorder[root] == *(postorder + length - 1))//左半邊長度
			break;
	}
	newPtr->left = order(inorder, postorder, root);//左大邊
	newPtr->right = order(inorder + root + 1, postorder + root, length - (root + 1));//右大邊
	return newPtr;
}

int main()
{
	char inorder[15];
	char postorder[15];
	int length = 0;
	struct Tree* startPtr = NULL;

	printf("請輸入後序：");
	gets_s(postorder);
	printf("請輸入中序：");
	gets_s(inorder);

	length = strlen(postorder);
	startPtr = order(inorder, postorder, length);
	printf("\n");

	system("pause");
	return 0;
}
#include<stdio.h>
//��ʽ�洢������
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

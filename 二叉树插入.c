#include<stdio.h>
BinTree Insert(ElementType X,BinTree BST)
{
	//���ж�������ǲ���Ϊ�գ��յĻ���ֱ����Ҫ��������������
//����һ���µ�������
	if(!BST){
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}else
		//�����Ϊ�վͺͲ��Ҷ�����һ�����뵽��Ҫ��λ��
		if(X<BST->Data)
		//�õݹ�ʵ��
		BST->Left = Insert(X,X->Left);//�����������Ϊ�յ�ʱ��ͷ�������
		else if(X>BST->Data)
			BST->Right = Insert(X,X->Right);
		//������뵽��ȵĻ���ʲôҲ����
		return BST;
}

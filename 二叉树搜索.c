#include<stdio.h>
//�����������Ĳ��ҷ��������õݹ�ʵ�ֵ�
Position Find(ElementType X,BinTree BST)
{
	//if��Ϊ�վ�ֱ�ӷ���
	if(!BST)
		return NULL;
	//if��Ϊ��������ж�������ڵĻ������ҵݹ�
	if(X>BST->Data)
		return Find(X,BST->Right);
	//���С�Ļ�������������ߵݹ�
	else if(x<BST->Data)
		return Find(X,BST->Left);
	//����Ȳ������ֲ�С�ھ�����Ⱦͷ������ֵ
	else
		return BST;
}
//���Ƿǵݹ�ĺ���ִ��Ч�ʸߣ��ɽ������β�ݹ��Ϊѭ���ṹ
Position IterFind(ElementType X,BinTree BST)
{
	//ֻҪ���վ�һֱѭ�����򷵻�NULL
	while(BST)
	{
		if(X>BST->Data)
			BST = BST->Right;
		else if(X<BST->Data)
			BST = BST->left;
		else 
			return BST;
	}
	return NULL;
}
//������������С����ֻҪ��Ϊ��һֱ��������
Position FindMin(BinTree BST)
{
	if(!BST)
		return NULL;
	//�Ѿ��ҵ����һ��������
	else if(!BST->left)
		return BST;
	else return FindMin(BST->left);
}
//����������һ�����������ѭ������
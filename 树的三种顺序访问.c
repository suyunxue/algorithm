#include<stdio.h>
//���������1.���ʸ��ڵ� 
//2.��������������� 3.���������������
void PreOrderTraversal(BinTree BT)
{
	if(BT){
	printf("%d",BT->Data);
	PreOrderTraversal(BT->Left);
	PreOrderTraversal(BT->Right);
	}
}

//������� 1.��������������� 2.���ʸ���� 
//3�����������������
void InOrderTraversal(BinTree BT)
{
	if(BT){
		InOrderTraversal(BT->Left);
		printf("%d",BT->Data);
		InOrderTraversal(BT->Right);
	}
}
//������� 1.��������������� 2.��������������� 3.���ʸ����
void PostOrderTraversal(BinTree BT)
{
	if(BT){
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d",BT->Data);
	}
}
//��������ķǵݹ��㷨
void InOrderTraversal(BinTree BT)
{
	BinTree T BT;
	Stack s = CreatStack(MaxSize);//��������ʼ����ջs
	while(T || !IsEmpty(s)){
		while(T){
			Push(S,T);
			T = T->Left;
		}
		if(!IsEmpaty(s)){
			T = Pop(s);//��㵯����ջ
			printf("%5d",T->Data);//���ʴ�ӡ���
			T = T->right;//ת��������
		}
	}
}
//����������Ҷ�ӽ��
//�ڶ������б����㷨������ӽ������������Ƿ�Ϊ��
void PreOrderPrintLeaves(BinTree BT)
{
	if(BT)
	{
		if(!BT->left && !BT->Right)
			printg("%d",BT->Data);
		PreOrderPrintLeavers(BT->Left);
		PreOrderPrintLeavers(BT->right);
	}
}
//���������߶�
int PostOrderGetHeight(BinTree BT)
{
	int HL , HR, MaxH;
	if(BT)
	{
		HL = PostOrderGetHeight(BT->Left);
		HR = PostOrderGetHeight(BT->right);
		MaxH = (HL>HR) ? HL : HR;//ȡ�����нϴ�����
		return (MaxH+1);//�������
	}
}
//ɾ�����Ĺ��̡���ǰ��һ�����Ƿ��ص�����
BinTree Delete(ElementType X,BinTree BST)
{
	//ɾ����ʱ��ע�����������
	//1ɾ�����Ϊ�յĻ�
	Position Tmp;//Ҫ��λ���Ǹ�ֵ
	if(!BST) printf("Ҫɾ���Ľ��û�ҵ�");
	else if(X< BST->Data)//���ҵ�Ҫɾ�����Ǹ�����
		BST->Left = Delete(X,BST->Left);
	else if(X>BST->Data)
		BST->Right = Delete(X,BST->Right);
	else//�ҵ�Ҫɾ���Ľ��֮���Ϊ�������
		//��һ��Ҫɾ�����������ӽ�㶼�еĽ��
		if(BST->Left && BST->Right)
		{
			//���ҽ�㶼���ڵĻ��������ұ���С��Ԫ�����ɾ�����
			Tmp = FindMin(BST->Right);
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data,BST->Right);//��ɾ��������������ɾ����СԪ��
		}
	//ʣ�µ��Ǳ�ɾ���Ľ����һ�������ӽ��
		else{
			Tmp = BST;
			if(!BST->Left)//���к��ӻ����ӽ��
				BST = BST->Right;
			else if(!BST->Right)//�����ӻ����ӽ��
				BST = BST->Left;
			//���ɾ����֮��Ҫ�ͷŵ�ԭ������Ŀռ�
			free(Tmp);
		}
		return BST;


}
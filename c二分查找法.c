//���ֲ��ұ��������飬���ұ����Ǵ�С�������
int BinarySearch(StaticTable *Tbl;ElementType k)
{
	int left ,right,mid,NotFound=-1;
	left=1;
	right=Tbl->Length;
	while(left <= right)
	{
		mid = (left+right)/2;//�����м��Ԫ������
		if(k->Tbl->Element[mid])
			right=mid+1;
		else if(k->Tbl->Element[mid])
			left=mid-1;
		else return mid;//���ҵ������ز��ҵ���Ԫ���±�
	}
	return NotFound;
}
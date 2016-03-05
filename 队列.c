#define MaxSize
typedef struct{
	ElementType Data[MaxSize];
	int rear;
	int front;
}Queue;
void addQ(Queue *PtrQ,ElementType item)
{
	if((PtrQ->rear+1)%MaxSize == PtrQ->front)
	{
		printf("������");
		return;
	}
	PtrQ->rear=(PtrQ->rear+1)%MaxSize;
	return PtrQ->Data[PtrQ->rear]=item ;
}
ElementType DeleteQ(Queue *PtrQ)
{
	if(PtrQ->front==Ptr->rear){
		printf("���п�");
		return ERROR;
	}else{
		PtrQ->front=(PtrQ->front+1)%MaxSize;
		return PtrQ->Data[PtrQ->front];

	}
	
}
typedef struct Node{
	ElementType Data;
	struct Node *Next;
}QNode;
typedef struct{
	QNode *rear;
	QNode *front;

}LinkQueue;
LinkQueue *PtrQ;
//������
ElementType DeleteQ(LinkQueue *PtrQ)
{
	Qnode *FrontCell;
	ElementType FrontElem;
	if(PtrQ->front == NULL){
		printf("���п�");
		return ERROR;
	}

	FrontCell = PtrQ->front;
	if(PtrQ->front == PtrQ->rear)
		PtrQ->front=PtrQ->rear=NULL;
	else
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);
	return FrontElem;
}
//����ʽ�ӷ�
Polynomial PolyAdd(Polynomial P1,Polynomial P2)
{
	//����������ʽÿ���Ƚ���Ⱦ�ϵ�����
	//���ָ����ľ͸��ƽ�ȥָ����һ��С�Ĳ���
	//���ָ��С��Ѵ�ĸ��ƽ�ȥָ����һ����С�Ĳ���
	Polynomial font,rear,temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(PolyNode));
	front = rear;
	while(P1 & P2)
		switch(Compare(P1->expon,P2->expon)){
		case 1:
			Attch(P1->coef,P1->expon,&rear);
			P1=P1->link;
			break;
		case -1:
			Attch(P2->coef,P1->expon,&rear);
			P2=P2->link;
			break;
		case 0:
			sum = P1->coef+P2->coef;
			P1 = P1->link;
			P2 = P2->link;
			break;
	}
	//��δ�������˶���ʽ�����нڵ㸴�Ƶ�����ʽ��
	for(;P1;P1=P1->link)
		Attach(P1->coef;P1->expon,&rear);
	for(;P2;P2=P2->link)
		Attach(P2->coef;P2->expon,&rear);
	rear->link = NULL;
	temp = front;
	front = front->link;//��frontָ��������ʽ�ĵ�һ��������
	free(temp);//�ͷ���ʱ�ձ�ͷ���
	return front;
}
void Attach(int coef,int expon,Polynomai *PtrRear)
{
	//PtrRear��Ҫ��ӵ�ĩβָ��
	Polynomial P;
	P=(Polynomian)malloc(sizeof(PolyNode));
	P->coef=coef;
	P->expon=expon;
	(*PtrRear)->link=P;//��ĩβ׷�Ӷ���ʽ
	*PtrRear = P;//�޸�ĩβָ���ֵ
}












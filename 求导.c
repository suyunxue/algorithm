#include<stdio.h>
//����ʽ�������⣬����ϵ����ָ�����ؽṹ�������
/*struct typedef POLYNOMIAL{
	int coefficient;
	int index;
	Polynomial *next;
}Polynomial;
void derivaltive(Polynomial *p)
{
	for(;p;p->next)
	{
		p->coefficient = p->coefficient*p->index;
		p->index=p->index-1;
	}

}*/
int main()
{

	int n,e,flag=0;
	printf("��������Ҫ�󵼵Ķ���ʽ������ϵ�� ָ����˳��ָ���Ӵ�С����");
	while(scanf("%d %d",&n,&e)!=EOF)
	{
		if(flag)
		{
			printf(" ");
		}
		else
		{
			flag = 1;
		}
		printf("%d %d\n",n*e,e-1);
	}
	if(flag != 0)
		printf("0 0");
	return 0;


}

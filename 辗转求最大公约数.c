#include<stdio.h>
void main()
{
	int a = 40;
	int b = 24;
    int c = a%b;//�����ĳ�����Ҫa>b�����a<b��Ҫ��a��b��λ�ý���
	//Ҫ�Ӽ�������������������������
	while(c!=0){
		a = b;
		b = c;
		c = a%b;
	}
	printf("%d�������Լ��\n",b);
}


#include<stdio.h>
#include<stdlib.h>
int main(void) {
	//��̬�ڴ����,�н��л���������ԭʼ������Ǹ�������ԭ�ⲻ���Ļ����˼�
	int *p = 0;
	int cnt=0;
	while((p=malloc(100*1024*1024))) {
		cnt++;
	}
	printf("������%d00MB�Ŀռ�\n",cnt);
	return 0;
}

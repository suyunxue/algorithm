#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define PAGE 6
typedef struct
{  int year;
   int month;
   int day;
}DATE;
typedef struct   /*ѧ����Ϣ�ṹ��*/
{  char name[15];    /*����*/
   char sex[5];    /*�Ա�*/
   char hometown[20];    /*����*/ 
   char group[10];    /*����*/
   DATE birthday;    /*��������*/
   char xibie[20];    /*ϵ��*/
   char zhuanye[20];    /*רҵ*/ 
   int  banji;     /*�༶*/
   char num[10];     /*ѧ��*/
   DATE in_time;     /*��ѧ����*/
}STU;
/*���ļ�ģ��*/
int read_file(STU stu[])
{ 
    FILE *fp;
   int i=0;
   if((fp=fopen("student.txt","rt"))==NULL)
   { 
	   printf("\n\n*****�ļ�������!�봴��!*****");
      return 0;
   }
  while(feof(fp)!=1)
  {   fscanf(fp,"%s%s%s%s%d%d%d%s%s%d%s%d%d%d",stu[i].name,stu[i].sex,stu[i].group,stu[i].hometown,
		&stu[i].birthday.year,&stu[i].birthday.month,&stu[i].birthday.day,stu[i].xibie,
		stu[i].zhuanye,&stu[i].banji,stu[i].num,&stu[i].in_time.year,&stu[i].in_time.month,&stu[i].in_time.day);

   if(stu[i].num[0]=='0')
		 break;
	  else
		  i++;
   }
   fclose(fp);
   return i;   /*����������Ϣ��ѧ���ĸ���*/
}
/*���ݴ���ģ��*/
void save_file(STU stu[],int sum)
{  FILE *fp;
   int i;
   if((fp=fopen("student.txt","wt"))==NULL)
   {  printf("���ļ�����!\n");
      return;
   }
   for(i=0;i<sum;i++)
   {
	   fprintf(fp,"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%s\t%s\t%d\t%s\t%d\t%d\t%d\n",stu[i].name,stu[i].sex,stu[i].group,stu[i].hometown,stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day,stu[i].xibie,stu[i].zhuanye,stu[i].banji,stu[i].num,stu[i].in_time.year,stu[i].in_time.month,stu[i].in_time.day);
   }  
   fprintf(fp,"z z z z 0 0 0 z z 0 0 0 0 0\n");
	   fclose(fp);
}
/*����ģ��*/
int input(STU stu[])
{  int i=0;
   char choice;
   system("cls");
   printf("\n\n     ¼��ѧ����Ϣ(���%d��)\n",MAX);
   printf("-----------------------------------------\n\n");
   do
   {  printf("\n             ��%d��ѧ����Ϣ",i+1);
      printf("\n       ����:");
	  scanf("%s",stu[i].name);
	  printf("\n       �Ա�:");
	  scanf("%s",stu[i].sex);
	  printf("\n       ����:");
	  scanf("%s",stu[i].group);
	  printf("\n       ����:");
	  scanf("%s",stu[i].hometown);
	  printf("\n       ��������:");
	  scanf("%d-%d-%d",&stu[i].birthday.year,&stu[i].birthday.month,&stu
      [i].birthday.day);
	  printf("\n       ϵ��:");
	  scanf("%s",stu[i].xibie);
	  printf("\n       רҵ:");
	  scanf("%s",stu[i].zhuanye);
	  printf("\n       �༶:");
	  scanf("%d",&stu[i].banji);
	  printf("\n       ѧ��:");
	  scanf("%s",stu[i].num);
	  printf("\n       ��ѧ����:");
	  scanf("%d-%d-%d",&stu[i].in_time.year,&stu[i].in_time.month,&stu[i].in_time.day);
	  i++;
	  printf("�Ƿ��������?(Y/N)");
	  getchar();   
	  choice=getchar();
         if(choice=='n'||choice=='N')
		 break;
   }while(i<MAX);
   printf("\n---------%d��ѧ�������������!---------\n",i);
   printf("           ��������������˵�!\n");
   getchar();
   getchar();
   return i;
}
/*���ģ��*/
void output(STU stu[],int sum)
{  
	int i=0,j=0,page=1;
     system("cls");
     printf("\n����������������������������������������");
       printf("\n\n--------ѧ����Ϣ��----��%dҳ--------\n\n",page);
       printf("����---�Ա�---����---����---��������---ϵ��---רҵ---�༶---ѧ��---��ѧ����\n");
       printf("---------------------------------------------------------------------------\n");
   while(i<sum)
   {  j++;
      if(j%PAGE!=0)
	  {printf(" %s\t%s\t%s\t%s\t%d_%d_%d\t%s\t%s\t%d\t%s\t%d_%d_%d\n",stu[i].name,stu[i].sex,stu[i].group,stu[i].hometown,stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day,stu[i].xibie,stu[i].zhuanye,stu[i].banji,stu[i].num,stu[i].in_time.year,stu[i].in_time.month,stu[i].in_time.day);
       printf("--------------------------------------------------------------------------\n");
	}
	  else
	  {   printf("****�����������!****\n");
	      getchar();
       printf("\n\n--------ѧ����Ϣ��----��%dҳ--------\n\n",++page);
	   printf("����---�Ա�---����---����---��������---ϵ��---רҵ---�༶---ѧ��---��ѧ����\n");
	   printf("---------------------------------------------------------------------------\n");
	   printf(" %s\t%s\t%s\t%s\t%d_%d_%d\t%s\t%s\t%d\t%s\t%d_%d_%d\n",stu[i].name,stu[i].sex,stu[i].group,stu[i].hometown,stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day,stu[i].xibie,stu[i].zhuanye,stu[i].banji,stu[i].num,stu[i].in_time.year,stu[i].in_time.month,stu[i].in_time.day);
       printf("--------------------------------------------------------------------------\n");
	  }
	  i++;
   }
   printf("��������������˵�!");
   getchar();
   getchar();
}
/*���ģ��*/
add(STU stu[],int sum)
{   
    int i,n;
	printf("      �����ѧ����Ϣ!��\n");
    printf("�������������������\n");
    printf("��������Ҫ�����Ϣ��ѧ���ĸ���:");
	scanf("%d",&n);
	if(n<=MAX-sum)
    {	for(i=sum;i<sum+n;i++)
	{   system("cls");
		printf("��������Ҫ��ӵĵ�%d��ѧ����Ϣ!\n",i-sum+1);
	    printf("------------------------------------------------------");
        printf("\n       ����:");
	    scanf("%s",stu[i].name);
	    printf("\n       �Ա�:");
	    scanf("%s",stu[i].sex);
	    printf("\n       ����:");
	    scanf("%s",stu[i].group);
	    printf("\n       ����:");
	    scanf("%s",stu[i].hometown);
	    printf("\n       ��������:");
	    scanf("%d-%d-%d",&stu[i].birthday.year,&stu[i].birthday.month,&stu[i].birthday.day);
	    printf("\n       ϵ��:");
	    scanf("%s",stu[i].xibie);
	    printf("\n       רҵ:");
	    scanf("%s",stu[i].zhuanye);
	    printf("\n       �༶:");
	    scanf("%d",&stu[i].banji);
	    printf("\n       ѧ��:");
	    scanf("%s",stu[i].num);
	    printf("\n       ��ѧ����:");
	    scanf("%d-%d-%d",&stu[i].in_time.year,&stu[i].in_time.month,&stu[i].in_time.day);
	    printf("------------------------------------------------------\n");
	}
	    printf("���%dѧ����Ϣ���!\n",n);
    }
    else
	    printf("�������%d��ѧ����Ϣ",MAX-sum);
	printf("��������������˵�!");
	getchar();
    getchar();
	return sum+n;
}
/*1.��ѧ�Ų�ѯ*/
void inquire_num(STU stu[],int sum)
{   int i;
	char num1[10];
	printf("������ѧ��:");
    scanf("%s",num1);
	for(i=0;i<sum;i++)
    { if(strcmp(num1,stu[i].num)==0)
	{ 
			system("cls");
			printf("\n��Ҫ��ѯ��ѧ����Ϣ����:\n");
	  printf("����---�Ա�---����---����---��������---ϵ��---רҵ---�༶---ѧ��---��ѧ����\n");
      printf("---------------------------------------------------------------------------\n");
      printf(" %s\t%s\t%s\t%s\t%d_%d_%d\t%s\t%s\t%d\t%s\t%d_%d_%d\n",stu[i].name,stu[i].sex,stu[i].group,stu[i].hometown,stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day,stu[i].xibie,stu[i].zhuanye,stu[i].banji,stu[i].num,stu[i].in_time.year,stu[i].in_time.month,stu[i].in_time.day);
      printf("--------------------------------------------------------------------------\n");
	}
	}
}
 
/*2.��������ѯ*/
void inquire_name(STU stu[],int sum)
{   int i;
    char name1[15];
	printf("����������:");
	scanf("%s",name1);
	for(i=0;i<sum;i++)
	{  if(strcmp(name1,stu[i].name)==0)
	{  
			system("cls");
			printf("��Ҫ��ѯ��ѧ����Ϣ����:\n");
	   printf("����---�Ա�---����---����---��������---ϵ��---רҵ---�༶---ѧ��---��ѧ����");
       printf("---------------------------------------------------------------------------\n");
       printf("%s\t%s\t%s\t%s\t%d_%d_%d\t%s\t%s\t%d\t%s\t%d_%d_%d\n",stu[i].name,stu[i].sex,stu[i].group,stu[i].hometown,stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day,stu[i].xibie,stu[i].zhuanye,stu[i].banji,stu[i].num,stu[i].in_time.year,stu[i].in_time.month,stu[i].in_time.day);
       printf("--------------------------------------------------------------------------\n");
	}
	}
}   
/*��ѯѧ����Ϣģ��*/
void inquire(STU stu[],int sum)
{  int choice;
   do
   { 
   printf("      ****************ѧ����Ϣ��ѯ******************\n");
   printf("                      1.��ѧ�Ų�ѯ\n");
   printf("                      2.��������ѯ\n");
   printf("                      0.�������˵�\n");
   printf("                     ����ѡ��0-2��\n");
   scanf("%d",&choice);
   switch(choice)
   {   case 1:inquire_num(stu,sum);   break;
       case 2:inquire_name(stu,sum);   break;
	   case 0:     break;
   }
   }while(choice!=0);
   printf("��������������˵�!\n");
   getchar();
   getchar();
}
/*�޸���Ϣģ��*/
void modify(STU stu[],int sum)
{   int i,choice,k;
	char num1[10];
	printf("������ѧ��:");
    scanf("%s",num1);
	for(i=0;i<sum;i++)
    { if(strcmp(num1,stu[i].num)==0)
	{ printf("ԭ��Ϣ����:\n");
	  printf("����---�Ա�---����---����---��������---ϵ��---רҵ---�༶---ѧ��---��ѧ����\n");
      printf("---------------------------------------------------------------------------\n");
      printf(" %s\t%s\t%s\t%s\t%d_%d_%d\t%s\t%s\t%d\t%s\t%d_%d_%d\n",stu[i].name,stu[i].sex,stu[i].group,stu[i].hometown,stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day,stu[i].xibie,stu[i].zhuanye,stu[i].banji,stu[i].num,stu[i].in_time.year,stu[i].in_time.month,stu[i].in_time.day);
      printf("--------------------------------------------------------------------------\n");
      k=i;
	}
	}
	do{
	  printf("        *************�޸�ѧ����Ϣ***********\n");
	  printf("     ------------------------------------------------\n");
	  printf("                   1.��������\n");
	  printf("                   2.���Ա�\n");
	  printf("                   3.�����塿\n");
	  printf("                   4.�����᡿\n");
	  printf("                   5.���������¡�\n");
	  printf("                   6.��ϵ��\n");
	  printf("                   7.��רҵ��\n");
	  printf("                   8.���༶��\n");
	  printf("                   9.��ѧ�š�\n");
	  printf("                  10.����ѧ���¡�\n");
	  printf("                   0.���������˵���\n");
	  printf("                   ����ѡ��0-10��\n");
	  scanf("%d",&choice);
	  switch(choice)
	  {   case 1:printf("\n�������޸ĺ������:");
                   scanf("%s",stu[k].name);
				   printf("\n�޸����!\n");   break;
	      case 2:printf("\n�������޸ĺ���Ա�:");
                   scanf("%s",stu[k].sex);
				   printf("\n�޸����!\n");   break;
		  case 3:printf("\n�������޸ĺ������:");
                   scanf("%s",stu[k].group); 
				   printf("\n�޸����!\n");   break;
		  case 4:printf("\n�������޸ĺ�ļ���:");
                   scanf("%s",stu[k].hometown);
				   printf("\n�޸����!\n");   break;
		  case 5:printf("\n�������޸ĺ�ĳ�������(xxxx-xx-xx):");
                 scanf("%d-%d-%d",&stu[k].birthday.year,&stu[k].birthday.month,&stu[k].birthday.day); 
				 printf("\n�޸����!\n");    break;
		  case 6:printf("\n�������޸ĺ��ϵ��:");
                   scanf("%s",stu[k].xibie);
				   printf("\n�޸����!\n");    break;
		  case 7:printf("\n�������޸ĺ��רҵ:");
                   scanf("%s",stu[k].zhuanye);
				   printf("\n�޸����!\n");    break;
		  case 8:printf("\n�������޸ĺ�İ༶:");
                   scanf("%d",&stu[k].banji);  
				   printf("\n�޸����!\n");   break;
		  case 9:printf("\n�������޸ĺ��ѧ��:");
                   scanf("%s",stu[k].num);  
				   printf("\n�޸����!\n"); 
				   break;
		  case 10:printf("\n�������޸ĺ����ѧ����(xxxx-xx-xx):");
                 scanf("%d-%d-%d",&stu[k].in_time.year,&stu[k].in_time.month,&stu[k].in_time.day); 
				   printf("\n�޸����!\n");    break;
		  case  0:       break;
	  }
	}while(choice!=0);
}
/*ɾ����Ϣģ��*/
del(STU stu[],int sum)
{   int i,j;
    char num1[10];

         printf("��������Ҫɾ����ѧ��ѧ��:");
	     scanf("%s",num1);
		 for(i=0;i<=sum;i++)
		 { if(strcmp(num1,stu[i].num)==0)
		  {for(j=i;j<sum-1;j++)
		    stu[j]=stu[j+1];
		    printf("\n��ѧ����Ϣ��ɾ��!\n");
		 }
		 if(i==sum+1)
		 {  printf("\n��ѧ��������!");
		 }
		 }
		 printf("   ��������������˵�!");
		 getchar();
		 getchar();
		 return(sum-1);
	}
/*����ģ��*/
void sort(STU stu[],int sum)/*��ѧ����������*/
{  int i,j,k;
   STU t;
   for(i=0;i<sum-1;i++)
   {  k=i;
	   for(j=i+1;j<sum;j++)
	  { if(strcmp(stu[k].num,stu[j].num)>0)
	     k=j;
	   }
	   if(k!=i)
	   { t=stu[i];
         stu[i]=stu[k];
		 stu[k]=t;
	   }
   }
   printf("����ѧ��������������\n");
   output(stu,sum);

}
/*ͳ��ģ��*/
count(STU stu[],int sum)
{  int count=0,i;
   char zhuanye_1[20],xibie_1[20],choice;
   int banji_1;
     printf("\n��������Ҫͳ�Ƶ�ϵ��:");
     scanf("%s",xibie_1);
     printf("\n\n��������Ҫͳ�Ƶ�רҵ:");
     scanf("%s",zhuanye_1);
     printf("\n\n��������Ҫͳ�Ƶİ༶:");
     scanf("%d",&banji_1);
     for(i=0;i<sum;i++)
	 {if((strcmp(stu[i].xibie,xibie_1)==0)&&(strcmp(stu[i].zhuanye,zhuanye_1)==0)&&(stu[i].banji==banji_1))
       count++;
	 }
     printf("\n��Ҫͳ�Ƶ�%sϵ%sרҵ%d�������Ϊ:%d\n",xibie_1,zhuanye_1,banji_1,count);
		 
  printf("\n�����������\n");
  getchar();
  getchar();
}
main()
{   STU stu[MAX];
    int choice,sum,zhanghao,mima;
	printf("�����������˺�!");
	scanf("%d",&zhanghao);
	printf("��������������!");
	scanf("%d",&mima);
	if(zhanghao==123&&mima==123)
	{sum=read_file(stu);
	getch();
	if(sum==0)
	{  printf("\n****��¼��ѧ����Ϣ!****\n");
	   getchar();
	   sum=input(stu);
	}
    
    system("cls");	
	do
	{ 	system("cls");	
	printf("%d",sum);
	  printf("\n\n");
	  printf("          ����������������������������������������������\n");
	  printf("          ----------------------------------------------\n");
	  printf("\t\t\t1.��ѯѧ����Ϣ\n");
	  printf("\t\t\t2.���ѧ����Ϣ\n");
	  printf("\t\t\t3.�޸�ѧ����Ϣ\n");
	  printf("\t\t\t4.ɾ��ѧ����Ϣ\n");
	  printf("\t\t\t5.���ѧ����Ϣ\n");
	  printf("\t\t\t6.ͳ��ѧ������\n");
	  printf("\t\t\t7.ѧ����Ϣ����\n");
	  printf("\t\t\t0.�˳�ϵͳ\n");
	  printf("\t\t\t����ѡ��(0-7)��\n");
	  printf("          ----------------------------------------------\n");
	  printf("          ����������������������������������������������\n");
	  scanf("%d",&choice);
	  switch(choice)
	  {   case 1:inquire(stu,sum);  break;
	      case 2:output(stu,sum);  break;
		  case 3:modify(stu,sum);  break;
		  case 4:sum=del(stu,sum);  break;
		  case 5:sum=add(stu,sum);  break;
		  case 6:count(stu,sum);   break;
		  case 7:sort(stu,sum);  break;
		  case 8:save_file(stu,sum);  break;
		  case 0:      break;
	  }
	}while(choice!=0);
    save_file(stu,sum);
	}
}
    

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
void printArr(int *a){
	int i=0;
	printf("---------------------------------------------\n");
	for(;i<10;i++){
		printf("%d\n",a[i]);
	}
	printf("---------------------------------------------\n");
}
//�����������������˻�Ϊָ��
void printArr2(int *a,int Num){
	int i=0;
	for(;i<Num;i++){
		printf("%d\n",a[i]);
	}
}
//2���β�������ֵ�char buf[30] int a[10] c/c++���������������ָ�룬Ҳ���������Ķ�����ڴ�
//day2�Ժ�
//�����������������˻�Ϊָ��
void printfArray3(int a[10])
{
	int i = 0;
	int num1 = sizeof(a);
	int num2 = sizeof(*a);
	int num = sizeof(a)/sizeof(*a);
	printf("num1:%d, num2:%d, num:%d \n", num1, num2, num);
	for (i=0; i<num; i++)
	{
		printf("%d  ", a[i]);
	}
}

int main01(int arg,char *argv[])
{
	//shif+delɾ��һ��
	int i = 0, j = 0;
	int a[10] = {1, 3, 44, 2, 3, 44, 5, 5,6, 67};
	int tmp = 0;
	printf("sort before===============\n");
	//printArr(a);
	//printArr2(a,10);
	printfArray3(a);
	for(i=0; i<10; i++)
	{
		for (j=i+1;j<10; j++)
		{
			if (a[i] < a[j])
			{
				tmp = a[i]; 
				a[i] = a[j]; 
				a[j] = tmp;
			}
		}
	}
	printf("sort after ===============\n");
	//printArr(a);
	//	printArr2(a,10);
		printfArray3(a);
	printf("hello,world!\n");
	system("pause");
}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//������ ��λ���� �������Դ洢�����Դ������������������˻�������
//��ά��������������ʱ����ά���������ǿ����ά����ά�Ͳ�����
//ָ��������������Ч�ڴ�β�� ֱ������
void myprint(int *p,int num){
	int i;
	for(i=0;i<num;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
void myprint2(char (*p)[30],int num){
	int i;
	for(i=0;i<num;i++){
		printf("%s  ",p[i]);
	}
	printf("\n");
}


int main1010101001(int arg,char *args[]){
	int arr[3][5];
	int tmp=0;
	int i=0;
	int j=0;
	int *p=NULL;
	char myt[10][30]={"abc","ddd","ddddd"};
	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			arr[i][j]=tmp;
			*(*(arr+i) +j)	= tmp;
			tmp++;
		}
	}
	p=(int *)arr;
	myprint(p,3*5);
	myprint2(myt,3);
	system("pause");
	return 1;
}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct MyTea{
	char name[64];//˳��һ���ڴ��С��һ��,�����ڴ�����Ĵ�С��ŵĿ��ܻ��������ֽ�
	int age;
};
/************************************************************************/
/* ��ӡ�ķ���                                                                     */
/************************************************************************/
void	printArray(struct MyTea *tarray,int count){
	int i;
	for(i=0;i<4;i++){
		printf("%d  ",tarray[i].age);
	}
	printf("\n");
}
/************************************************************************/
/* ����ķ���                                                                     */
/************************************************************************/
void	sortArray(struct MyTea *tarray,int count){
	int i;
	int j;
	struct MyTea tmp;
	for(i=0;i<4;i++){
		for(j=i;j<count;j++){
			if(tarray[i].age>tarray[j].age){
				tmp = tarray[i];
				tarray[i]=tarray[j];
				tarray[j]=tmp;
			}
		}
	}
}
int main04440(int argc,char * args[]){
	struct MyTea tArray[10];
	int i;
	for(i=0;i<4;i++){
		int tmp=0;
		printf("\n������age: ");
		scanf("%d",&tArray[i].age);
	}
	printf("***********sort before***************\n");
	printArray(tArray,4);
	sortArray(tArray,4);
	printf("***********sort after ***************\n");
	printArray(tArray,4);
	system("pause");
}
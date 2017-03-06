#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct MyTea{
	char name[64];//顺序不一样内存大小不一样,按照内存变量的大小存放的可能会多出几个字节
	int age;
};
/************************************************************************/
/* 打印的方法                                                                     */
/************************************************************************/
void	printArray(struct MyTea *tarray,int count){
	int i;
	for(i=0;i<4;i++){
		printf("%d  ",tarray[i].age);
	}
	printf("\n");
}
/************************************************************************/
/* 排序的方法                                                                     */
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
		printf("\n请输入age: ");
		scanf("%d",&tArray[i].age);
	}
	printf("***********sort before***************\n");
	printArray(tArray,4);
	sortArray(tArray,4);
	printf("***********sort after ***************\n");
	printArray(tArray,4);
	system("pause");
}
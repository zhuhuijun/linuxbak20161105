#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct AdvMyTea{
	char name[64];//顺序不一样内存大小不一样,按照内存变量的大小存放的可能会多出几个字节
	char *alice;
	int age;
	char ** studentname;
};
/************************************************************************/
/* 打印的方法                                                                     */
/************************************************************************/
void	printArray2(struct AdvMyTea *tarray,int count){
	int i;
	int j;
	for(i=0;i<4;i++){
		printf("%d  ",tarray[i].age);
		printf("%s  ",tarray[i].name);
		printf("%s ",tarray[i].alice);//没有内存哪来的指针
		for(j=0;j<3;j++){
			char **p2=tarray[i].studentname;
			printf("%s  ",p2[j]);
		}
		printf("\n");
	}
	printf("\n");
}
/************************************************************************/
/* 排序的方法                                                                     */
/************************************************************************/
void	sortArray2(struct AdvMyTea *tarray,int count){
	int i;
	int j;
	struct AdvMyTea tmp;
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
/************************************************************************/
/* 在堆上分配内存                                                                     */
/************************************************************************/
struct AdvMyTea * createArray2(int count){
	int i=0;
	int j;
	struct AdvMyTea *p1=(struct AdvMyTea *)malloc(count*sizeof(struct AdvMyTea));
	if(p1 == NULL)
	{
		return NULL;
	}
	for(i=0;i<count;i++)
	{
		memset(&p1[i],0,sizeof(struct AdvMyTea));
		//memset(p1+i,0,sizeof(struct AdvMyTea));
		p1[i].alice = (char *)malloc(128*sizeof(char ));
		memset(p1[i].alice,0,128*sizeof(char));
		//p1[i].studentname=(char **)malloc(254);
		{
			char **p=(char **)malloc(3*sizeof(char *));
			for(j=0;j<3;j++)
			{
				p[j] = (char *)malloc(sizeof(char) * 128);
				memset(p[j],0,sizeof(char)*128);
			}
			p1[i].studentname=p;
		}
	}
	return p1;
}
/************************************************************************/
/* 释放二级指针                                                                     */
/************************************************************************/
void free2p(char **p,int num){
	int i=0;
	int j=0;
	for(i=0;i<num;i++){
		if(p[i] != NULL){
			free(p[i]);
		}
	}
	free(p);
}
void  freeArray2(struct AdvMyTea* tArray,int count){
	int i;
	if(tArray == NULL)
	{
		return;
	}
	for(i=0;i<count;i++)
	{
		//释放别名
		char *p=tArray[i].alice;
		if(p != NULL){
			free(p);
		}
		//释放student的空间
		if(tArray[i].studentname != NULL){
			free2p(tArray[i].studentname,3);
		}

	}
	if(tArray != NULL)
	{
		free(tArray);
		tArray=NULL;//垃圾话语
	}
}


int main0777777(int arg,char* args[])
{
	struct AdvMyTea *tArray;
	int i;
	int j;
	tArray=createArray2(4);
	for(i=0;i<4;i++){
		int tmp=0;
		char *p=tArray[i].alice;
		printf("\n请输入age: ");
		scanf("%d",&tArray[i].age);
		printf("\n请输入name: ");
		scanf("%s",&tArray[i].name);
		printf("\n请输入alice: ");
		scanf("%s",p);
		for(j=0;j<3;j++){
			char **pp=tArray[i].studentname;
			printf("\n请输入student name: ");
			scanf("%s",pp[j]);
		}
	}
	printf("***********sort before***************\n");
	printArray2(tArray,4);
	sortArray2(tArray,4);
	printf("***********sort after ***************\n");
	printArray2(tArray,4);
	//释放内存
	freeArray2(tArray,4);
	tArray=NULL;
	system("pause");
}
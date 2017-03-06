#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct AdvMyTeacher{
	char name[64];//顺序不一样内存大小不一样,按照内存变量的大小存放的可能会多出几个字节
	char *alice;
	int age;
	int *pnum;
};
/************************************************************************/
/* 创建结构体                                                                     */
/************************************************************************/
struct AdvMyTeacher * createArray3(int count){
	int i=0;
	int j;
	struct AdvMyTeacher *p1=(struct AdvMyTeacher *)malloc(count*sizeof(struct AdvMyTeacher));
	if(p1 == NULL)
	{
		return NULL;
	}
	for(i=0;i<count;i++)
	{
		memset(&p1[i],0,sizeof(struct AdvMyTeacher));
		//memset(p1+i,0,sizeof(struct AdvMyTea));
		p1[i].alice = (char *)malloc(128*sizeof(char ));
		memset(p1[i].alice,0,128*sizeof(char));
		//处理int *
		p1[i].pnum=(int *)malloc(sizeof(int));//4个字节的int 型变量
		//p1[i].pnum=(int *)malloc(10 * sizeof(int));//int 型数组
	}
	return p1;
}
/************************************************************************/
/* 释放结构体                                                                     */
/************************************************************************/
void  freeArray3(struct AdvMyTeacher* tArray,int count){
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
	}
	if(tArray != NULL)
	{
		free(tArray);
		tArray=NULL;//垃圾话语
	}
}
int copy03(struct AdvMyTeacher *from,struct AdvMyTeacher *to){
	memcpy(to,from,sizeof(struct AdvMyTeacher));
	to->alice=(char *)malloc(128);
	strcpy(to->alice,from->alice);
	return 1;
}
/************************************************************************/
/* 结构体的copy行为                                                                     */
/************************************************************************/
int main0888889(int arg,char* args[]){
	//struct AdvMyTeacher t1;
	//struct AdvMyTeacher t2;
	struct AdvMyTeacher *p1=createArray3(1);
	struct AdvMyTeacher *p2=createArray3(1);
	int tmp=0;
	char *p=p1->alice;
	printf("\n请输入t1.age: ");
	scanf("%d",&(p1->age));
	printf("\n请输入t1.name: ");
	scanf("%s",p1->name);
	printf("\n请输入t1.alice: ");
	scanf("%s",p);
	//(*p2)=(*p1);//浅copy
	copy03(p1,p2);//深copy
	freeArray3(p1,1);
	freeArray3(p2,1);
	system("pause");
	return 1;
}

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct AdvMyTea{
	char name[64];//˳��һ���ڴ��С��һ��,�����ڴ�����Ĵ�С��ŵĿ��ܻ��������ֽ�
	char *alice;
	int age;
	char ** studentname;
};
/************************************************************************/
/* ��ӡ�ķ���                                                                     */
/************************************************************************/
void	printArray2(struct AdvMyTea *tarray,int count){
	int i;
	int j;
	for(i=0;i<4;i++){
		printf("%d  ",tarray[i].age);
		printf("%s  ",tarray[i].name);
		printf("%s ",tarray[i].alice);//û���ڴ�������ָ��
		for(j=0;j<3;j++){
			char **p2=tarray[i].studentname;
			printf("%s  ",p2[j]);
		}
		printf("\n");
	}
	printf("\n");
}
/************************************************************************/
/* ����ķ���                                                                     */
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
/* �ڶ��Ϸ����ڴ�                                                                     */
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
/* �ͷŶ���ָ��                                                                     */
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
		//�ͷű���
		char *p=tArray[i].alice;
		if(p != NULL){
			free(p);
		}
		//�ͷ�student�Ŀռ�
		if(tArray[i].studentname != NULL){
			free2p(tArray[i].studentname,3);
		}

	}
	if(tArray != NULL)
	{
		free(tArray);
		tArray=NULL;//��������
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
		printf("\n������age: ");
		scanf("%d",&tArray[i].age);
		printf("\n������name: ");
		scanf("%s",&tArray[i].name);
		printf("\n������alice: ");
		scanf("%s",p);
		for(j=0;j<3;j++){
			char **pp=tArray[i].studentname;
			printf("\n������student name: ");
			scanf("%s",pp[j]);
		}
	}
	printf("***********sort before***************\n");
	printArray2(tArray,4);
	sortArray2(tArray,4);
	printf("***********sort after ***************\n");
	printArray2(tArray,4);
	//�ͷ��ڴ�
	freeArray2(tArray,4);
	tArray=NULL;
	system("pause");
}
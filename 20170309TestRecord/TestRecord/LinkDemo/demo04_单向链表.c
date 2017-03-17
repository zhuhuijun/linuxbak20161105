#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct Node
{
	int data;
	struct Node *next;
}SLIST;
SLIST*  create_List();
int		SList_Print(SLIST *pHead);
//指定x前面位置插入y
int		SList_NodeInsert(SLIST *phead,int x,int y);
//删除值为y
int		SList_NodeDel(SLIST *pHead,int y);
//销毁链表
int		SList_Destory(SLIST *phead);
//链表逆序
int	SList_Reverse(SLIST *phead);
//创建链表
SLIST*  create_List(){
	int data = 0;
	//建立头结点并初始化
	SLIST *phead = NULL;
	SLIST *tmp = NULL;
	SLIST *pcur = NULL;
	phead = (SLIST *)malloc(sizeof(SLIST));
	if (phead == NULL)
	{
		return NULL;
	}
	phead->data = 0;
	phead->next = NULL;
	printf ("Please Input Node Data:( -1 means quit!)>>");
	scanf ("%d",&data);
	//准备环境
	pcur = phead;
	while(data != -1)
	{
		tmp =(SLIST *) malloc(sizeof(SLIST));
		if (tmp == NULL)
		{
			SList_Destory(phead);
			return NULL;
		}
		tmp->data = data;
		tmp->next = NULL;
		//新节点入联表
		pcur->next = tmp;
		//新节点变成当前节点
		pcur = tmp;

		printf ("Please Input Node Data:( -1 means quit!)>>");
		scanf ("%d",&data);
	}
	return phead;
}

//创建链表
int  create_List2(SLIST **ptmp){
	int ret = 0;
	int data = 0;
	//建立头结点并初始化
	SLIST *phead = NULL;
	SLIST *tmp = NULL;
	SLIST *pcur = NULL;
	phead = (SLIST *)malloc(sizeof(SLIST));
	if (phead == NULL)
	{
		ret = -1;
		return ret;;
	}
	phead->data = 0;
	phead->next = NULL;
	printf ("Please Input Node Data:( -1 means quit!)>>");
	scanf ("%d",&data);
	//准备环境
	pcur = phead;
	while(data != -1)
	{
		tmp =(SLIST *) malloc(sizeof(SLIST));
		if (tmp == NULL)
		{
			SList_Destory(phead);
			ret = -2;
			return ret;
		}
		tmp->data = data;
		tmp->next = NULL;
		//新节点入联表
		pcur->next = tmp;
		//新节点变成当前节点
		pcur = tmp;

		printf ("Please Input Node Data:( -1 means quit!)>>");
		scanf ("%d",&data);
	}
	*ptmp  =  phead;
	return ret;
}
//打印链表
int	SList_Print(SLIST *pHead)
{
	int ret = 0;
	SLIST *pcur = NULL;
	if (pHead  == NULL)
	{
		ret = -1;
		return ret;
	}
	pcur = pHead->next;
	while(pcur){
		printf("data>>>:%d\n",pcur->data);
		pcur = pcur->next;
	};
	return ret;
}
//销毁链表
int		SList_Destory(SLIST *phead)
{
	int ret = 0;
	SLIST *pcur = NULL;
	SLIST *ptemp = NULL;
	if (phead == NULL)
	{
		ret = -1;
		return ret;
	}
	pcur = phead;
	while (pcur){
		ptemp = pcur->next;
		free(pcur);
		pcur = ptemp;
	}
	return ret ;
}
int		SList_NodeInsert(SLIST *phead,int x,int y)
{
	int ret = 0;
	SLIST *pcur = NULL;
	SLIST *ppre = NULL;
	SLIST *pnew = NULL;
	if (phead == NULL)
	{
		ret = -1;
		return -1;
	}
	ppre = NULL;
	pcur = phead;
	while (pcur){
		if (pcur->data ==x)
		{
			break;
		}
		//同时下移
		ppre = pcur;
		pcur = pcur->next;
	}
	//继续挂载
	pnew =(SLIST *) malloc(sizeof(SLIST));
	pnew->data = y;
	//让前驱节点指向pnew
	pnew->next = ppre->next;
	ppre->next = pnew;

	return ret ;
}
//链表逆序
int	SList_Reverse(SLIST *phead){
	int ret = 0;
	SLIST *p = NULL, *q = NULL, *t = NULL;
	//准备环境
	if (phead == NULL)
	{
		ret = -1;
		return ret;
	}
	if (phead->next == NULL || phead->next ->next == NULL)
	{
		return ret;
	}
	while ( q != NULL)
	{
		//做一个缓存
		t = q->next;
		//开始逆置
		q->next = p;
		//让 p q 分别后移
		p = q;
		q = t;
	}
	phead->next->next = NULL;
	phead->next = p;
	return ret ; 
}
int main40000(int argc,char* argv[])
{
	SLIST *phead = NULL;
	phead = create_List();
	SList_Print(phead);
	SList_NodeInsert(phead,100,19);
	SList_Print(phead);
	SList_Destory(phead);
	printf("%s\n","hello,world!");
	system("pause");
	return 1;
}
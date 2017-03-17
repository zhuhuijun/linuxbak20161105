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
//ָ��xǰ��λ�ò���y
int		SList_NodeInsert(SLIST *phead,int x,int y);
//ɾ��ֵΪy
int		SList_NodeDel(SLIST *pHead,int y);
//��������
int		SList_Destory(SLIST *phead);
//��������
int	SList_Reverse(SLIST *phead);
//��������
SLIST*  create_List(){
	int data = 0;
	//����ͷ��㲢��ʼ��
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
	//׼������
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
		//�½ڵ�������
		pcur->next = tmp;
		//�½ڵ��ɵ�ǰ�ڵ�
		pcur = tmp;

		printf ("Please Input Node Data:( -1 means quit!)>>");
		scanf ("%d",&data);
	}
	return phead;
}

//��������
int  create_List2(SLIST **ptmp){
	int ret = 0;
	int data = 0;
	//����ͷ��㲢��ʼ��
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
	//׼������
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
		//�½ڵ�������
		pcur->next = tmp;
		//�½ڵ��ɵ�ǰ�ڵ�
		pcur = tmp;

		printf ("Please Input Node Data:( -1 means quit!)>>");
		scanf ("%d",&data);
	}
	*ptmp  =  phead;
	return ret;
}
//��ӡ����
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
//��������
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
		//ͬʱ����
		ppre = pcur;
		pcur = pcur->next;
	}
	//��������
	pnew =(SLIST *) malloc(sizeof(SLIST));
	pnew->data = y;
	//��ǰ���ڵ�ָ��pnew
	pnew->next = ppre->next;
	ppre->next = pnew;

	return ret ;
}
//��������
int	SList_Reverse(SLIST *phead){
	int ret = 0;
	SLIST *p = NULL, *q = NULL, *t = NULL;
	//׼������
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
		//��һ������
		t = q->next;
		//��ʼ����
		q->next = p;
		//�� p q �ֱ����
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
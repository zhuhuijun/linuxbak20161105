
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "linkstack.h"
#include "linklist.h"

typedef struct _Teacher
{
	LinkListNode nodeddddddddd;
	void *item;
}Teacher;

typedef struct _tag_linkStackNode
{
	LinkListNode node;
	void *item;
}TlinkStackNode;


LinkStack* LinkStack_Create()
{
	return LinkList_Create();;
}

void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
	return ;
}
//��Ҫ�Ѳ���Ľڵ�ȫ��free��
void LinkStack_Clear(LinkStack* stack)
{
	if(stack==NULL){
		return;
	}
	while(LinkStack_Size(stack)>0){
		LinkStack_Pop(stack);
	}
	return;
}

//��stack��push���ݣ��൱����linklist�в�������
int LinkStack_Push(LinkStack* stack, void* item)
{
	int ret = 0;
	TlinkStackNode *t1 =(TlinkStackNode *) malloc(sizeof(TlinkStackNode));
	t1->item = item;
	ret = LinkList_Insert(stack, (LinkListNode*)t1, 0);
	if (ret != 0)
	{
		free(t1); //ע���ڴ�й¶
	}
	return ret;
}

void* LinkStack_Pop(LinkStack* stack)
{	
	void *myItem = NULL;
	TlinkStackNode *node = NULL;
	if (stack == NULL)
	{
		return NULL;
	}

	node = (TlinkStackNode *)LinkList_Delete(stack, 0);
	if (node == NULL)
	{
		return NULL;
	}
	myItem = node->item;
	free(node); //ע���ͷ��ڴ治Ҫ����
	return myItem;
}
//���ջ��Ԫ�ص��ǲ�ɾ��
void* LinkStack_Top(LinkStack* stack)
{
	TlinkStackNode *node=NULL;
	if(stack==NULL){
		return NULL;
	}
	node=(TlinkStackNode*)LinkList_Get(stack,0);
	return node->item;
}

int LinkStack_Size(LinkStack* stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	return LinkList_Length(stack);
}

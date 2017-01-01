#include "stdio.h"
#include "malloc.h"
#include "dlinklist.h"
typedef struct _tag_DLinkList{
	DLinkListNode header;
	DLinkListNode *slider;
	int length;
}TDLinkList;
DLinklist* DLinkList_Create()
{
	TDLinkList* ret=(TDLinkList*)malloc(sizeof(TDLinkList));
	if(ret!=NULL){
		ret->length=0;
		ret->header.next=NULL;
		ret->header.pre=NULL;
		ret->slider=NULL;
	}
	return ret;
}
void DLinkList_Destroy(DLinklist* list)
{
	if(list!=NULL){
		free(list);
	}
}

void DLinkList_Clear(DLinklist* list){
	TDLinkList* sList=(TDLinkList*)list;
	if(sList!=NULL)
	{
		sList->length=0;
		sList->header.next=NULL;
		sList->header.pre=NULL;
		sList->slider=NULL;
	}
}

int DLinkList_Length(DLinklist* list){
	TDLinkList* sList=(TDLinkList*)list;
	int ret=-1;
	if(sList!=NULL){
		ret=sList->length;
	}
	return ret;
}

int DLinkList_Insert(DLinklist* list, DLinkListNode* node, int pos){
	int ret=0,i=0;
	TDLinkList* sList=(TDLinkList*)list;
	if(list==NULL||node==NULL||pos<0){
		return -1;
	}
	{
		DLinkListNode* current=(DLinkListNode*)sList;
		DLinkListNode* next=NULL;//需要增加next指针
		for (i=0;i<pos;i++)
		{
			current=current->next;
		}
		next=current->next;
		//步骤1-2
		current->next=node;
		node->next=next;
		//步骤3-4
		if(next!=NULL){
			next->pre=node;
		}
		node->pre=current;
		if(sList->length==0){
			sList->slider=node;//当链表茶如第一个元素处理游标
		}
		sList->length++;
	}
	return ret;
}

DLinkListNode* DLinkList_Get(DLinklist* list, int pos){
	return NULL;
}

DLinkListNode* DLinkList_Delete(DLinklist* list, int pos){
	return NULL;
}

//add

DLinkListNode* DLinkList_DeleteNode(DLinklist* list, DLinkListNode* node){
	return NULL;
}

DLinkListNode* DLinkList_Reset(DLinklist* list){
	return NULL;
}

DLinkListNode* DLinkList_Current(DLinklist* list){
	return NULL;
}

DLinkListNode* DLinkList_Next(DLinklist* list){
	return NULL;
}
DLinkListNode* DLinkList_Pre(DLinklist* list){
	return NULL;
}
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
		if(next!=NULL){//当链表插入第一个元素
			next->pre=node;
		}
		node->pre=current;
		if(sList->length==0){
			sList->slider=node;//当链表茶如第一个元素处理游标
		}
		//若在0位置插入需要特殊处理新来节点的next前pre指向null
		if(current==(DLinkListNode*)sList)
		{
			node->pre=NULL;
		}
		sList->length++;
	}
	return ret;
}

DLinkListNode* DLinkList_Get(DLinklist* list, int pos){
	TDLinkList* sList=(TDLinkList*) list;
	DLinkListNode* ret=NULL;
	int i=0;
	if((sList !=NULL)&&(0<=pos)&&(pos<sList->length))
	{
		DLinkListNode* current=(DLinkListNode*) sList;
		for(i=0;i<pos;i++){
			current=current->next;
		}
		ret=current->next;
	}
	return ret;
}

DLinkListNode* DLinkList_Delete(DLinklist* list, int pos){
	TDLinkList* sList=(TDLinkList*) list;
	DLinkListNode* ret=NULL;
	int i=0;
	if(sList==NULL||pos<0){
		return NULL;
	}
	{
		DLinkListNode* current=(DLinkListNode*)sList;
		DLinkListNode* next=NULL;
		for(i=0;i<pos,i++){
			current=current->next;
		}
		ret=current->next;
		next=ret->next;
		//步骤一
		current->next=next;
		//步骤二
		if(next!=NULL){//需要特殊处理
			next->pre=current;
			if(current==(DLinkListNode*)sList){//若第0个位置需要特殊处理
				next->pre=NULL;
			}
		}
		if(sList->slider==ret){
			sList->slider=next;
		}
		sList->length--;
	}
	return ret;
}

//add

DLinkListNode* DLinkList_DeleteNode(DLinklist* list, DLinkListNode* node){
	TDLinkList* sList=(TDLinkList*)list;
	DLinkListNode* ret=NULL;
	int i=0;
	if(sList!=NULL){
		DLinkListNode* current=(DLinkListNode*)sList;
		for(i=0;i<sList->length;i++){
			if(current->next==node){
				ret=current->next;
				break;
			}
			current=current->next;
		}
		if(ret!=NULL){
			DLinkList_Delete(sList,i);
		}
	}
	return ret;
}
//重置游标
DLinkListNode* DLinkList_Reset(DLinklist* list){
	TDLinkList* sList=(TDLinkList*)list;
	DLinkListNode* ret=NULL;
	if(sList!=NULL){
		sList->slider=sList->header.next;
		ret=sList->slider;
	}
	return ret;
}

DLinkListNode* DLinkList_Current(DLinklist* list){
	TDLinkList* sList=(TDLinkList*)list;
	DLinkListNode* ret=NULL;
	if(sList!=NULL){
		ret=sList->slider;
	}
	return ret;
}

DLinkListNode* DLinkList_Next(DLinklist* list){
	TDLinkList* sList=(TDLinkList*)list;
	DLinkListNode* ret=NULL;
	if((sList!=NULL)&&(sList->slider!=NULL)){
		ret=sList->slider;
		sList->slider=ret->next;
	}
	return ret;
}
DLinkListNode* DLinkList_Pre(DLinklist* list){
	TDLinkList* sList=(TDLinkList*)list;
	DLinkListNode* ret=NULL;
	if((sList!=NULL)&&(sList->slider!=NULL)){
		ret=sList->slider;
		sList->slider=ret->pre;
	}
	return ret;
}
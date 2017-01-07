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
		DLinkListNode* next=NULL;//��Ҫ����nextָ��
		for (i=0;i<pos;i++)
		{
			current=current->next;
		}
		next=current->next;
		//����1-2
		current->next=node;
		node->next=next;
		//����3-4
		if(next!=NULL){//����������һ��Ԫ��
			next->pre=node;
		}
		node->pre=current;
		if(sList->length==0){
			sList->slider=node;//����������һ��Ԫ�ش����α�
		}
		//����0λ�ò�����Ҫ���⴦�������ڵ��nextǰpreָ��null
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
		for(i=0;i<pos;i++){
			current=current->next;
		}
		ret=current->next;
		next=ret->next;
		//����һ
		current->next=next;
		//�����
		if(next!=NULL){//��Ҫ���⴦��
			next->pre=current;
			if(current==(DLinkListNode*)sList){//����0��λ����Ҫ���⴦��
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
//�����α�
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
#ifndef _MY_DLINKLIST_H_   
#define _MY_DLINKLIST_H_
typedef void DLinklist;
typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode* next;
	struct _tag_DLinkListNode* pre;

}DLinkListNode;

DLinklist* DLinkList_Create();

void DLinkList_Destroy(DLinklist* list);

void DLinkList_Clear(DLinklist* list);

int DLinkList_Length(DLinklist* list);

int DLinkList_Insert(DLinklist* list, DLinkListNode* node, int pos);

DLinkListNode* DLinkList_Get(DLinklist* list, int pos);

DLinkListNode* DLinkList_Delete(DLinklist* list, int pos);

//add

DLinkListNode* DLinkList_DeleteNode(DLinklist* list, DLinkListNode* node);

DLinkListNode* DLinkList_Reset(DLinklist* list);

DLinkListNode* DLinkList_Current(DLinklist* list);

DLinkListNode* DLinkList_Next(DLinklist* list);
DLinkListNode* DLinkList_Pre(DLinklist* list);
#endif //_MY_DLINKLIST_H_
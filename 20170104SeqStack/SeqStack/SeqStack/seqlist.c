#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "seqlist.h"

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	unsigned int *node ; // unsigned int nodeAarry[100]
	//void *node ;
}TSeqList;

//typdef����˼ ��void ����������SeqList

/*
void * SeqList_Create2(int capacity)
{
	TSeqList *ret = NULL;
	ret = (TSeqList *)malloc(sizeof(TSeqList));
	if (ret == NULL)
	{
		return NULL;
	}
	ret->capacity = capacity;
	ret->node = (unsigned int *)malloc(sizeof(unsigned int ) * capacity);
	if (ret->node == NULL)
	{
		return NULL;
	}
	ret->length = 0;
	return ret;
}
*/

void * SeqList_Create(int capacity)
{
	TSeqList *ret = NULL;

	if (capacity <= 0)
	{
		return NULL;
	}
	ret = (TSeqList *)malloc(sizeof(TSeqList) + sizeof(unsigned int ) * capacity );
	if (ret == NULL)
	{
		return NULL;
	}
	ret->capacity = capacity;
	ret->node = (unsigned int *)(ret + 1);
	
	ret->length = 0;
	return ret;
}

void SeqList_Destroy(SeqList* list)
{
	if (list == NULL)
	{
		return ;
	}
	free(list);
	return ;
}

void SeqList_Clear(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return ;
	}
	tlist = (TSeqList *)list;

	tlist->length = 0;
	return ;
}

int SeqList_Length(SeqList* list)
{
	TSeqList *tlist = list;
	if (list == NULL)
	{
		return -1;
	}
	return tlist->length;
}

int SeqList_Capacity(SeqList* list)
{
	TSeqList *tlist = list;
	if (list == NULL)
	{
		return -1;
	}
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int i = 0;
	TSeqList *tlist = (TSeqList *) list;

	if (list == NULL || node== NULL )
	{
		return -1;
	}

	if (pos<0 || pos>=tlist->capacity )
	{
		return -2;
	}

	//�ж��Ƿ��Ѿ�man
	if (tlist->length >= tlist->capacity)
	{
		return -3;
	}

	//�ݴ�
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}
	
	//�����㷨 ������
	//�Ӳ����λ�� ����Ԫ�� 
	//ע��length�ܱ�ʾ��������������Ԫ��λ��
	//���Ԫ�ص��±�Ϊ tlist->node[length-1];
	for (i=tlist->length; i>pos; i--)
	{
		tlist->node[i] = tlist->node[i-1];
	}
	//��posλ�ò���Ԫ��
	tlist->node[pos] = (unsigned int)node; //20140514����ط����ܼ� (unsigned int *)
	//������*��˵�����	unsigned int *node ; // unsigned int nodeAarry[100]��û����� 
	tlist->length ++;

	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int i = 0;
	TSeqList *tlist =(TSeqList *)  list;
	//if (list== NULL || pos<0 || pos>=tlist->length)
	if (list== NULL || pos<0 || pos>tlist->length)
	{
		return NULL;
	}
	return (SeqListNode*)tlist->node[pos];
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int i = 0;
	TSeqList *tlist =(TSeqList *) list;
	SeqListNode* ret = NULL;
	if (list == NULL || pos<0 || pos>tlist->length)
	{
		return NULL;
	}
	//����Ҫɾ���Ľ��
	ret = (SeqListNode*)tlist->node[pos];
	//����������ƶ�
	for (i=pos+1; i<tlist->length; i++)
	{
		tlist->node[i-1] = tlist->node[i];
 	}
	tlist->length --;
	return ret;
}

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "dlinklist.h"
//////////////////////////////////////////////////////////////////////////
//˫�������ѧϰ
struct Value{
	DLinkListNode header;
	int v;
};
void main(int argc,char argv[])
{

	int i=0;
	DLinklist* list=DLinkList_Create();
	struct Value* pv=NULL;
	struct Value v1,v2,v3,v4,v5;
	v1.v=1;
	v2.v=2;
	v3.v=3;
	v4.v=4;
	v5.v=5;
	DLinkList_Insert(list,(DLinkListNode*)&v1,DLinkList_Length(list));
	DLinkList_Insert(list,(DLinkListNode*)&v2,DLinkList_Length(list));
    DLinkList_Insert(list,(DLinkListNode*)&v3,DLinkList_Length(list));
	DLinkList_Insert(list,(DLinkListNode*)&v4,DLinkList_Length(list));
	DLinkList_Insert(list,(DLinkListNode*)&v5,DLinkList_Length(list));
	for (i=0;i<DLinkList_Length(list);i++)
	{
		pv=(struct Value*)DLinkList_Get(list,i);
		printf("pv=%d\n",pv->v);
	}
	printf("\n");
	DLinkList_Delete(list,DLinkList_Length(list)-1);
	DLinkList_Delete(list,0);
	//DLinkList_Delete(list,3);
	for (i=0;i<DLinkList_Length(list);i++)
	{
		pv=(struct Value*)DLinkList_Next(list);
		printf("pv=%d\n",pv->v);
	}
	DLinkList_Reset(list);
	DLinkList_Next(list);
	pv=(struct Value*)DLinkList_Current(list);
	printf("current pv=%d\n",pv->v);
	printf("\n");
	DLinkList_DeleteNode(list,(DLinkListNode*)pv);
	pv=(struct Value*)DLinkList_Current(list);
	printf("delete after current pv=%d\n",pv->v);
	DLinkList_Pre(list);
	pv=(struct Value*)DLinkList_Current(list);
	printf("current pv=%d\n",pv->v);
	printf("Length:%d\n",DLinkList_Length(list));
	printf("hello,world!\n");
	system("pause");
}
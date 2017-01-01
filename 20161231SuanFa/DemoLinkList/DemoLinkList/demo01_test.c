#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "linklist.h"
typedef struct _Teacher
{
	LinkListNode *node;
	char name[64];
	int age;
} Teacher;
void main(int argc,char *argv[])
{
	LinkList *list=NULL;
	int ret=0,i=0;
	Teacher t1,t2,t3,t4,t5;
	t1.age=10;
	t2.age=20;
	t3.age=30;
	list=LinkList_Create();
	ret=LinkList_Length(list);
	printf("linklist of length:%d",ret);
	ret=LinkList_Insert(list,(LinkListNode *)(&t1),LinkList_Length(list));
	ret=LinkList_Insert(list,(LinkListNode *)(&t2),LinkList_Length(list));
	ret=LinkList_Insert(list,(LinkListNode *)(&t3),LinkList_Length(list));
	ret=LinkList_Insert(list,(LinkListNode *)(&t4),LinkList_Length(list));
	ret=LinkList_Insert(list,(LinkListNode *)(&t5),LinkList_Length(list));

	for ( i=0;i<LinkList_Length(list);i++)
	{
		Teacher *tmp=(Teacher *)LinkList_Get(list,i);
		if(tmp!=NULL)
		{
			printf("curr==%d",tmp->age);
		}
	}

	LinkList_Destroy(list);
	printf("hello,world!\n");
	system("psuse");
}

















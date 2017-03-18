#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Mylinklist.h"

typedef struct _Teacher
{
	LinkListNode *node;
	char name[64];
	int age;
}Teacher;

int main(int argc,char* argv[])
{
	int len = 0;
	Teacher t1,t2,t3,t4,t5;
	LinkList* list = NULL;
	t1.age = 10;
	t2.age = 20;
	t3.age = 30;
	t4.age = 40;
	t5.age = 50;
	list = LinkList_Create();
	len = LinkList_Length(list);
	LinkList_Insert(list,(LinkListNode *)&t1,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode *)&t2,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode *)&t3,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode *)&t4,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode *)&t5,LinkList_Length(list));
	printf("linklist_len:%d\n",LinkList_Length(list));
	while(LinkList_Length(list) > 0)
	{
		Teacher* tmp = (Teacher *)LinkList_Delete(list,0);
		if (tmp != NULL)
		{
			printf("tmp->age:%d\n",tmp->age);
		}
	}
	LinkList_Destroy(list);
	printf("%s\n","hello,world!");
	system("pause");
	return 1;
}
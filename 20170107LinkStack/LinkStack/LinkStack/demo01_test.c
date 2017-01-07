#include "stdlib.h"
#include "stdio.h"
#include "linkstack.h"
//////////////////////////////////////////////////////////////////////////
//链表栈的实现
void main(int argc,char* argv[])
{
	int i=0,a[10];
	int ret=0,tmp=0;
	LinkStack*  stack;
	stack=LinkStack_Create();
	for (i=0;i<10;i++)
	{
		a[i]=i+1;
		ret = LinkStack_Push(stack,(void *)&a[i]);
	}
	tmp = *((int*)LinkStack_Top(stack));
	printf("stack header value:\d",tmp);
	printf("stack length value:%d\n",LinkStack_Size(stack));
	while(LinkStack_Size(stack)>0){
		tmp = *((int*)LinkStack_Pop(stack));
		printf("stack pop value:%d\n",tmp);
	}
	//销毁栈
	LinkStack_Destroy(stack);
	printf("hello,world!\n");
	system("pause");
}
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "seqstack.h"
/************************************************************************/
/* 线性栈的实现                                                                     */
/************************************************************************/
void main(int argc,char *argv[])
{
	int i=0,tmp;
	int a[10];
	SeqStack* stack=NULL;
	stack=SeqStack_Create(10);
	for (i=0;i<10;i++)
	{
		a[i]=i+1;
		SeqStack_Push(stack,(void*)&a[i]);
		//SeqStack_Push(stack,(void*)(a+i));
	}
	tmp = *((int *)SeqStack_Top(stack));
	printf("stack top=%d\n",tmp);
	printf("stack length=%d\n",SeqStack_Size(stack));
	printf("stack capacity=%d\n",SeqStack_Capacity(stack));
	while(SeqStack_Size(stack)>0){
			tmp = *((int *)SeqStack_Pop(stack));
			printf("pop value:%d\n",tmp);
	}
	SeqStack_Destory(stack);
	printf("hello,world\n");
	system("pause");
}
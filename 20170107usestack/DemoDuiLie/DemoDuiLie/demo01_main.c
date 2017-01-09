#include"stdlib.h"
#include "stdio.h"
#include "seqqueue.h"
void main(int argc,char* argv[])
{
	int i=0,a[10],tmp;
	SeqQueue* queue=NULL;
	queue=SeqQueue_Create(10);
	for (i=0;i<5;i++)
	{
		a[i]=i+1;
		SeqQueue_Append(queue,(void*)&a[i]);
		//SeqQueue_Append(queue,(void*)(a+i));
	}
	tmp=*((int*)SeqQueue_Header(queue));
	printf("队列头元素的值:%d\n",tmp);
	printf("队列的长度:%d\n",SeqQueue_Length(queue));
	printf("队列的容量值:%d\n",SeqQueue_Capacity(queue));
	printf("=============队列的值====================\n");
	while(SeqQueue_Length(queue)>0){
		tmp=*((int*)SeqQueue_Retrieve(queue));
		printf("队列的值:%d\n",tmp);
	}
	printf("=============队列的值====================\n");
	//销毁
	SeqQueue_Destroy(queue);
	printf("hello,world\n");
	system("pause");
}
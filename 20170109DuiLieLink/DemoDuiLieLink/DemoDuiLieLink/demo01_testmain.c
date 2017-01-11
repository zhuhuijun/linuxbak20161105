#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "linkqueue.h"
//////////////////////////////////////////////////////////////////////////
//队列的链式存储
void main(int argc,char* argv[]){
	LinkQueue* queue=NULL;
	int i=0,aa[10],tmp;
	//创建队列
	queue = LinkQueue_Create();

	for(i=0;i<10;i++){
		aa[i]=i+1;
		LinkQueue_Append(queue,(void*)&aa[i]);
	}
	tmp=*((int*)LinkQueue_Header(queue));
	printf("队列的头部元素:%d\n",tmp);
	printf("队列的长度值：%d\n",LinkQueue_Length(queue));
	printf("=================队列的元素============\n");
	while(LinkQueue_Length(queue)>0){
		tmp=*((int*)LinkQueue_Retrieve(queue));
		printf("元素的值:%d\n",tmp);
	}
	printf("=================队列的元素============\n");
	//销毁队列
	LinkQueue_Destroy(queue);
	printf("hello,world!\n");
	system("pause");
}
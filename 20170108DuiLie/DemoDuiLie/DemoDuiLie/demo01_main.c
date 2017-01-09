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
	printf("����ͷԪ�ص�ֵ:%d\n",tmp);
	printf("���еĳ���:%d\n",SeqQueue_Length(queue));
	printf("���е�����ֵ:%d\n",SeqQueue_Capacity(queue));
	printf("=============���е�ֵ====================\n");
	while(SeqQueue_Length(queue)>0){
		tmp=*((int*)SeqQueue_Retrieve(queue));
		printf("���е�ֵ:%d\n",tmp);
	}
	printf("=============���е�ֵ====================\n");
	//����
	SeqQueue_Destroy(queue);
	printf("hello,world\n");
	system("pause");
}
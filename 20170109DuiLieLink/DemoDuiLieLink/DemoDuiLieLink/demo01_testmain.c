#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "linkqueue.h"
//////////////////////////////////////////////////////////////////////////
//���е���ʽ�洢
void main(int argc,char* argv[]){
	LinkQueue* queue=NULL;
	int i=0,aa[10],tmp;
	//��������
	queue = LinkQueue_Create();

	for(i=0;i<10;i++){
		aa[i]=i+1;
		LinkQueue_Append(queue,(void*)&aa[i]);
	}
	tmp=*((int*)LinkQueue_Header(queue));
	printf("���е�ͷ��Ԫ��:%d\n",tmp);
	printf("���еĳ���ֵ��%d\n",LinkQueue_Length(queue));
	printf("=================���е�Ԫ��============\n");
	while(LinkQueue_Length(queue)>0){
		tmp=*((int*)LinkQueue_Retrieve(queue));
		printf("Ԫ�ص�ֵ:%d\n",tmp);
	}
	printf("=================���е�Ԫ��============\n");
	//���ٶ���
	LinkQueue_Destroy(queue);
	printf("hello,world!\n");
	system("pause");
}
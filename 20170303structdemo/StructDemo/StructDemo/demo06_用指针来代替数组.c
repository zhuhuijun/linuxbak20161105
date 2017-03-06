#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct MyTeaBak{
	char name[64];//˳��һ���ڴ��С��һ��,�����ڴ�����Ĵ�С��ŵĿ��ܻ��������ֽ�
	int age;
};
/************************************************************************/
/* ��ӡ�ķ���                                                                     */
/************************************************************************/
void	printArray1(struct MyTeaBak *tarray,int count){
	int i;
	for(i=0;i<4;i++){
		printf("%d  ",tarray[i].age);
	}
	printf("\n");
}
/************************************************************************/
/* ����ķ���                                                                     */
/************************************************************************/
void	sortArray1(struct MyTeaBak *tarray,int count){
	int i;
	int j;
	struct MyTeaBak tmp;
	for(i=0;i<4;i++){
		for(j=i;j<count;j++){
			if(tarray[i].age>tarray[j].age){
				tmp = tarray[i];
				tarray[i]=tarray[j];
				tarray[j]=tmp;
			}
		}
	}
}
/************************************************************************/
/* �ڶ��Ϸ����ڴ�                                                                     */
/************************************************************************/
struct MyTeaBak * createArray(int count){
	int i=0;
	struct MyTeaBak *p1=(struct MyTeaBak *)malloc(count*sizeof(struct MyTeaBak));
	if(p1 == NULL)
	{
		return NULL;
	}
	for(i=0;i<count;i++)
	{
		memset(&p1[i],0,sizeof(struct MyTeaBak));
		//memset(p1+i,0,sizeof(struct MyTeaBak));
	}
	return p1;
}


void  freeArray(struct MyTeaBak* tArray){
	if(tArray != NULL)
	{
		free(tArray);
		tArray=NULL;//��������
	}
}


int main66666666(int argc,char * args[]){
	struct MyTeaBak *tArray;
	int i;
	tArray=createArray(4);
	for(i=0;i<4;i++){
		int tmp=0;
		printf("\n������age: ");
		scanf("%d",&tArray[i].age);
	}
	printf("***********sort before***************\n");
	printArray1(tArray,4);
	sortArray1(tArray,4);
	printf("***********sort after ***************\n");
	printArray1(tArray,4);
	//�ͷ��ڴ�
	freeArray(tArray);
	tArray=NULL;
	system("pause");
}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct TeaBak{
	char name[64];//˳��һ���ڴ��С��һ��,�����ڴ�����Ĵ�С��ŵĿ��ܻ��������ֽ�
	int age;
};
void teaArr_create(struct TeaBak ** p,int count){
	int i;
	struct TeaBak  *p1=(struct TeaBak *)(count*(sizeof(struct TeaBak)));
	if(p1==NULL) return;
	for(i=0;i<count;i++){
		memset(&p1[i],0,sizeof(struct TeaBak));
		//memset(p1+i,0,sizeof(struct TeaBak));
		p1[i].age=i;
	}
	*p=p1;
}
int main033333(int arg,char* args[])
{
	struct  TeaBak teaArr[10];
	struct TeaBak * pa=NULL;
	teaArr[0].age=10;
	//teaArr_create(&pa,2);
	//printf("pa[0].age:%d\n",pa[0].age);
	system("pause");
}
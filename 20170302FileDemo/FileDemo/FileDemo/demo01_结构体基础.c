#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/************************************************************************/
/* �ṹ��Ļ���֪ʶ
*1.�Լ�����һ���������ͣ����������ǹ̶���С�ڴ��ı���
*2.�ṹ�����Ͷ��������ʱ��,c��c++�������Ĵ����ǲ�һ����
*3.�ṹ������typedef 
*4.�ṹ�����4�ֽ��ڴ�������/
/************************************************************************/
typedef struct TeacherBak{
	char name[64];//64
	int age;//4
	char c1;//4
	char c2;//4
} TeacherBak;
//�ṹ�嶨�������3�ַ���
struct Teacher{
	char name[64];
	int age;
}t2={"ddd",5},t3={"rrr",6};

struct {
	char name[64];
	int age;//4
}t4={"ddd",5};
int main01sdfsff(int arg,char *args[]){
	struct Teacher t1={"fffff",6};
	struct Teacher *p=NULL;
	p=&t1;
	printf("sizeof(t1):%d\n",sizeof(t1));
	printf("p->name:%s\n",p->name);
	system("pause");
	return 1;
}
int main(int arg,char *args[]){
	struct Teacher t1={"fffff",6};
	struct Teacher t2={"ddddd",23};
	struct Teacher *p=NULL;
	t2=t1;//�����=�Ų������ǳ�ʼ��//ǳ��copy,�����ָ��Ļ�ֻ��copy��ַ,�����¿��ٿռ�
	//�ͷ�����ʱ��down��

	p=&t1;
	printf("sizeof(t1):%d\n",sizeof(t1));
	printf("p->name:%s\n",p->name);
	system("pause");
	return 1;
}
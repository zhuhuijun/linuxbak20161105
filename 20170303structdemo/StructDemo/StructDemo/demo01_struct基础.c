#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//�Զ���һ����������  �������͵ı����ǹ̶���С�ڴ��ı���
//c++��c �ṹ���ڶ���ṹ�����͵ı���ʱ���������Ĵ����ǲ�һ����

struct Teacher{
	char name[64];//˳��һ���ڴ��С��һ��,�����ڴ�����Ĵ�С��ŵĿ��ܻ��������ֽ�
	int age;
	char title[128];
};


typedef struct Teacher1{
	char name[64];
	int age;
	char title[128];
} Teacher1;
//��������ļ��ַ�ʽ����������ֿ�������
struct Tea
{
	char name[64];
	int age;
} t2={"t2",34},t3={"t3",56};

struct{
	char name[64];
	int age;
} t4={"t4",22};
int main0101001010(int argc,char* args[]){
	struct Teacher t1={"zhuhj",34};//���߱����������ڴ�
	Teacher1 t2;
	struct Teacher *p2=NULL;
	p2=&t1;
	printf("name:%s\n",p2->name);
	printf("sizeof(t2):%d\n",sizeof(t2));
	system("pause");
}
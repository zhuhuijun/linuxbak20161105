#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//�������
struct Student{
	char name[64];
	int age;
	char *p;
}Student;
//�ڶ������ݽṹ�����ݽṹ�ǹ̶��ڴ���С�ı���������c������Ҫ��������ڴ�
struct Teacher{
	char name[64];
	int age;
	char *p;
	struct Student s1;
	struct Student *ps2;//ֻ�Ǳ���û�пռ�
	//,�ṹ�����ָ�� 4���ֽ�
	struct Teacher *pT;//���������Ϊֻ�Ǹ�ָ�����4���ֽ�
	//struct Teacher t2;
};
int main1000(int argc,char* argv[])
{
	//�ṹ���������ýṹ��
	struct Teacher t1;
	struct Student s2;
	t1.age=100;
	t1.s1.age=10;
	//t1.ps2->age=10; //û���ڴ�����ָ��
	t1.ps2 = &s2;
	t1.ps2->age=20;
	system("pause");
	return 1;
}
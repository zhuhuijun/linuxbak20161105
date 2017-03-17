#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//链表基础
struct Student{
	char name[64];
	int age;
	char *p;
}Student;
//在定义数据结构，数据结构是固定内存块大小的别名，告诉c编译器要分配多少内存
struct Teacher{
	char name[64];
	int age;
	char *p;
	struct Student s1;
	struct Student *ps2;//只是变量没有空间
	//,结构体变量指针 4个字节
	struct Teacher *pT;//这个可以因为只是个指针变量4个字节
	//struct Teacher t2;
};
int main1000(int argc,char* argv[])
{
	//结构体里面套用结构体
	struct Teacher t1;
	struct Student s2;
	t1.age=100;
	t1.s1.age=10;
	//t1.ps2->age=10; //没有内存那有指针
	t1.ps2 = &s2;
	t1.ps2->age=20;
	system("pause");
	return 1;
}
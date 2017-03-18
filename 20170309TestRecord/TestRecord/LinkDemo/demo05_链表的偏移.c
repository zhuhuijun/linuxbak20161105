#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//链表保函各种业务数据但是做不到
typedef struct linkList1{
	struct linkList1 *next;
	int age;
	char name[64];//业务数据
} linkList1;

typedef struct AdvLinkList1{
	struct linkList1 *next;
} AdvLinkList1;

//业务数据包含链表
struct AdvTeacher1{
	char name[32];
	int age;
	char *p;
	AdvLinkList1 *node;
};
int main(int argc,char* argv[])
{
	struct linkList1 t1;
	printf("&(t1.age):%d,t1:%d\n)",&(t1.age),&t1);
	printf("%s\n","hello,world!");
	system("pause");
    return 1;
}
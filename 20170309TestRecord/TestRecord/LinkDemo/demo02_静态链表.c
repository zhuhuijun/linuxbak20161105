#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct AdvTeacher
{
	char name[64];
	int age;
	struct AdvTeacher *next;
} AdvTeacher;
//静态链表的使用
int main2000(int argc,char* argv[])
{
	AdvTeacher t1,t2,t3;
	struct AdvTeacher *p;
	t1.age=10;
	t2.age=20;
	t3.age=30;
	t1.next=&t2;
	t2.next=&t3;
	t3.next=NULL;
	//遍历链表准备场景
	p = &t1;
	while(p){
		printf("age:%d \n",p->age);
		p = p->next;
	}
	system("pause");
	return 1;
}
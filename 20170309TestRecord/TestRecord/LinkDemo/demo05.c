#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//链表保函各种业务数据但是做不到
typedef struct linkList{
	int age;
	char name[64];//业务数据
	struct linkList *next;
} linkList;

typedef struct AdvLinkList{
	struct linkList *next;
} AdvLinkList;

//业务数据包含链表
struct AdvTeacher{
	char name[32];
	int age;
	char *p;
	AdvLinkList *node;
};
//结构体的偏移问题
int main500423231(int argc,char* argv[])
{
	int i=0;
	struct AdvTeacher *p = NULL;
	struct AdvTeacher t1;

	p = &t1;
	printf("age:%d\n",p->age);

	p = p+1;
	p = p -1;
	p = p -p;
	i = (int ) (&(p->age));
	printf("i:%d\n",i);
	system("pause");
	return 1;
}

int main555555555(int argc,char* argv[])
{
	int i=0;
	//对0这个空间做地址转换
	//只是把地址空间做了一个类型转换
	((struct AdvTeacher *) 0);
	// -> 只不过是个寻址操作就是计算age的地址在哪里，没有向age所在的内存空间读写数据
	//寻址操作只是cpu的+ -运算
	//各个元素相对于 0 偏移了多少
	//结构体中各个变量相对于结构体便宜了多少
	i = (int )&(((struct AdvTeacher *) 0)->age);
	printf("i:%d\n",i);
	system("pause");
	return 1;
}
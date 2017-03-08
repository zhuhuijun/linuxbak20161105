#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/************************************************************************/
/* 结构体的基础知识
*1.自己定义一个数据类型，数据类型是固定大小内存块的别名
*2.结构体类型定义变量的时候,c和c++编译器的处理是不一样的
*3.结构体类型typedef 
*4.结构体变量4字节内存变量存放/
/************************************************************************/
typedef struct TeacherBak{
	char name[64];//64
	int age;//4
	char c1;//4
	char c2;//4
} TeacherBak;
//结构体定义变量的3种方法
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
int main00001(int arg,char *args[]){
	struct Teacher t1={"fffff",6};
	struct Teacher t2={"ddddd",23};
	struct Teacher *p=NULL;
	t2=t1;//这个是=号操作不是初始化//浅的copy,如果有指针的话只会copy地址,不会新开辟空间
	//释放两次时会down掉

	p=&t1;
	printf("sizeof(t1):%d\n",sizeof(t1));
	printf("p->name:%s\n",p->name);
	system("pause");
	return 1;
}
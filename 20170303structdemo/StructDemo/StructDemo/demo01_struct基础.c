#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//自定义一个数据类型  数据类型的本质是固定大小内存块的别名
//c++和c 结构体在定义结构体类型的变量时，编译器的处理是不一样的

struct Teacher{
	char name[64];//顺序不一样内存大小不一样,按照内存变量的大小存放的可能会多出几个字节
	int age;
	char title[128];
};


typedef struct Teacher1{
	char name[64];
	int age;
	char title[128];
} Teacher1;
//定义变量的几种方式，下面的两种可以忘掉
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
	struct Teacher t1={"zhuhj",34};//告诉编译器分配内存
	Teacher1 t2;
	struct Teacher *p2=NULL;
	p2=&t1;
	printf("name:%s\n",p2->name);
	printf("sizeof(t2):%d\n",sizeof(t2));
	system("pause");
}
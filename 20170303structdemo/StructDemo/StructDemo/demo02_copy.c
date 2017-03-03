#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//自定义一个数据类型  数据类型的本质是固定大小内存块的别名
//c++和c 结构体在定义结构体类型的变量时，编译器的处理是不一样的

struct TeacherBak{
	char name[64];//顺序不一样内存大小不一样,按照内存变量的大小存放的可能会多出几个字节
	int age;
};
/************************************************************************/
/* 第一种不使用指针的方式(结构体做函数参数时会退化成什么？)                                                                     */
/************************************************************************/
int copy01(struct TeacherBak from,struct TeacherBak to){
	memcpy(&to,&from,sizeof(struct TeacherBak));
	return 1;
}
int copy02(struct TeacherBak *from,struct TeacherBak *to){
	memcpy(to,from,sizeof(struct TeacherBak));
	return 1;
}
int main(int argc,char* args[]){
	struct TeacherBak t1={"t1",34};
	struct TeacherBak t2;
	struct TeacherBak t3={"t3",34};
	//结构体类型是复杂类型,结构体一出来就是一级指针
	struct TeacherBak *p=NULL;
	t2=t1;//这是"="操作不是初始化
	p=&t1;
	printf("t2.name:%s\n",t2.name);
	printf("p->name:%s\n",p->name);
	//使用memcpy完成两个结构体的copy
	memcpy(&t2,&t1,sizeof(struct TeacherBak));
	printf("t2.name:%s\n",t2.name);
	printf("p->name:%s\n",p->name);
	//结构体copy的自己定义赋值的方式
	copy01(t1,t3);//编译器行为将t1 copy 给from 
	//将 t3 copy 给 to 在copy01中将from copy给to
	//和t3 没关系//机械的修改形参和实参没有任何关系
	printf("copy01 after t3.name:%s\n",t3.name);
	copy02(&t1,&t3);//修改了实参所指的内存空间
	printf("copy02 after t3.name:%s\n",t3.name);
	system("pause");
}
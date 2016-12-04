#include "iostream"
using namespace std;
class Parent01{
public:
	Parent01(){
		cout<<"Parent01:printf()..do"<<endl;
	}
public:
	void func(){
		cout<<"Parent01:void func()"<<endl;
	}
	virtual void func(int i){
		cout<<"Parent01:void func(int i)"<<endl;
	}
	virtual void func(int i,int j){
		cout<<"Parent01:void func(int i,int j)"<<endl;
	}
};
class Child01:public Parent01{
public:
	//函数的重写
	//此处2个参数和子类的func函数是什么关系
	void func(int i,int j){
		cout<<"child01 void func(int i,int j)"<<endl;
	}
	//此处的三个参数的函数和子类func的关系
	void func(int i,int j,int k){
		cout<<"Child01:func(int i,int j,int k)"<<endl;
	}
};
void run01(Parent01 *p){
	p->func(1,2);
}
void main07(int argc,char *argv[])
{
	Parent01 p;
	Child01 c1;
	//p.func();
	//p.func(1);
	//p.func(1,2);
	c1.func(4,5);
	//c1.func();
	c1.Parent01::func();//这样调用父类的方法
	c1.func(3,4,5);
	run01(&p);
	run01(&c1);
	cout<<"hello,world!"<<endl;
	system("pause");
}
//1.子类的func无法重载父类的func
//2.当父类和子类有共同的函数名出现发生名称覆盖
//3.函数重载必须在一个类中进行
//4.如果父类中有virtual关键字,这种父子之间的关系叫做虚函数重写这种情况下发生迟绑定
//如果父类中没有virtual关键字,这种父子之间的关系冲定义叫做静态链编
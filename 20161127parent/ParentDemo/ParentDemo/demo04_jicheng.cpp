#include "iostream"
using namespace std;
/*1.方法是写在了子类的内部还是外部,2.这个类从父类的继承方式是public protected private 3.看父类中的访问级别*/
class A{
private:
	int a;
protected:
	int b;
public: 
	int c;
	A(){
		a=0;
		b=0;
		c=0;

	}
	void set(int a,int b,int c)
	{
		this->a=a;
		this->b=b;
		this->c=c;
	}
public:
	void print(){
		cout<<"b="<<b<<endl;
		cout<<"c="<<c<<endl;

	}
};
class B:public A{
public:
	void add()
	{
		b++;
	}
};
void howtoCall(A *pa)
{
	pa->print();
}
//子类是特殊的父类,赋值兼容性原则
void main04()
{
	A aa;
	B bb;
	aa.print();
	bb.print();
	cout<<"hello,world!"<<endl;
	//定义了父类
	A *pA=NULL;
	pA =&bb;
	
	pA->print();

	//
	bb.add();
	A &myb=bb;
	myb.print();


	howtoCall(&aa);
	howtoCall(&bb);
	system("pause");
}

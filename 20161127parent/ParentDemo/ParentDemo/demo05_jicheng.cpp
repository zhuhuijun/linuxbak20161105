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
	int c;
};
void main05()
{
	B d;
	d.c=5;
	d.A::c=6;
	d.print();
	system("pause");
}

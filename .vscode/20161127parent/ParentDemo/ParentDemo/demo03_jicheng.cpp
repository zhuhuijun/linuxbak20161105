#include "iostream"
using namespace std;
/*1.方法是写在了子类的内部还是外部,2.这个类从父类的继承方式是public protected private 3.看父类中的访问级别*/
class A{
private:
	int a;
	friend void setAA(A *a,int m_b);
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
};
class B:public A{
public:
	void print(){
		cout<<"b="<<b<<endl;
		cout<<"c="<<c<<endl;

	}
};
void setAA(A *a,int m_b)
{

	printf("ddddd\n");
	return ;
}

void main03()
{
	A aa;
	B bb;
	setAA(&aa,1);
	//子类是特殊的父类
	setAA(&bb,2);
	cout<<"hello,world!"<<endl;
	system("pause");
}

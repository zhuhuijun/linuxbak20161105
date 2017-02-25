#include <iostream>
using namespace std;
class ParentO{
public: 
	int a;
protected:
	int b;
private:
	int c;
public:
	ParentO(int a=0, int b=0,int c=0)
	{
		this->a=a;
		this->b=b;
		this->c=c;
	}
	void MyPrint(){
		cout<<"i am dad"<<endl;
	}
};

class ChildO:public ParentO
{
public:
	int getB(){
		return b;
	}
private:
protected:
};
/*1.方法是写在了子类的内部还是外部,2.这个类从父类的继承方式是public protected private 3.看父类中的访问级别*/
void main02()
{
	cout<<"hello,world!"<<endl;
	ParentO p1;
	p1.MyPrint();
	ChildO o1;
	o1.MyPrint();
	int bb = o1.getB();
	cout<<bb<<endl;
	system("pause");
}
#include <iostream>
using namespace  std;
class A{
public:
	A(){
		cout<<&c<<endl;
	} 
	void mm()
	{
		cout<<&(A::c)<<endl;
	}
	int a;
	static int c;
protected:
	int b;
};
//����c++���������ҿ����ڴ�
int A::c=100;
class B:public A
{
public:
	B(){
		//cout<<&c;
	}
	static int c;
	int a;
protected:
	int b;
};


void main0202(){
	B b;
	system("pause");
}
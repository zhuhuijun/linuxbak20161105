#include "iostream"
using namespace std;
/*1.������д����������ڲ������ⲿ,2.�����Ӹ���ļ̳з�ʽ��public protected private 3.�������еķ��ʼ���*/
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

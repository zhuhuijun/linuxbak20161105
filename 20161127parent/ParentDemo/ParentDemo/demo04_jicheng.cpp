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
//����������ĸ���,��ֵ������ԭ��
void main04()
{
	A aa;
	B bb;
	aa.print();
	bb.print();
	cout<<"hello,world!"<<endl;
	//�����˸���
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

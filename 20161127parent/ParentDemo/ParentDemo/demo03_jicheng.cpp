#include "iostream"
using namespace std;
/*1.������д����������ڲ������ⲿ,2.�����Ӹ���ļ̳з�ʽ��public protected private 3.�������еķ��ʼ���*/
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
	//����������ĸ���
	setAA(&bb,2);
	cout<<"hello,world!"<<endl;
	system("pause");
}

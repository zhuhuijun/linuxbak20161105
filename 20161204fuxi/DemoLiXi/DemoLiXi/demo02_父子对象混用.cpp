#include "iostream"
using namespace std;
class parent01{
public:
	virtual void f(){
		cout<<"parent01()...do"<<endl;
	}
protected:
	int i;
	int j;
};
class child:public parent01{
public:
	child(int i,int j){
		cout<<"child()...do"<<endl;
	}
	virtual void f(){
		cout<<"child::f()"<<endl;
	}
public:
	//int k;//�������������һ��
};
void howtoCall(parent01 *pbase){
	pbase->f();
}
void main02(int argc,char *argv[])
{
	cout<<"hello,world"<<endl;
	int i=0;
	parent01 *p=NULL;
	child* c=NULL;
	//��Ҫ�Ѹ��������������ͬʱ����һ��������
	child ca[3]={child(1,2),child(3,4),child(5,6)};
	p=ca;
	c=ca;
	p->f();
	c->f();
	p++;
	c++;
	p->f();
	c->f();
	for(i=0;i<3;i++){
		howtoCall(&(ca[i]));
	}
	system("pause");
}
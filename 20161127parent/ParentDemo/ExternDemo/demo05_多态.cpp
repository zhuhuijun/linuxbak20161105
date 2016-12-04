#include "iostream"
using namespace std;
class parent{
public:
	parent(){
		a=100;
	}
	virtual void print(){
		cout<<"parent()>>>>>a="<<a<<endl;
	}
protected:
private:
	int a;
};
class children:public parent{
public:
	children(int b=0)
	{
		this->b=b;
	}
	void print(){
		cout<<"children()>>>>>>>b="<<b<<endl;
	}
protected:
private:
	int b;
};
void howtoprint(parent *base){
	base->print();//多态就是通过同样的函数实现多种功能,使用关键词virtual
}
void main05(int argc,char *argv[]){
	parent p1;
	//p1.print();
	children c1;
	//c1.print();
	parent *base=NULL;
	base=&c1;
	//base->print();
	howtoprint(&p1);
	howtoprint(&c1);
	cout<<"hello,world!"<<endl;
	system("pause");
}
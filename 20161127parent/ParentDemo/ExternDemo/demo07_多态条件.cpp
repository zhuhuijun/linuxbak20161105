#include "iostream"
using namespace std;
class AA{
public:
	AA(int a=0){
		this->a=a;
	}
	virtual	void print(){
		cout<<"a="<<a<<endl;
	}
protected:
	int a;
};
class BB:public AA{
public:
	BB(int a=0,int b=0){
		this->a=a;
		this->b=b;
	}
	virtual	void print(){
		cout<<"a="<<a<<",b="<<b<<endl;
	}
protected:
	int b;
};
void howtoCall(AA *base){
	base->print();
}
void main07(int argc,char *argv[]){
	AA a1;
	BB b1;
	howtoCall(&a1);
	howtoCall(&b1);
	cout<<"hello,world!"<<endl;
	system("pause");
}
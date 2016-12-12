#include "iostream"
using namespace std;
class AA{
public:
	AA(int a=0){
		this->a=a;
	}
	virtual void print(){
		cout<<"AA()------a="<<a<<endl;
	}
protected:
	int a;
};
//当指向父类的构造函数时编译器会初始化子类的vptr指针
//让vptr指针指向父类的虚函数
//当父类的构造函数执行完毕之后再执行子类的构造函数
//这个时候让eptr指针真正的指向子类的虚函数表
class BB:public AA{
public:
	BB(int b=0){
		this->b=b;
	}
	virtual void print(){
		cout<<"BB()------b="<<b<<endl;
	}
protected:
	int b;
};

void run(AA *pbase){
	pbase->print();
}
int main01(int argc,char *argv){
	AA aa;
	BB bb;
	run(&aa);
	run(&bb);
	cout<<"hello,world!"<<endl;
	system("pause");
	return 0;
}
#include "iostream"
using namespace std;
//在派生类中使用静态变量
class B
{
public:
	static int i;
	static void add(){i++;}
	void out(){cout<<"static i="<<i<<endl;}
};

int B::i=0;

class D:private B{
public:
	void f(){
		i=5;
		add();
		B::i++;
		B::add();
	}
};

void main06(){
	B x;
	D y;
	x.add();
	x.out();
	y.f();
	cout<<"static i="<<B::i<<endl;
	cout<<"static i="<<x.i<<endl;
	system("pause");
}
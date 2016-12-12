#include "iostream"
using namespace std;
class interface1{
public:
	virtual int add(int i,int j)=0;
	virtual void print()=0;
};
class interface2{
	virtual int add(int i,int j)=0;
	virtual int  minus(int i,int j)=0;
};
class parent02{
public:
};
class child:public parent02,public interface2,public interface1{
public:
	void print(){
		cout<<"child:print()"<<endl;
	}
	int add(int i,int j){
		return i+j;
	}
	int minus(int i,int j){
		return i-j;
	}
};
//c++使用纯虚函数事项接口
int main(int argc,char*argv[]){
	cout<<"hello,world!"<<endl;
	child c;
	c.print();
	cout<<c.add(4,5)<<endl;
	cout<<c.minus(5,3)<<endl;
	interface1* inter1=&c;
	interface1* i2=&c;
	cout<<inter1->add(5,6)<<endl;
	cout<<i2->add(4,5)<<endl;
	system("pause");
	return 1;
}
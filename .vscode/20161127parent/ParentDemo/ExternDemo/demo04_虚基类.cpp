#include "iostream"
using namespace std;
class base{
public:
	int k;
	void printk(){
		cout<<"k="<<k<<endl;
	}
};
class base1:virtual public base{
public:
	int i;
protected:
private:
};
class base2:virtual public base{
public:
	int j;
	void printj()
	{
		cout<<j<<endl;
	}
};
class child:public base1,public base2
{
public:
};
//多继承的二义性使用关键词virtual解决
int main04(int argc,char *argv[])
{
	child c1;
	c1.k=300;//访问不明确
	c1.i=100;
	c1.j=200;
	c1.printj();
	cout<<"hello,world!"<<endl;
	system("pause");
	return 0;
}
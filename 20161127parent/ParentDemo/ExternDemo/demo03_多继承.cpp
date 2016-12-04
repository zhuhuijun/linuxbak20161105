#include "iostream"
using namespace std;
class base1{
public:
	int i;
protected:
private:
};
class base2{
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
int main03(int argc,char *argv[])
{
	child c1;
	c1.i=100;
	c1.j=200;
	c1.printj();
	cout<<"hello,world!"<<endl;
	system("pause");
	return 0;
}
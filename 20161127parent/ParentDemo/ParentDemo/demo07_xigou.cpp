#include "iostream"
using namespace std;

class Parent04{
public:
	Parent04(const char *s){
		cout<<"Parent04()"<<s<< " "<<endl;
	}
	~Parent04()
	{
		cout<<"~Parent04()"<<" "<<endl;
	}
};
class Child04:public Parent04
{
public:
	//子类初始化父类
	Child04():Parent04("Parameter from child!"){
		cout<<"child04()"<< " "<<endl;
	}
	~Child04()
	{
		cout<<"~Child04()"<<" "<<endl;
	}
};

void run04(){
	Child04 child;
}

int main(int argc,char *argv[])
{
	run04();
	system("pause");
	return 0;

}
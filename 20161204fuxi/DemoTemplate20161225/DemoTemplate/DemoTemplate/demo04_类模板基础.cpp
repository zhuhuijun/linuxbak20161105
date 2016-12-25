#include "iostream"
using namespace std;
//定义类的模板
template<typename T>
class AA{
public:
	AA(T a)
	{
		this->a=a;
	}
	void setA(T a)
	{
		this->a=a;
	}
	T getA(){
		return this->a;
	}
private:
	T a;
protected:
};
//class BB
class BB:public AA<int>
{
public:
	BB(int a,int b):AA<int>(a)
	{
		this->b=b;
	}
private:
	int b;
};
void main04(int argc,char *argv[])
{
	//要把类模板具体成类型后才定义变量
	AA<int> a(34);
	cout<<"hello,world!"<<endl;
	BB b(5,6);
	system("pause");
}
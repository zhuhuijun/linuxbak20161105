#include "iostream"
using namespace std;
//�������ģ��
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
	//Ҫ����ģ���������ͺ�Ŷ������
	AA<int> a(34);
	cout<<"hello,world!"<<endl;
	BB b(5,6);
	system("pause");
}
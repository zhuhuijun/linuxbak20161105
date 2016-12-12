#include "iostream"
using namespace std;
class AA
{
public:
	AA(int a= 0)
	{
		this->a = a;
		print(); //在构造函数里面能实现多态吗？
	}
	virtual ~AA()
	{
		cout<<"父类析构函数do"<<endl;
	}

	//分析一下要想实现多态，c++编译器应该动什么手脚
	//第一个需要动手脚的地方  起码这个函数print 我应该特殊处理
	virtual void print()
	{
		cout<<"父类的"<<"a"<<a<<endl;
	}

protected:
	int a ;
};

class BB : public AA
{
public:
	BB(int a= 0, int b = 0)
	{
		this->a = a;
		this->b = b;

	}

	~BB()
	{
		cout<<"子类析构函数do"<<endl;
	}
	virtual void print()
	{
		cout<<"子类的"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};
//通过父类指针释放所有的子类的析构函数那么需要在父类的析构函数前面加上virtual
void howToDelete(AA *pBase)
{
	//把子类的对象给父类时如果父类的析构函数不是virtual时，子类的析构函数就不能执行
	delete pBase;
}
void main03()
{
	BB *b1 = new BB(1, 2);

	b1->print();

	howToDelete(b1);
	//delete b1;
	system("pause");
}
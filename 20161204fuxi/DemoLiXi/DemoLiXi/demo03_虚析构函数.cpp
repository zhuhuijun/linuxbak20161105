#include "iostream"
using namespace std;
class AA
{
public:
	AA(int a= 0)
	{
		this->a = a;
		print(); //�ڹ��캯��������ʵ�ֶ�̬��
	}
	virtual ~AA()
	{
		cout<<"������������do"<<endl;
	}

	//����һ��Ҫ��ʵ�ֶ�̬��c++������Ӧ�ö�ʲô�ֽ�
	//��һ����Ҫ���ֽŵĵط�  �����������print ��Ӧ�����⴦��
	virtual void print()
	{
		cout<<"�����"<<"a"<<a<<endl;
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
		cout<<"������������do"<<endl;
	}
	virtual void print()
	{
		cout<<"�����"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};
//ͨ������ָ���ͷ����е����������������ô��Ҫ�ڸ������������ǰ�����virtual
void howToDelete(AA *pBase)
{
	//������Ķ��������ʱ��������������������virtualʱ����������������Ͳ���ִ��
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
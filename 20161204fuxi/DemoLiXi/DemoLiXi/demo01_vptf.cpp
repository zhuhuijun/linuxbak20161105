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
//��ָ����Ĺ��캯��ʱ���������ʼ�������vptrָ��
//��vptrָ��ָ������麯��
//������Ĺ��캯��ִ�����֮����ִ������Ĺ��캯��
//���ʱ����eptrָ��������ָ��������麯����
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
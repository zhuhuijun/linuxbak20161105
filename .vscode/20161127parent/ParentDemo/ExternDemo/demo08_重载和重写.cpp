#include "iostream"
using namespace std;
class Parent01{
public:
	Parent01(){
		cout<<"Parent01:printf()..do"<<endl;
	}
public:
	void func(){
		cout<<"Parent01:void func()"<<endl;
	}
	virtual void func(int i){
		cout<<"Parent01:void func(int i)"<<endl;
	}
	virtual void func(int i,int j){
		cout<<"Parent01:void func(int i,int j)"<<endl;
	}
};
class Child01:public Parent01{
public:
	//��������д
	//�˴�2�������������func������ʲô��ϵ
	void func(int i,int j){
		cout<<"child01 void func(int i,int j)"<<endl;
	}
	//�˴������������ĺ���������func�Ĺ�ϵ
	void func(int i,int j,int k){
		cout<<"Child01:func(int i,int j,int k)"<<endl;
	}
};
void run01(Parent01 *p){
	p->func(1,2);
}
void main07(int argc,char *argv[])
{
	Parent01 p;
	Child01 c1;
	//p.func();
	//p.func(1);
	//p.func(1,2);
	c1.func(4,5);
	//c1.func();
	c1.Parent01::func();//�������ø���ķ���
	c1.func(3,4,5);
	run01(&p);
	run01(&c1);
	cout<<"hello,world!"<<endl;
	system("pause");
}
//1.�����func�޷����ظ����func
//2.������������й�ͬ�ĺ��������ַ������Ƹ���
//3.�������ر�����һ�����н���
//4.�����������virtual�ؼ���,���ָ���֮��Ĺ�ϵ�����麯����д��������·����ٰ�
//���������û��virtual�ؼ���,���ָ���֮��Ĺ�ϵ�嶨�������̬����
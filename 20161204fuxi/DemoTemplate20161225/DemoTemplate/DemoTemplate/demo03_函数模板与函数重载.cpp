/*
	1.?����ģ���������ͨ����һ��������
	2.c++���������ȿ�����ͨ����
	3.�������ģ����Բ���һ�����õ�ƥ�䣬��ôѡ��ģ��
	4.����ͨ����ģ��ʵ���б���﷨�޶�������ֻͨ��ģ��ƥ��
*/
/*
	1.����ģ�岻�����Զ�ת������
	2.��ͨ�����ܹ�ʵ�������Զ�ת��
*/
#include "iostream"
using namespace std;
//��ͨ����
int Max(int a,int b){
	cout<<"int Max(int a,int b)"<<endl;
	return a>b?a:b;
}
//����ģ��
template <typename T>
T Max(T a,T b){
	cout<<"T Max(T a,T b)"<<endl;
	return a>b?a:b;
}
//�����˺���ģ�������
template <typename T>
T Max(T a,T b,T c){
	cout<<"T Max(T a,T b,T c)"<<endl;
	return Max(Max(a,b),c);
}
void main03(int argc,char *argv[])
{
	int a=2;
	int b=3;
	int c=0;
	//����2
	c =Max(a,b);
	cout<<"c="<<c<<endl;
	cout<<Max(3.4,5.6)<<endl;
	cout<<Max(3.4,5.6,9.0)<<endl;
	system("pause");
}
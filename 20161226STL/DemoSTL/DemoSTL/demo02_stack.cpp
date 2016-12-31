#include "iostream"
#include "stack"
using namespace std;
typedef struct Teacher1
{
	int age;
	char name[10];
} Teacher1;
//��ӡ����
void printArrT(stack<Teacher1> &v)
{
	while(!v.empty())
	{
		//���ջ��Ԫ��
		Teacher1 tmp=v.top();
		//����Ԫ��
		v.pop();
		cout<<tmp.age<<endl;
	}
}
void printArr(stack<int> &v)
{
	while(!v.empty())
	{
		//���ջ��Ԫ��
		int tmp=v.top();
		//����Ԫ��
		v.pop();
		cout<<tmp<<endl;
	}
}

//������
void main02(int argc,char *argv[])
{
	cout<<"hello,world!"<<endl;
	stack<int> s;
	for(int j=0;j<5;j++)
	{
		s.push(j+10);
	}
	printArr(s);
	stack<Teacher1> tt;
	Teacher1 t1,t2,t3;
	t1.age=11;
	t2.age=22;
	t3.age=33;
	tt.push(t1);
	tt.push(t2);
	tt.push(t3);
	printArrT(tt);
	system("pause");
}
#include "iostream"
#include "vector"
using namespace std;
void printArr(vector<int> &v)
{
	int i=0;
	int vsize=v.size();
	for(i=0;i<vsize;i++)
	{
		cout<<v[i]<<endl;
	}
}
typedef struct Teacher
{
	int age;
	char name[10];
} Teacher;
void main01(int argc,char *argv[])
{
	cout<<"hello,world!"<<endl;
	vector<int> v1(5);
	for(int i=0;i<5;i++)
	{
		v1[i]=i*100;
	}
	printArr(v1);
	vector<int> v2(10);
	v2=v1;
	printArr(v2);
	//
	v2.resize(0);
	cout<<"v2 size="<<v2.size()<<endl;
	vector<int> v3(2);
	v3.push_back(6);//向后追加
	v3.push_back(5);
	printArr(v3);
	//结构体
	vector<Teacher> v4(0);
	Teacher t1,t2,t3;
	t1.age=11;
	t2.age=22;
	t3.age=33;
	v4.push_back(t1);
	v4.push_back(t2);
	v4.push_back(t3);
	for(int t=0;t<3;t++)
	{
		cout<<v4[t].age<<endl;
	}
	{
		vector<Teacher *> v5(0);
		Teacher t1,t2,t3;
		t1.age=11;
		t2.age=22;
		t3.age=33;
		v5.push_back(&t1);
		v5.push_back(&t2);
		v5.push_back(&t3);
		for(int t=0;t<3;t++)
		{
			struct Teacher *tmp=(struct Teacher *)v5[t];
			cout<<"指针"<<tmp->age<<endl;
		}

	}
	system("pause");
}


















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
void main(int argc,char *argv[])
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
	vector<int> v3(10);
	v3.push_back(6);
	v3.push_back(5);
	printArr(v3);
	system("pause");
}
/*
	1.?函数模板可以像普通函数一样被重载
	2.c++编译器优先考虑普通函数
	3.如果函数模板可以产生一个更好的匹配，那么选择模板
	4.可以通过空模板实参列表的语法限定编译器只通过模板匹配
*/
/*
	1.函数模板不允许自动转换类型
	2.普通函数能够实现类型自动转换
*/
#include "iostream"
using namespace std;
//普通函数
int Max(int a,int b){
	cout<<"int Max(int a,int b)"<<endl;
	return a>b?a:b;
}
//函数模板
template <typename T>
T Max(T a,T b){
	cout<<"T Max(T a,T b)"<<endl;
	return a>b?a:b;
}
//出现了函数模板的重载
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
	//规则2
	c =Max(a,b);
	cout<<"c="<<c<<endl;
	cout<<Max(3.4,5.6)<<endl;
	cout<<Max(3.4,5.6,9.0)<<endl;
	system("pause");
}
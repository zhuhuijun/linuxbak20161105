#include "iostream"
using namespace std;
void swap(int &a,int &b){
	int c;
	c=a;
	a=b;
	b=c;
}
void swap(float &a,float &b){
	float c;
	c=a;
	a=b;
	b=c;
}
//tempalte 关键字告诉c++编译器唤醒泛型编程
//typename 告诉编译器 这是泛型可以参数化，不要报错
template<typename T>
void swap2(T &a,T &b)
{
	T c;
	c=a;
	a=b;
	b=c;
}
void main01(int argc,char *argv[]){
	int a=1,b=2;
	float a1=1,b1=3;
	swap(a,b);
	printf("swap(int,int):a=%d,b=%d\n",a,b);
	{
		//泛型编程调用有两种方式
		//自动类型推导
		swap2(a,b);
		printf("swap2():a=%d,b=%d\n",a,b);
		//具体类型调用
		swap2<float>(a1,b1);
		printf("swap2():a=%f,b=%f\n",a1,b1);

	}
	system("pause");
}
#include "iostream"
using namespace std;
class figure{
protected: 
	double x;
	double y;
public:
	virtual void show_erea()=0;
};
class tri:public figure{
public:
	tri(double x=2, double y=3){
		this->x=x;
		this->y=y;
	}
	void show_erea(){
		cout<<"show erea="<<x*y*0.5<<endl;
	}

};
class square:public figure{
public:
	square(double x=1, double y=2){
		this->x=x;
		this->y=y;
	}
	void show_erea(){
		cout<<"show square="<<x*y<<endl;
	}
};
//通过抽象类 的纯虚函数 接口约定来实现业务的具体模型
void objPlay(figure *pbase){
	pbase->show_erea();
}
//如果子类继承抽象类只有把所有的纯虚函数实现了才能实例化
//在抽象类中可以定义普通函数
void main06(){
	//figure p;//不能用于创建对象
	figure *pbase=NULL;
	tri tr;
	square s;
	objPlay(&tr);
	objPlay(&s);
	system("pause");
}
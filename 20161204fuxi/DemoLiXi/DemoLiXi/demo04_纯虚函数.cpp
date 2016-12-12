#include "iostream"
using namespace std;
class point{};
class shape{
	point center;
public:
	point where(){
		return center;
	}
	void move(point pointp){
		center=pointp;
		draw();
	}
	virtual void rotate(int)=0;//纯虚函数
	virtual void draw()=0;//传虚函数
};
void main04(){
	//shape x;//抽象类不能建立对象
	shape *p;//可以声明抽象类指针
	//shape f()//抽象类不能作为返回类型
	//void g(shap);//抽象类不能作为参数
	//sahpe &h(shape &);//可以声明抽象类引用
	cout<<"hello,world!"<<endl;
	system( "pause");
}
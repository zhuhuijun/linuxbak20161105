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
//ͨ�������� �Ĵ��麯�� �ӿ�Լ����ʵ��ҵ��ľ���ģ��
void objPlay(figure *pbase){
	pbase->show_erea();
}
//�������̳г�����ֻ�а����еĴ��麯��ʵ���˲���ʵ����
//�ڳ������п��Զ�����ͨ����
void main06(){
	//figure p;//�������ڴ�������
	figure *pbase=NULL;
	tri tr;
	square s;
	objPlay(&tr);
	objPlay(&s);
	system("pause");
}
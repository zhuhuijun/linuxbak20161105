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
	virtual void rotate(int)=0;//���麯��
	virtual void draw()=0;//���麯��
};
void main04(){
	//shape x;//�����಻�ܽ�������
	shape *p;//��������������ָ��
	//shape f()//�����಻����Ϊ��������
	//void g(shap);//�����಻����Ϊ����
	//sahpe &h(shape &);//������������������
	cout<<"hello,world!"<<endl;
	system( "pause");
}
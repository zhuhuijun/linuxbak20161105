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
//tempalte �ؼ��ָ���c++���������ѷ��ͱ��
//typename ���߱����� ���Ƿ��Ϳ��Բ���������Ҫ����
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
		//���ͱ�̵��������ַ�ʽ
		//�Զ������Ƶ�
		swap2(a,b);
		printf("swap2():a=%d,b=%d\n",a,b);
		//�������͵���
		swap2<float>(a1,b1);
		printf("swap2():a=%f,b=%f\n",a1,b1);

	}
	system("pause");
}